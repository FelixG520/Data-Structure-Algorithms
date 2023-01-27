#include "QuickSort.h"
void QuickSort3(int* a, int left, int right)//前后指针法
{
	if (left >= right)
		return;
	int key = left;
	int pre = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[key])
		{
			++pre;
			Swap(&a[pre], &a[cur]);
		}
		++cur;
	}
	Swap(&a[key], &a[pre]);
	//把[left,right]分成以下区间
	//[left,begin-1]  begin  [begin+1,right]
	//左子区间和右子区间有序，就有序 -- 分治递归
	QuickSort3(a, left, pre - 1);
	QuickSort3(a, pre + 1, right);
}


void TestQuickSort3()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	QuickSort3(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}