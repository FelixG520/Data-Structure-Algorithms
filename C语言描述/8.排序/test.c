#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}



int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestBubbleSort();
	TestQuickSort();


	// ������������ܶԱ�
	//TestOP();
	return 0;
}