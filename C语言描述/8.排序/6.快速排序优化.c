#include "QuickSort.h"

//�����������Ż�
//����ȡ�У����ң��м䣩
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//����һλ�൱�ڳ�2��(left + right) / 2;
	if (a[left] < a[mid])//˳��
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
	else//a[left] > a[mid] -- ����
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


void QuickSort_Mid(int* a, int left, int right)//��������
{
	//�����ֵ����䲻���ڻ�������ֻ��һ����ʱ˵�������˳�ѭ��
	if (left >= right)
	{
		return;
	}

	int begin = left, end = right;
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int pivot = begin;
	int key = a[begin];
	//��������
	while (begin < end)
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
		while (begin < end && a[begin] <= key)
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


//С�����Ż�
void QuickSort_Mid_Minizone(int* a, int left, int right)//��������
{
	//�����ֵ����䲻���ڻ�������ֻ��һ����ʱ˵�������˳�ѭ��
	if (left >= right)
		return;

	int begin = left, end = right;
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);
	int pivot = begin;
	int key = a[begin];
	//��������
	while (begin < end)
	{
		//�ұ���С���ŵ����
		while (begin < end && a[end] >= key)
			//��Ҫ��һ���ж� begin < end
			end--;
		//С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;

		//����Ҵ󣬷ŵ��ұ�
		while (begin < end && a[begin] <= key)
			begin++;
		//��ķŵ��ұߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;
	}
	pivot = begin;
	a[pivot] = key;

	//��[left,right]�ֳ���������
	//[left,pivot-1]  pivot  [pivot+1,right]
	//��������С��13��Ԫ�ص�ʱ��͸���ֱ�Ӳ�������������Щ�����н�������
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