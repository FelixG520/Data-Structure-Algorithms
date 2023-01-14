#include "List.h"



void TestList1()
{
	LTNode* plist = ListInit();
	ListInit(plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);

	ListPopBack(plist);
	ListPrint(plist);
	ListPushFront(plist, 1000);
	ListPushFront(plist, 1001);
	ListPushFront(plist, 1002);
	ListPushFront(plist, 1003);
	ListPushFront(plist, 1004);
	ListPrint(plist);

	LTNode* cur = ListFind(plist, 1000);
	printf("%d\n", cur);

}

void TestList2()
{
	LTNode* plist = ListInit();
	ListInit(plist);
	ListPushBack2(plist, 1000);
	ListPushBack2(plist, 1001);
	ListPushBack2(plist, 1002);
	ListPushBack2(plist, 1003);
	ListPushFront2(plist, 1004);
	ListPushFront2(plist, 1005);
	ListPushFront2(plist, 1006);
	ListPushFront2(plist, 1007);
	ListPrint(plist);


	LTNode* pos = ListFind(plist, 1002);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);

}


void TestList3()
{
	LTNode* plist = ListInit();
	ListInit(plist);
	ListPushBack2(plist, 1000);
	ListPushBack2(plist, 1001);
	ListPushBack2(plist, 1002);
	ListPushBack2(plist, 1003);
	ListPushFront2(plist, 1004);
	ListPushFront2(plist, 1005);
	ListPushFront2(plist, 1006);
	ListPushFront2(plist, 1007);
	ListPrint(plist);


	ListPopFront3(plist);
	ListPopBack3(plist);
	ListPrint(plist);

	ListDestroy(plist);
	plist = NULL;
}
int main()
{
	//TestList1();
	//TestList2();
	TestList3();


	return 0;
}