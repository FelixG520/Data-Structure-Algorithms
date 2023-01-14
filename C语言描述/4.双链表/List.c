#include "List.h"
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

LTNode* ListInit()//初始化
{
	//作为哨兵位的头结点,不用给值，随机值，存啥不重要
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->pre = phead;
	return phead;
}

//建立新结点
LTNode* BuyLisyNode(SLDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}


void ListPushBack(LTNode* phead, SLDataType x)//尾插
{
	assert(phead);

	LTNode* tail = phead->pre;
	LTNode* newnode = BuyLisyNode(x);

	tail->next = newnode;
	newnode->pre = tail;
	newnode->next = phead;
	phead->pre = newnode;
}

void ListPopBack(LTNode* phead)//尾删
{
	//不能删除哨兵位
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->pre;
	LTNode* tailpre = tail->pre;
	free(phead->pre);//free(tail);

	//记录为指针，避免出现野指针
	tailpre->next = phead;
	phead->pre = tailpre;
}

void ListPopBack2(LTNode* phead)//尾删
{
	//不能删除哨兵位
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->pre;

	phead->pre = tail->pre;
	tail->pre->next = phead;
	free(tail);
}

void ListPushFront(LTNode* phead, SLDataType x)//头插
{
	assert(phead);
	LTNode* newnode = BuyLisyNode(x);
	LTNode* next = phead->next;

	//空链表也不会有问题
	phead->next = newnode;
	newnode->pre = phead;
	newnode->next = next;
	next->pre = newnode;
}

void ListPopFront(LTNode* phead)//头删
{
	assert(phead);
	assert(phead->next != phead);//链表空

	LTNode* next = phead->next;
	LTNode* nextNext = next->next;

	phead->next = nextNext;
	nextNext->pre = phead;
	free(next);
}

LTNode* ListFind(LTNode* phead, SLDataType x)//查找
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos位置前插入
LTNode* ListInsert(LTNode* pos, SLDataType x)//任意位置插入
{
	assert(pos);
	LTNode* posPre = pos->pre;
	LTNode* newnode = BuyLisyNode(x);

	//posPre   newnode   pos
	posPre->next = newnode;
	newnode->pre = posPre;
	newnode->next = pos;
	pos->pre = newnode;
}


void ListPushBack2(LTNode* phead, SLDataType x)//尾插
{
	assert(phead);
	ListInsert(phead, x);
}
void ListPushFront2(LTNode* phead, SLDataType x)//头插
{
	assert(phead);
	ListInsert(phead->next, x);
}


LTNode* ListErase(LTNode* pos)//任意位置删除
{
	assert(pos);
	LTNode* posPre = pos->pre;
	LTNode* posNext = pos->next;

	posPre->next = posNext;
	posNext->pre = posPre;
	free(pos);
	pos = NULL;
}

void ListPopFront3(LTNode* phead)//头删
{
	assert(phead);
	assert(phead->next != phead);//链表空
	ListErase(phead->next);

}

void ListPopBack3(LTNode* phead)//尾删
{
	//不能删除哨兵位
	assert(phead);
	assert(phead->next != phead);
	ListErase(phead->pre);
}


void ListDestroy(LTNode* phead)//销毁空间
{
	assert(phead);
	LTNode* cur = phead;
	while (cur!=phead)
	{
		//释放一个就找不到他的下一个节点了，因此要保存下来下一个节点
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

}
