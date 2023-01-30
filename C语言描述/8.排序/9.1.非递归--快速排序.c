#include "QuickSort.h"

//栈里面的区间要分割排序
void QuickSortNonR(int* a, int n)
{
	ST st;
	StackInit(&st);
	StackPush(&st, n - 1);
	StackPush(&st, 0);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);
		int keyIndex = PartSort_Trenching(a, left, right);//挖坑法
		//int keyIndex = PartSort_RLHands(a, left, right);//左右指针
		//int keyIndex = PartSort_FBHands(a, left, right);//前后指针

		//[left,keyIndex - 1],ketIndex,[ketIndex+1,right]
		if (keyIndex + 1 < right)//说明还有多个值，还没有序
		{
			//先入右，再入左
			StackPush(&st,right);
			StackPush(&st, keyIndex + 1);
		}
		if (left< keyIndex - 1)//说明还有多个值，还没有序
		{
			StackPush(&st, keyIndex - 1);
			StackPush(&st, left);
		}
	}

	STackDestory(&st);

}

void TestQuickSortNonR()
{
	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
	QuickSortNonR(a,  sizeof(a) / sizeof(int) );
	PrintArray(a, sizeof(a) / sizeof(int));
}