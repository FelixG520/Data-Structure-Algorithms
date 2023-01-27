#include "Sort.h"

void _MergeSort(int* a, int left, int right,int* tmp)//归并排序子函数
{
	if (left >= right)
		return;//区间不存在
	int mid = (left + right) >> 1;//右移一位相当于除2
	//假设[left,mid][mid+1,right]有序，那么我们就可以归并
	//无序就递归
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	
	//归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)//begin1没结束把begin1拷贝过来
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)//begin2没结束把begin2拷贝过来
	{
		tmp[index++] = a[begin2++];
	}
	//把临时数组中的数拷贝回去
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)//归并排序
{
	int* tmp = (int*)malloc(sizeof(int) * n);//空间复杂度O(N)
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}


void TestMergeSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}