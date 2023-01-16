#include "Queen.h"

typedef struct
{
	int* a;//����ṹʵ��
	int front;
	int tail;
	int k;
}MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	cq->a = (int*)malloc(sizeof(int) * (k + 1));
	cq->front = cq->tail = 0;
	cq->k = k;
	return cq;
}

//���
bool myCircularQueueEnQueue(MyCircularQueue * obj, int value)
{
	if (myCircularQueueIsFUll(obj))
		return false;
	obj->a[obj->tail] = value;
	++obj->tail;
	obj->tail %= (obj->k + 1);
	return true;
}

//����
bool myCircularQueueDeQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsEmpty(obj))
		return false;
	++obj->front;
	obj->front %= (obj->k + 1);
	return true;

}

//ȡ��ͷ
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->a[obj->front];
}

//ȡ��β
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	if (obj->tail == 0)
	{
		return obj->a[obj->k];
	}
	else
	{
		return obj->a[obj->tail - 1];
	}
	/*int i = (obj->tail + obj->k) % (obj->k + 1);
	return obj->a[i];*/
	
}



bool myCircularQueueIsEmpty(MyCircularQueue* obj)//�п�
{
	return obj->front == obj->tail;
}

bool myCircularQueueIsFUll(MyCircularQueue* obj)//����
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}
void myCircularQueueIsFree(MyCircularQueue* obj)
{
	free(obj->a);
	free(obj);
}