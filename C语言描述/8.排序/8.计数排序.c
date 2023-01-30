#include "Sort.h"

void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);
	//统计次数
	for (int i = 0; i < n; i++)
	{
		count[a[i]-min]++;
	}
	int j = 0;
	for(int i; i < range; i++)
	{
		while (count[i]--)
		{
			a[j] = i + min;
			j++;
			//a[j++] = i + min;
		}
	}
	free(count);
}


void TestCountSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}