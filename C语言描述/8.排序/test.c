#include "QuickSort.h"

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

	//TestQuickSort();
	//TestQuickSort2();
	//TestQuickSort3();
	//TestQuickSort_Conformity();
	//TestQuickSort_optimize();
	//TestMergeSort();

	//TestQuickSortNonR();
	//TestMergeSortNonR();


	// 测试排序的性能对比
	TestOP();
	return 0;
}