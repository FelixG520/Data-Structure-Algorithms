#include "Sort.h"

void _MergeSort(int* a, int left, int right,int* tmp)//�鲢�����Ӻ���
{
	if (left >= right)
		return;//���䲻����
	int mid = (left + right) >> 1;//����һλ�൱�ڳ�2
	//����[left,mid][mid+1,right]������ô���ǾͿ��Թ鲢
	//����͵ݹ�
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);
	
	//�鲢
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
	while (begin1 <= end1)//begin1û������begin1��������
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)//begin2û������begin2��������
	{
		tmp[index++] = a[begin2++];
	}
	//����ʱ�����е���������ȥ
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)//�鲢����
{
	int* tmp = (int*)malloc(sizeof(int) * n);//�ռ临�Ӷ�O(N)
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}


void TestMergeSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}