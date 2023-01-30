#include "Sort.h"



void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;//每组数据的个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//[i,i+gap-1][i+gap,i+2*gap-1]
			//归并
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// end1 越界，修正
			if (end1 >= n)
				end1 = n - 1;
			//归并过程右半区间可能不存在
			if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			// 归并过程右半区间算多了，begin2 ok， end2越界，修正end2即可
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
			while (begin1 <= end1)//begin1没结束把begin1拷贝过来
				tmp[index++] = a[begin1++];
			while (begin2 <= end2)//begin2没结束把begin2拷贝过来
				tmp[index++] = a[begin2++];
		}
		//把临时数组中的数拷贝回去
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