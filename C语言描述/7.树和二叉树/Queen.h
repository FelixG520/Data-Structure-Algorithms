#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//前置声明
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

void QueueInit(Queue* pq);//初始化
void QueueDestroy(Queue* pq);//销毁

void QueuePush(Queue* pq, QDataType x);//进队
void QueuePop(Queue* pq);//出队

QDataType QueueFront(Queue* pq);//取队头
QDataType QueueBack(Queue* pq);//取队尾
int QueueSize(Queue* pq);//求队长
bool QueueEmpty(Queue* pq);//判空



