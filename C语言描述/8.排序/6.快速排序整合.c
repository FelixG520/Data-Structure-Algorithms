#include "QuickSort.h"


//�ڿӷ�
int PartSort_Trenching(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
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
	return pivot;
}

//����ָ�뷨
int PartSort_RLHands(int* a, int left, int right)
{
	int begin = left, end = right;
	int key = a[begin];
	while (begin < end)
	{
		//��С
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		//�Ҵ�
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);//��С����
	}
	Swap(&a[begin], &a[key]);
	return begin;
}


void QuickSort_Conformity(int* a, int left, int right)//��������
{
	//�����ֵ����䲻���ڻ�������ֻ��һ����ʱ˵�������˳�ѭ��
	if (left >= right)
		return;

	int keyIndex = PartSort_Trenching(a, left, right);//�ڿӷ�
	//int keyIndex = PartSort_RLHands(a, left, right);//����ָ��


	//��[left,right]�ֳ���������
	//[left,keyIndex-1]  keyIndex  [keyIndex+1,right]
	//��������С��13��Ԫ�ص�ʱ��͸���ֱ�Ӳ�������������Щ�����н�������
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