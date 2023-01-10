#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct SListNode
{
    int data;
    struct SListNode* next;
}SLTNode;

// 不会改变链表的头指针，传一级指针
void SListPrint(SLTNode* phead);

void SListPushBack(SLTNode** pphead, SLDataType x);//尾插
void SListPushFront(SLTNode** pphead, SLDataType x);//头插
void SListPopFront(SLTNode** pphead);//尾删
void SListPopBack(SLTNode** pphead);//头删

SLTNode* SListFind(SLTNode* phead, SLDataType x);//查找
void SListInsert(SLTNode** phead, SLTNode* pos, SLDataType x);//任意位置插入
void SListErase(SLTNode** phead, SLTNode* pos);//任意位置删除

// 有些地方也有这样的
//// 在pos的前面插入x
//void SListInsert(SLTNode** phead, int i, SLTDataType x);
//// 删除pos位置的值
//void SListErase(SLTNode** phead, int i);


