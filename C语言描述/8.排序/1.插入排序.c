#include "Sort.h"


//�������� -- ʱ�临�Ӷ�O(N^2)
void InsertSort(int* a, int n)
{
	//[0,end]���򣬰�[0,end+1]λ�õ�ֵ�����ȥ����[0��end+1]Ҳ����
	for (int i = 0; i < n - 1; i++)//ע��n-1����n
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)//����
			//if (a[end] < tmp)����
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				//a[end] >= tmp
				//end<0,����������ҪС -- ����ѭ������
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