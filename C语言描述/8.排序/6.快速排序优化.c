#include "QuickSort.h"

//处理最坏情况的优化
//三数取中（左，右，中间）
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//右移一位相当于除2，(left + right) / 2;
	if (a[left] < a[mid])//顺序
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else//a[left] > a[mid] -- 逆序
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}


void QuickSort_Mid(int* a, int left, int right)//快速排序
{
	//当划分的区间不存在或区间内只有一个数时说明有序，退出循环
	if (left >= right)
	{
		return;
	}

	int begin = left, end = right;
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int pivot = begin;
	int key = a[begin];
	//单趟排序
	while (begin < end)
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
		while (begin < end && a[begin] <= key)
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


//小区间优化
void QuickSort_Mid_Minizone(int* a, int left, int right)//快速排序
{
	//当划分的区间不存在或区间内只有一个数时说明有序，退出循环
	if (left >= right)
		return;

	int begin = left, end = right;
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
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

	//把[left,right]分成以下区间
	//[left,pivot-1]  pivot  [pivot+1,right]
	//当子序列小于13个元素的时候就改用直接插入排序来对这些子序列进行排序
	if (pivot - 1 - left > 13)
		QuickSort_Mid_Minizone(a, left, pivot - 1);
	else
		InsertSort(a + left, pivot - 1 - left + 1);
	if (right - (pivot + 1) > 13)
		QuickSort_Mid_Minizone(a, pivot + 1, right);
	else
		InsertSort(a + pivot + 1, right - (pivot + 1) + 1);
}


void TestQuickSort_optimize()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	//QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	//QuickSort_Mid(a, 0, sizeof(a) / sizeof(int) - 1);
	QuickSort_Mid_Minizone(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}