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

// ����ı������ͷָ�룬��һ��ָ��
void SListPrint(SLTNode* phead);

void SListPushBack(SLTNode** pphead, SLDataType x);//β��
void SListPushFront(SLTNode** pphead, SLDataType x);//ͷ��
void SListPopFront(SLTNode** pphead);//βɾ
void SListPopBack(SLTNode** pphead);//ͷɾ

SLTNode* SListFind(SLTNode* phead, SLDataType x);//����
void SListInsert(SLTNode** phead, SLTNode* pos, SLDataType x);//����λ�ò���
void SListErase(SLTNode** phead, SLTNode* pos);//����λ��ɾ��

// ��Щ�ط�Ҳ��������
//// ��pos��ǰ�����x
//void SListInsert(SLTNode** phead, int i, SLTDataType x);
//// ɾ��posλ�õ�ֵ
//void SListErase(SLTNode** phead, int i);


