#include "SList.h"

//��ӡ��������
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

//�����½��
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

//β�巨����������
void SListPushBack(SLTNode** pphead, SLDataType x)
{

	//�����½��
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//�ҵ�β���
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}


//ͷ�巨����������
void SListPushFront(SLTNode** pphead, SLDataType x)
{
	//�����½��
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;//����newnode->next = plist
	*pphead = newnode;
}

//βɾ��
void SListPopBack(SLTNode** pphead)//βɾ
{
	//while(tail->next!=NULL)

	//���ᴦ��ʽ
	if (*pphead == NULL)
	{
		return;
	}
	//������ʽ
	//assert(*pphead != NULL);
	//����ֻ��1��Ԫ��
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//���д���1��Ԫ��
	else
	{
		SLTNode* pre = NULL;//ǰ�����
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


void SListPopBack2(SLTNode** pphead)//βɾ
{
	//���ᴦ��ʽ
	if (*pphead == NULL)
	{
		return;
	}
	//������ʽ
	//assert(*pphead != NULL);

	//����ֻ��1��Ԫ��
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//���д���1��Ԫ��
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


//ͷɾ��
void SListPopFront(SLTNode** pphead)//ͷɾ
{
	//���������ᴦ��ʽ
	if (*pphead == NULL)
	{
		return;
	}
	//assert(*pphead!=NULL);
	SLTNode* next = (*pphead)->next;//plist����һ�����
	free(*pphead);
	*pphead = next;//plist����һ�������Ϊplist
}


//����--ͬʱ�����޸ĵ�����
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


//����λ�ò���
void SListInsert(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	//�����ڵ�һ��λ�ò���
	if (pos == *pphead)
	{
		SListPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuyListNode(x);
		SLTNode* pre = *pphead;//��ͷ��ʼ
		while (pre->next != pos)
		{
			pre = pre->next;//�ҵ�pos��ǰ��
		}
		pre->next = newnode;//pre����ָ��pos������newnode
		newnode->next = pos;
	}
}

void SListInsert2(SLTNode** pphead, SLTNode* pos, SLDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	//�����ڵ�һ��λ�ò���
	if (pos == *pphead)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* pre = *pphead;//��ͷ��ʼ
		while (pre->next != pos)
		{
			pre = pre->next;//�ҵ�pos��ǰ��
		}
		pre->next = newnode;
		newnode->next = pos;
	}
}



// ɾ��posλ�õ�ֵ
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