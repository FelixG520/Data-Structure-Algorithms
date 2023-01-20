#include "Sort.h"

//最简单的排序也是效率最差的排序(优化后的)
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
		//先找到一组最大值最小值，一直到循环结束
		Swap(&a[begin], &a[min]);
		//{ 9,3,5,2,7,8,6,-1,1,9,4,0 }这种情况begin和max重合，要对max进行修正
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