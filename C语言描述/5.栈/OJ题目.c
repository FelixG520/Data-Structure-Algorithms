#include "Stack.h"

//1. 括号匹配问题。
bool isValid(char* s)
{
	ST st;
	StackInit(&st);
	while (*s)//'\0'结束
	{
		if ((*s == '(')
			||( *s == '{')
			|| (*s == '['))
		{
			StackPush(&st, *s);//左括号入栈
			++s;
		}
		else
		{
			//没有左括号栈空，只有一个右括号,不匹配
			if (StackEmpty(&st))
			{
				STackDestory(&st);//防止内存泄漏
				return false;
			}
			STDataType top = StackTop(&st);
			StackPop(&st);//右括号出栈
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				STackDestory(&st);//防止内存泄漏
				return false;//不匹配
			}
			else
			{
				++s;//匹配，继续匹配
			}
		}

	}
	//如果栈不是空，说明栈中还有左括号未出
	//没有匹配，返回时false
	bool ret = StackEmpty(&st);//没有匹配，但已经栈空
	STackDestory(&st);
	return true;
}


//用栈实现队列
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
	if (StackEmpty(&obj->popST))//pop栈没有数据，就要从push栈里倒过来
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
	if (StackEmpty(&obj->popST))//pop栈没有数据，就要从push栈里倒过来
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