#include "Sort.h"


void ShellSort(int *a,int n)
{
	int gap = n;//���൱�ڲ�������ֻ�ǰ�1�滻����gap
	while (gap > 1)
	{
		//gapû�й̶���ȡֵ��һ���ǳ������������һ��Ҫ��֤���һ��gap��1
		gap = gap / 3 + 1;
		//gap /= 2;
		//�Ѽ��Ϊgap�Ķ�������ͬʱ�� 
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
				//end<0,����������ҪС -- ����ѭ������
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}
