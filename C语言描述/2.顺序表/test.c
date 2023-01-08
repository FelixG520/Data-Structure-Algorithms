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
	printf("******** 1.ͷ��            2.β��    *******\n");
	printf("******** 3.ͷɾ            4.βɾ    *******\n");
	printf("******** 5.ͷ��2           6.β��2   *******\n");
	printf("******** 7.ͷɾ2           8.βɾ2   *******\n");
	printf("******** 9.����            10.ɾ��   *******\n");
	printf("******** 11.����           0.�˳�   *******\n");
	printf("********************************************\n");

}

int main()
{
	int input = 0;
	//����ͨѶ¼
	int size = 0;//ͨѶ¼��Ԫ�ظ���
	struct Contact con;//con����ͨѶ¼,�������1000��Ԫ�غ�size
	//��ʼ��ͨѶ¼
	InitContact(&con);
	//
	do
	{
		menu();
		printf("��ѡ��");
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
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�������\n");
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