#include "Sort.h"


void ShellSort(int *a,int n)
{
	int gap = n;//就相当于插入排序，只是把1替换成了gap
	while (gap > 1)
	{
		//gap没有固定的取值，一般是除三或除二，但一定要保证最后一次gap是1
		gap = gap / 3 + 1;
		//gap /= 2;
		//把间隔为gap的多组数据同时排 
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				//end<0,比所有数都要小 -- 跳出循环处理
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}
