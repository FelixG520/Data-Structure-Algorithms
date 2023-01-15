#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//容量
}ST;

void StackInit(ST* ps);//初始化
void STackDestory(ST* ps);//释放空间
void StackPush(ST* ps, STDataType x);//入栈
void StackPop(ST* ps);//出栈
STDataType StackTop(ST* ps);//返回栈顶的值
int StackSize(ST* ps);//计算栈大小
bool StackEmpty(ST* ps);//判空
