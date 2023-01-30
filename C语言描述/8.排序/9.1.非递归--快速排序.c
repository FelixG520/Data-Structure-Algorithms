#include "QuickSort.h"

//ջ���������Ҫ�ָ�����
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
		int keyIndex = PartSort_Trenching(a, left, right);//�ڿӷ�
		//int keyIndex = PartSort_RLHands(a, left, right);//����ָ��
		//int keyIndex = PartSort_FBHands(a, left, right);//ǰ��ָ��

		//[left,keyIndex - 1],ketIndex,[ketIndex+1,right]
		if (keyIndex + 1 < right)//˵�����ж��ֵ����û����
		{
			//�����ң�������
			StackPush(&st,right);
			StackPush(&st, keyIndex + 1);
		}
		if (left< keyIndex - 1)//˵�����ж��ֵ����û����
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