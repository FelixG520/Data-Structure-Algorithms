#include "Stack.h"

void StackInit(ST* ps)//初始化
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//也可以给-1
	ps->capacity = 0;
}
void STackDestory(ST* ps)//释放空间
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps,STDataType x)//入栈
{
	assert(ps);
	if (ps->top == ps->capacity)//栈满
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType)*newcapacity);//a为空时，相当于malloc
		if (tmp == NULL)
		{
			printf("Realloc fail!\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}


void StackPop(ST* ps)//出栈
{
	assert(ps);
	//assert(ps->top > 0);//判空，top不能小于0
	assert(!StackEmpty(ps));//判空
	ps->top--;

}


STDataType StackTop(ST* ps)//返回栈顶的值
{
	assert(ps);
	//assert(ps->top > 0);//top不能小于0，删空了，就不能返回top了
	assert(!StackEmpty(ps));//判空
	return ps->a[ps->top - 1];//top指向的是栈顶元素的下一个，因此-1
}


int StackSize(ST* ps)//计算栈大小
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)//判空
{
	assert(ps);
	return ps->top == 0;//等于0就是true，不等于0就是false
}
