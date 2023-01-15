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