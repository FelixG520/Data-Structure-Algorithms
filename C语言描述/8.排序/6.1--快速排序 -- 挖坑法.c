#include "QuickSort.h"

//�ڿӷ�
void QuickSort(int* a, int left, int right)//��������
{
	//�����ֵ����䲻���ڻ�������ֻ��һ����ʱ˵�������˳�ѭ��
	if (left >= right)
	{
		return;
	}
	int begin = left, end = right;
	int pivot = begin;
	int key = a[begin];
	//��������
	while (begin < end )
	{
		//�ұ���С���ŵ����
		while (begin < end && a[end] >= key)
		//��Ҫ��һ���ж� begin < end
		{
			end--;
		}
		//С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;

		//����Ҵ󣬷ŵ��ұ�
		while (begin < end && a[begin]<=key)
		{
			begin++;
		}
		//��ķŵ��ұߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	//��[left,right]�ֳ���������
	//[left,pivot-1]  pivot  [pivot+1,right]
	//��������������������򣬾����� -- ���εݹ�
	QuickSort(a, left, pivot - 1);
	QuickSort(a, pivot + 1, right);
}





void TestQuickSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}