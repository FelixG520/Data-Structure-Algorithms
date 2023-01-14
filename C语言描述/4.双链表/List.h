#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLDataType;

typedef struct ListNode
{
	SLDataType data;
	struct ListNode* next;
	struct ListNode* pre;

}LTNode;


//可以用二级指针，这里用返回值的形式
LTNode* ListInit();//初始化
void ListPrint(LTNode* phead);//打印
LTNode* BuyLisyNode(SLDataType x);//建立新结点
void ListDestroy(LTNode* phead);//销毁空间

void ListPushBack(LTNode* phead, SLDataType x);//尾插
void ListPopBack(LTNode* phead);//尾删
void ListPushFront(LTNode* phead, SLDataType x);//头插
void ListPopFront(LTNode* phead);//头删
LTNode* ListFind(LTNode* phead, SLDataType x);//查找
LTNode* ListInsert(LTNode* pos, SLDataType x);//任意位置插入
LTNode* ListErase(LTNode* pos);//任意位置删除


