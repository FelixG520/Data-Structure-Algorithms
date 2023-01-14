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


//�����ö���ָ�룬�����÷���ֵ����ʽ
LTNode* ListInit();//��ʼ��
void ListPrint(LTNode* phead);//��ӡ
LTNode* BuyLisyNode(SLDataType x);//�����½��
void ListDestroy(LTNode* phead);//���ٿռ�

void ListPushBack(LTNode* phead, SLDataType x);//β��
void ListPopBack(LTNode* phead);//βɾ
void ListPushFront(LTNode* phead, SLDataType x);//ͷ��
void ListPopFront(LTNode* phead);//ͷɾ
LTNode* ListFind(LTNode* phead, SLDataType x);//����
LTNode* ListInsert(LTNode* pos, SLDataType x);//����λ�ò���
LTNode* ListErase(LTNode* pos);//����λ��ɾ��


