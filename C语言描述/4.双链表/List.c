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

LTNode* ListInit()//��ʼ��
{
	//��Ϊ�ڱ�λ��ͷ���,���ø�ֵ�����ֵ����ɶ����Ҫ
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->pre = phead;
	return phead;
}

//�����½��
LTNode* BuyLisyNode(SLDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->pre = NULL;
	return newnode;
}


void ListPushBack(LTNode* phead, SLDataType x)//β��
{
	assert(phead);

	LTNode* tail = phead->pre;
	LTNode* newnode = BuyLisyNode(x);

	tail->next = newnode;
	newnode->pre = tail;
	newnode->next = phead;
	phead->pre = newnode;
}

void ListPopBack(LTNode* phead)//βɾ
{
	//����ɾ���ڱ�λ
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->pre;
	LTNode* tailpre = tail->pre;
	free(phead->pre);//free(tail);

	//��¼Ϊָ�룬�������Ұָ��
	tailpre->next = phead;
	phead->pre = tailpre;
}

void ListPopBack2(LTNode* phead)//βɾ
{
	//����ɾ���ڱ�λ
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->pre;

	phead->pre = tail->pre;
	tail->pre->next = phead;
	free(tail);
}

void ListPushFront(LTNode* phead, SLDataType x)//ͷ��
{
	assert(phead);
	LTNode* newnode = BuyLisyNode(x);
	LTNode* next = phead->next;

	//������Ҳ����������
	phead->next = newnode;
	newnode->pre = phead;
	newnode->next = next;
	next->pre = newnode;
}

void ListPopFront(LTNode* phead)//ͷɾ
{
	assert(phead);
	assert(phead->next != phead);//�����

	LTNode* next = phead->next;
	LTNode* nextNext = next->next;

	phead->next = nextNext;
	nextNext->pre = phead;
	free(next);
}

LTNode* ListFind(LTNode* phead, SLDataType x)//����
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

//��posλ��ǰ����
LTNode* ListInsert(LTNode* pos, SLDataType x)//����λ�ò���
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


void ListPushBack2(LTNode* phead, SLDataType x)//β��
{
	assert(phead);
	ListInsert(phead, x);
}
void ListPushFront2(LTNode* phead, SLDataType x)//ͷ��
{
	assert(phead);
	ListInsert(phead->next, x);
}


LTNode* ListErase(LTNode* pos)//����λ��ɾ��
{
	assert(pos);
	LTNode* posPre = pos->pre;
	LTNode* posNext = pos->next;

	posPre->next = posNext;
	posNext->pre = posPre;
	free(pos);
	pos = NULL;
}

void ListPopFront3(LTNode* phead)//ͷɾ
{
	assert(phead);
	assert(phead->next != phead);//�����
	ListErase(phead->next);

}

void ListPopBack3(LTNode* phead)//βɾ
{
	//����ɾ���ڱ�λ
	assert(phead);
	assert(phead->next != phead);
	ListErase(phead->pre);
}


void ListDestroy(LTNode* phead)//���ٿռ�
{
	assert(phead);
	LTNode* cur = phead;
	while (cur!=phead)
	{
		//�ͷ�һ�����Ҳ���������һ���ڵ��ˣ����Ҫ����������һ���ڵ�
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}

}
