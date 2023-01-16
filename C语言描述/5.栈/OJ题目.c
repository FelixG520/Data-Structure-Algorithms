#include "Stack.h"

//1. ����ƥ�����⡣
bool isValid(char* s)
{
	ST st;
	StackInit(&st);
	while (*s)//'\0'����
	{
		if ((*s == '(')
			||( *s == '{')
			|| (*s == '['))
		{
			StackPush(&st, *s);//��������ջ
			++s;
		}
		else
		{
			//û��������ջ�գ�ֻ��һ��������,��ƥ��
			if (StackEmpty(&st))
			{
				STackDestory(&st);//��ֹ�ڴ�й©
				return false;
			}
			STDataType top = StackTop(&st);
			StackPop(&st);//�����ų�ջ
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				STackDestory(&st);//��ֹ�ڴ�й©
				return false;//��ƥ��
			}
			else
			{
				++s;//ƥ�䣬����ƥ��
			}
		}

	}
	//���ջ���ǿգ�˵��ջ�л���������δ��
	//û��ƥ�䣬����ʱfalse
	bool ret = StackEmpty(&st);//û��ƥ�䣬���Ѿ�ջ��
	STackDestory(&st);
	return true;
}


//��ջʵ�ֶ���
typedef struct
{
	ST pushST;
	ST popST;
}MyQueue;

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->pushST);
	StackInit(&q->popST);
	return q;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))//popջû�����ݣ���Ҫ��pushջ�ﵹ����
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}

int myQueuePeek(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))//popջû�����ݣ���Ҫ��pushջ�ﵹ����
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->popST) && StackEmpty(&obj->pushST);
}

void myQueueFree(MyQueue* obj)
{
	QueueDestroy(&obj->popST);
	QueueDestroy(&obj->pushST);
	free(obj);
}