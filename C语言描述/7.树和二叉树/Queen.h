#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//ǰ������
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);//��ʼ��
void QueueDestroy(Queue* pq);//����

void QueuePush(Queue* pq, QDataType x);//����
void QueuePop(Queue* pq);//����

QDataType QueueFront(Queue* pq);//ȡ��ͷ
QDataType QueueBack(Queue* pq);//ȡ��β
int QueueSize(Queue* pq);//��ӳ�
bool QueueEmpty(Queue* pq);//�п�



