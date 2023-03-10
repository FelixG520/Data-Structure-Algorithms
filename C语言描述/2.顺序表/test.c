#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void TestSeqList1()
{
	SL s1;
	SeaListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);


	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);


	SeqListDestory(&s1);

}


void TestSeqList2()
{
	SL s1;
	SeaListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);


	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPushFront(&s1, 50);
	SeqListPushFront(&s1, 60);
	SeqListPopFront(&s1);
	SeqListPopFront(&s1);

	SeqListPopFront(&s1);

	SeqListPrint(&s1);

	SeqListDestory(&s1);

}
void TestSeqList3()
{
	SL s1;
	SeaListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);


	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPushFront(&s1, 50);
	SeqListPushFront(&s1, 60);

	SeqListInsert(&s1, 1, 30);
	SeqListInsert(&s1, 0, -1);
	SeqListInsert(&s1, 13, 14);

	SeqListPrint(&s1);

	int pos = SeqListFind(&s1, 4);
	if (pos != -1)
	{
		SeqListInsert(&s1, pos, 40);
	}


	SeqListPrint(&s1);
	SeqListDestory(&s1);

}
void TestSeqList4()
{
	SL s1;
	SeaListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);


	SeqListPushFront(&s1, 10);
	SeqListPushFront(&s1, 20);
	SeqListPushFront(&s1, 30);
	SeqListPushFront(&s1, 40);
	SeqListPushFront(&s1, 50);
	SeqListPushFront(&s1, 60);

	SeqListPushFront2(&s1, 100);
	SeqListPushFront2(&s1, 101);
	SeqListPushBack2(&s1, 103);
	SeqListPushBack2(&s1, 104);
	SeqListErase(&s1, 0);
	SeqListPopBack2(&s1);
		
	int pos = SeqListFind(&s1, 5);
	if (pos != -1)
	{
		SeqListErase(&s1, pos);
	}

	SeqListPrint(&s1);
	SeqListDestory(&s1);

}
void menu()
{
	printf("********************************************\n");
	printf("******** 1.????            2.????    *******\n");
	printf("******** 3.????            4.????    *******\n");
	printf("******** 5.????2           6.????2   *******\n");
	printf("******** 7.????2           8.????2   *******\n");
	printf("******** 9.????            10.????   *******\n");
	printf("******** 11.????           12.????   *******\n");
	printf("******** 0.????                      *******\n");
	printf("********************************************\n");

}

int main()
{
	int input = 0;
	//??????
	SL s1;
	SeaListInit(&s1);
	//
	do
	{
		menu();
		printf("????????");
		int x;
		int pos;
		scanf("%d", &input);
		switch (input)
		{
		case SLPushFront:
			printf("????????????????????????-1??????");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushFront(&s1, x);
				scanf("%d", &x);
			}
			break;
		case SLPushBack:
			printf("????????????????????????-1??????");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushBack(&s1, x);
				scanf("%d", &x);
			}
			break;
		case SLPopFront:
			SeqListPopFront(&s1);
			printf("??????????\n");
			SeqListPrint(&s1);
			break;
		case SLPopBack:
			SeqListPopBack(&s1);
			printf("??????????\n");
			SeqListPrint(&s1);
			break;
		case SLPushFront2:
			printf("????????????????????????-1??????");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushFront2(&s1, x);
				scanf("%d", &x);
			}
			break;
		case SLPushBack2:
			printf("????????????????????????-1??????");
			scanf("%d", &x);
			while (x != -1)
			{
				SeqListPushBack2(&s1, x);
				scanf("%d", &x);
			}
			break;
		case SLPopFront2:
			SeqListPopFront2(&s1);
			printf("??????????");
			SeqListPrint(&s1);
			break;
		case SLPopBack2:
			SeqListPopBack2(&s1);
			break;
		case SLInsert:
			printf("??????????????????????");
			scanf("%d", &x);
			printf("??????????????????????");
			scanf("%d", &pos);
			SeqListInsert(&s1, pos, x);
			break;
		case SLErase:
			printf("????????????????????????-1??????");
			scanf("%d", &pos);
			while (x != -1)
			{
				SeqListErase(&s1, pos);
				scanf("%d", &pos);
			}
			break;
		case SLFind:
			printf("??????????????????????");
			scanf("%d", &x);
			int tmp = SeqListFind(&s1, x);
			printf("%d\n", tmp);
			break;
		case SLPrint:
			SeqListPrint(&s1);
			break;
		case EXIT:
			DestoryContact(&s1);
			printf("????\n");
			break;
		default:
			printf("????????\n");
			break;
		}
	} while (input);
	return 0;
}

//int main()
//{
//	//TestSeqList1();
//	//TestSeqList2();
//	//TestSeqList3();
//	//TestSeqList4();
//	return 0;
//}







