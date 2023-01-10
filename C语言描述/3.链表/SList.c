#include "SList.h"

//打印链表内容
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//建立新结点
SLTNode* BuyListNode(SLDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//尾插法建立单链表
void SListPushBack(SLTNode** pphead, SLDataType x)
{

	//建立新结点
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找到尾结点
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//头插法建立单链表
void SListPushFront(SLTNode** pphead, SLDataType x)
{
	//建立新结点
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;//就是newnode->next = plist
	*pphead = newnode;
}

//尾删法
void SListPopBack(SLTNode** pphead)//尾删
{
	//while(tail->next!=NULL)

	//温柔处理方式
	if (*pphead == NULL)
	{
		return;
	}
	//暴力方式
	//assert(*pphead != NULL);
	//表中只有1个元素
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//表中大于1个元素
	else
	{
		SLTNode* pre = NULL;//前驱结点
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		pre->next = NULL;
	}
}


void SListPopBack2(SLTNode** pphead)//尾删
{
	//温柔处理方式
	if (*pphead == NULL)
	{
		return;
	}
	//暴力方式
	//assert(*pphead != NULL);

	//表中只有1个元素
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//表中大于1个元素
	else
	{
		SLTNode* tail = *pphead;
		//while(tail->next!=NULL)
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}

}


//头删法
void SListPopFront(SLTNode** pphead)//头删
{
	//空链表，温柔处理方式
	if (*pphead == NULL)
	{
		return;
	}
	//assert(*pphead!=NULL);
	SLTNode* next = (*pphead)->next;//plist的下一个结点
	free(*pphead);
	*pphead = next;//plist的下一个结点作为plist
}


//查找--同时具有修改的作用
SLTNode* SListFind(SLTNode* phead, SLDataType x)
{
	SLTNode* cur = phead;
	//while (cur != NULL)
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


//任意位置插入
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	//考虑在第一个位置插入
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuyListNode(x);
		SLTNode* pre = *pphead;//从头开始
		while (pre->next != pos)
		{
			pre = pre->next;//找到pos的前驱
		}
		pre->next = newnode;//pre不在指向pos，而是newnode
		newnode->next = pos;
	}
}

void SListInsert2(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	//考虑在第一个位置插入
	if (pos == *pphead)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* pre = *pphead;//从头开始
		while (pre->next != pos)
		{
			pre = pre->next;//找到pos的前驱
		}
		pre->next = newnode;
		newnode->next = pos;
	}
}



// 删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos)
{
	if (pos == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* pre = *pphead;
		while (pre->next != pos)
		{
			pre = pre->next;
		}

		pre->next = pos->next;
		free(pos);
	}
}