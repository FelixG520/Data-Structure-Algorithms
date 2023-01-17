#include "Queen.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;
}



void QueueDestroy(Queue* pq)//销毁
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


void QueuePush(Queue* pq, QDataType x)//进队
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


void QueuePop(Queue* pq)//出队
{
	assert(pq);
	/*if (pq->head)
		return;*/
	assert(!QueueEmpty(pq));//队空就不能继续删除了
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head==NULL)//空间被释放，但指针还在，避免出现野指针
	{
		pq->tail = NULL;
	}
}

QDataType QueueFront(Queue* pq)//取队头
{
	assert(!QueueEmpty(pq));
	assert(pq);
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)//取队尾
{
	assert(!QueueEmpty(pq));
	assert(pq);
	return pq->tail->data;
}

int QueueSize(Queue* pq)//求队长
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

bool QueueEmpty(Queue* pq)//判空
{
	assert(pq);
	return pq->head == NULL;
}