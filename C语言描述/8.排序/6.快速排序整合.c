#include "QuickSort.h"


//挖坑法
int PartSort_Trenching(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	//单趟排序
	while (begin < end)
	{
		//右边找小，放到左边
		while (begin < end && a[end] >= key)
			//还要再一次判断 begin < end
			end--;
		//小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大，放到右边
		while (begin < end && a[begin] <= key)
			begin++;
		//大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;
	return pivot;
}

//左右指针法
int PartSort_RLHands(int* a, int left, int right)
{
	int begin = left, end = right;
	int key = a[begin];
	while (begin < end)
	{
		//找小
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		//找大
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);//大小交换
	}
	Swap(&a[begin], &a[key]);
	return begin;
}


void QuickSort_Conformity(int* a, int left, int right)//快速排序
{
	//当划分的区间不存在或区间内只有一个数时说明有序，退出循环
	if (left >= right)
		return;

	int keyIndex = PartSort_Trenching(a, left, right);//挖坑法
	//int keyIndex = PartSort_RLHands(a, left, right);//左右指针


	//把[left,right]分成以下区间
	//[left,keyIndex-1]  keyIndex  [keyIndex+1,right]
	//当子序列小于13个元素的时候就改用直接插入排序来对这些子序列进行排序
	if (keyIndex - 1 - left > 13)
		QuickSort_Conformity(a, left, keyIndex - 1);
	else
		InsertSort(a + left, keyIndex - 1 - left + 1);
	if (right - (keyIndex + 1) > 13)
		QuickSort_Conformity(a, keyIndex + 1, right);
	else
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
}



void TestQuickSort_Conformity()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	QuickSort_Conformity(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}