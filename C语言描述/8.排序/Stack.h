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
	int top;//ջ��
	int capacity;//����
}ST;

void StackInit(ST* ps);//��ʼ��
void STackDestory(ST* ps);//�ͷſռ�
void StackPush(ST* ps, STDataType x);//��ջ
void StackPop(ST* ps);//��ջ
STDataType StackTop(ST* ps);//����ջ����ֵ
int StackSize(ST* ps);//����ջ��С
bool StackEmpty(ST* ps);//�п�
