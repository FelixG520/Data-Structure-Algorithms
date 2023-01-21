#include "QuickSort.h"

//����ָ�뷨
void QuickSort2(int* a, int left, int right)//��������
{
	//�����ֵ����䲻���ڻ�������ֻ��һ����ʱ˵�������˳�ѭ��
	if (left >= right)
	{
		return;
	}
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

	//��[left,right]�ֳ���������
	//[left,begin-1]  begin  [begin+1,right]
	//��������������������򣬾����� -- ���εݹ�
	QuickSort2(a, left, begin - 1);
	QuickSort2(a, begin + 1, right);
}

void TestQuickSort2()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	QuickSort2(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}