#include "Sort.h"

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//向下调整算法
void AdjustDown(int* a, int n,int root)
{
	int parent = root;
	int child = parent * 2 + 1;//默认是左孩子
	while (child < n)
	{
		//选出左右孩子中大的那一个 -- 小根堆
		//if (child + 1 < n && a[child + 1] < a[child])//只有左孩子或右孩子<左孩子
		if (child + 1 < n && a[child + 1] > a[child])//大根堆
		{
			child += 1;
		}
		if (a[child] > a[parent])//大根堆
		//if (a[child] < a[parent])//小根堆
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapSort(int* a, int n)
{
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//找到父亲结点
	{
		//从最后一个非叶子的子树开始建堆
		AdjustDown(a, n, i);
	}

	// 排升序，建大堆还是小堆？建大堆
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//把最大的数换到最后一个位置
		AdjustDown(a, end, 0);//剩下的数看成一个堆向下调整
		--end;
	}
}