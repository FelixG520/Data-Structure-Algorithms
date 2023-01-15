#include "Queen.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}



void QueueDestroy(Queue* pq)//����
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}


void QueuePush(Queue* pq, QDataType x)//����
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("Realloc fail!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}


void QueuePop(Queue* pq)//����
{
	assert(pq);
	/*if (pq->head)
		return;*/
	assert(!QueueEmpty(pq));//�ӿվͲ��ܼ���ɾ����
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head==NULL)//�ռ䱻�ͷţ���ָ�뻹�ڣ��������Ұָ��
	{
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)//ȡ��ͷ
{
	assert(!QueueEmpty(pq));
	assert(pq);
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)//ȡ��β
{
	assert(!QueueEmpty(pq));
	assert(pq);
	return pq->tail->data;
}

int QueueSize(Queue* pq)//��ӳ�
{
	assert(pq);
	int n = 0;
	QueueNode* cur = pq->head;
	while (cur)
	{
		n++;
		cur = cur->next;
	}
	return n;
}

bool QueueEmpty(Queue* pq)//�п�
{
	assert(pq);
	return pq->head == NULL;
}