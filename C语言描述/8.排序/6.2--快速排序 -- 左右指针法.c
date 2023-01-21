#include "QuickSort.h"

//左右指针法
void QuickSort2(int* a, int left, int right)//快速排序
{
	//当划分的区间不存在或区间内只有一个数时说明有序，退出循环
	if (left >= right)
	{
		return;
	}
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

	//把[left,right]分成以下区间
	//[left,begin-1]  begin  [begin+1,right]
	//左子区间和右子区间有序，就有序 -- 分治递归
	QuickSort2(a, left, begin - 1);
	QuickSort2(a, begin + 1, right);
}

void TestQuickSort2()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	QuickSort2(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}