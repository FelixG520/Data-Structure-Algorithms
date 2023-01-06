#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SeaListInit(SL ps)//初始化
{
	ps.a = NULL;
	ps.size = ps.capacity = 0;
}

void SeaListPushBack(SL* ps, SLDataType x);//尾插
//也可写成：void SeaListPushBack(struct Sqqlist* ps, SLDataType x);
void SeaListPopBack(SL* ps);//尾删
void SeaListPushFront(SL* ps, SLDataType x);//头插
void SeaListPushBack(SL* ps);//头删
