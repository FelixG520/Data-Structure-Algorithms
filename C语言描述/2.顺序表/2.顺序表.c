#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SeaListInit(SL ps)//��ʼ��
{
	ps.a = NULL;
	ps.size = ps.capacity = 0;
}

void SeaListPushBack(SL* ps, SLDataType x);//β��
//Ҳ��д�ɣ�void SeaListPushBack(struct Sqqlist* ps, SLDataType x);
void SeaListPopBack(SL* ps);//βɾ
void SeaListPushFront(SL* ps, SLDataType x);//ͷ��
void SeaListPushBack(SL* ps);//ͷɾ
