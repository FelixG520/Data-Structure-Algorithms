#include "Sort.h"


//插入排序 -- 时间复杂度O(N^2)
void InsertSort(int* a, int n)
{
	//[0,end]有序，把[0,end+1]位置的值插入进去，让[0，end+1]也有序
	for (int i = 0; i < n - 1; i++)//注意n-1不是n
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)//升序
			//if (a[end] < tmp)降序
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				//a[end] >= tmp
				//end<0,比所有数都要小 -- 跳出循环处理
				break;
			}
		}
		a[end + 1] = tmp;
	}

}



void TestInsertSort()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}