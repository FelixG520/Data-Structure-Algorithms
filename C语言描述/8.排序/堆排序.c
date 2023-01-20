#include "Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//���µ����㷨
void AdjustDown(int* a, int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ��������
	while (child < n)
	{
		//ѡ�����Һ����д����һ�� -- С����
		//if (child + 1 < n && a[child + 1] < a[child])//ֻ�����ӻ��Һ���<����
		if (child + 1 < n && a[child + 1] > a[child])//�����
		{
			child += 1;
		}
		if (a[child] > a[parent])//�����
		//if (a[child] < a[parent])//С����
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, int n)
{
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//�ҵ����׽��
	{
		//�����һ����Ҷ�ӵ�������ʼ����
		AdjustDown(a, n, i);
	}

	// �����򣬽���ѻ���С�ѣ������
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//���������������һ��λ��
		AdjustDown(a, end, 0);//ʣ�µ�������һ�������µ���
		--end;
	}
}