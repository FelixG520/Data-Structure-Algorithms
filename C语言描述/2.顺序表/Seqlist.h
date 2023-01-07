/*
顺序表概念及结构
顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构，一般情况下采用数组存储。
在数组上完成数据的增制查改。

顺序表就是数组，但是在数组的基础上，它还要求数据是连续存储的(从头开始存)，不能跳跃间隔
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#pragma once
#define N 1000
typedef int SLDataType;//类型重定义，int float double...



//静态顺序表
//静态的特点：如果满了就不让插入    缺点：给多少的合适呢？这个很难确定。N给小了不够用，N给大了浪费
//typedef struct Seqlist
//{
//	SLDataType  a[N];//数组
//	int size;//表示数组中存储了多少个数据
//}SL;

//**********************************************************************************************************


//动态顺序表
typedef struct Seqlist
{
	SLDataType* a;//数组
	int size;//表示数组中存储了多少个数据
	int capacity;//数组实际能存数据的空间容量是多大
}SL;




void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);
void SeqlistCheckCapacity(SL* ps);


//接口函数 -- 命名风格是跟着STL走的，方便后续学习STL
void SeaListInit(SL* ps);//初始化
void SeqListPushBack(SL* ps, SLDataType x);//尾插
//也可写成：void SeqListPushBack(struct Sqqlist* ps, SLDataType x);
void SeqListPopBack(SL* ps);//尾删
void SeqListPushFront(SL* ps, SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删
// ...
int SeqListFind(SL* ps, SLDataType x);//找到了返回x位置下标，没有找到返回-1
void SeqListInsert(SL* ps, int pos,SLDataType x);//在指定下标位置插入
void SeqListErase(SL* ps, int pos, SLDataType x);//删除任意位置元素
