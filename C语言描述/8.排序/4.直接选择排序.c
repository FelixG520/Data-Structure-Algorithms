#include "Sort.h"

//��򵥵�����Ҳ��Ч����������(�Ż����)
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		//���ҵ�һ�����ֵ��Сֵ��һֱ��ѭ������
		Swap(&a[begin], &a[min]);
		//{ 9,3,5,2,7,8,6,-1,1,9,4,0 }�������begin��max�غϣ�Ҫ��max��������
		//{ -1,3,5,2,7,8,6,9,1,9,4,0 }
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}

}