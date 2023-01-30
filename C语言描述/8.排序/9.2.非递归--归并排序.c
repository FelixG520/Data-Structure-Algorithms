#include "Sort.h"



void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;//ÿ�����ݵĸ���
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1][i+gap,i+2*gap-1]
			//�鲢
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// end1 Խ�磬����
			if (end1 >= n)
				end1 = n - 1;
			//�鲢�����Ұ�������ܲ�����
			if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			// �鲢�����Ұ���������ˣ�begin2 ok�� end2Խ�磬����end2����
			if (begin2 < n && end2 >= n)
				end2 = n - 1;

			int index = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}
			while (begin1 <= end1)//begin1û������begin1��������
				tmp[index++] = a[begin1++];
			while (begin2 <= end2)//begin2û������begin2��������
				tmp[index++] = a[begin2++];
		}
		//����ʱ�����е���������ȥ
		for (int j = 0; j < n; j++)
		{
			a[j] = tmp[j];
		}
		gap *= 2;
	}
	free(tmp);
}

void TestMergeSortNonR()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}