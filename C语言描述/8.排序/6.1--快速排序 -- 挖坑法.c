#include "QuickSort.h"

//挖坑法
void QuickSort(int* a, int left, int right)//快速排序
{
	//当划分的区间不存在或区间内只有一个数时说明有序，退出循环
	if (left >= right)
	{
		return;
	}
	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	//单趟排序
	while (begin < end )
	{
		//右边找小，放到左边
		while (begin < end && a[end] >= key)
		//还要再一次判断 begin < end
		{
			end--;
		}
		//小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		//左边找大，放到右边
		while (begin < end && a[begin]<=key)
		{
			begin++;
		}
		//大的放到右边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	//把[left,right]分成以下区间
	//[left,pivot-1]  pivot  [pivot+1,right]
	//左子区间和右子区间有序，就有序 -- 分治递归
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot + 1, right);
}





void TestQuickSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}