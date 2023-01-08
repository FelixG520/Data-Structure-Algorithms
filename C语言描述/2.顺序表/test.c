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
	printf("******** 1.头插            2.尾插    *******\n");
	printf("******** 3.头删            4.尾删    *******\n");
	printf("******** 5.头插2           6.尾插2   *******\n");
	printf("******** 7.头删2           8.尾删2   *******\n");
	printf("******** 9.插入            10.删除   *******\n");
	printf("******** 11.查找           0.退出   *******\n");
	printf("********************************************\n");

}

int main()
{
	int input = 0;
	//创建通讯录
	int size = 0;//通讯录里元素个数
	struct Contact con;//con就是通讯录,里面包含1000个元素和size
	//初始化通讯录
	InitContact(&con);
	//
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	return 0;
}

int main()
{
	//TestSeqList1();
	//TestSeqList2();
	//TestSeqList3();
	//TestSeqList4();
	return 0;
}