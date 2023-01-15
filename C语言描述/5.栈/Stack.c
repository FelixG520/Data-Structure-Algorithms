#include "Stack.h"

void StackInit(ST* ps)//��ʼ��
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;//Ҳ���Ը�-1
	ps->capacity = 0;
}
void STackDestory(ST* ps)//�ͷſռ�
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps,STDataType x)//��ջ
{
	assert(ps);
	if (ps->top == ps->capacity)//ջ��
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType)*newcapacity);//aΪ��ʱ���൱��malloc
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


void StackPop(ST* ps)//��ջ
{
	assert(ps);
	//assert(ps->top > 0);//�пգ�top����С��0
	assert(!StackEmpty(ps));//�п�
	ps->top--;

}


STDataType StackTop(ST* ps)//����ջ����ֵ
{
	assert(ps);
	//assert(ps->top > 0);//top����С��0��ɾ���ˣ��Ͳ��ܷ���top��
	assert(!StackEmpty(ps));//�п�
	return ps->a[ps->top - 1];//topָ�����ջ��Ԫ�ص���һ�������-1
}


int StackSize(ST* ps)//����ջ��С
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST* ps)//�п�
{
	assert(ps);
	return ps->top == 0;//����0����true��������0����false
}
