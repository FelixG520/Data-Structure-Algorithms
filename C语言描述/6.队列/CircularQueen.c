#include "Queen.h"

typedef struct
{
	int* a;//数组结构实现
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

//入队
bool myCircularQueueEnQueue(MyCircularQueue * obj, int value)
{
	if (myCircularQueueIsFUll(obj))
		return false;
	obj->a[obj->tail] = value;
	++obj->tail;
	obj->tail %= (obj->k + 1);
	return true;
}

//出队
bool myCircularQueueDeQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsEmpty(obj))
		return false;
	++obj->front;
	obj->front %= (obj->k + 1);
	return true;

}

//取队头
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	return obj->a[obj->front];
}

//取队尾
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



bool myCircularQueueIsEmpty(MyCircularQueue* obj)//判空
{
	return obj->front == obj->tail;
}

bool myCircularQueueIsFUll(MyCircularQueue* obj)//判满
{
	return (obj->tail + 1) % (obj->k + 1) == obj->front;
}
void myCircularQueueIsFree(MyCircularQueue* obj)
{
	free(obj->a);
	free(obj);
}