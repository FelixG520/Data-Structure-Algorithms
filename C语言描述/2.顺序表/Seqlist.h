/*
˳������ṹ
˳�������һ�������ַ�����Ĵ洢��Ԫ���δ洢����Ԫ�ص����Խṹ��һ������²�������洢��
��������������ݵ����Ʋ�ġ�

˳���������飬����������Ļ����ϣ�����Ҫ�������������洢��(��ͷ��ʼ��)��������Ծ���
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#pragma once
#define N 1000
typedef int SLDataType;//�����ض��壬int float double...



//��̬˳���
//��̬���ص㣺������˾Ͳ��ò���    ȱ�㣺�����ٵĺ����أ��������ȷ����N��С�˲����ã�N�������˷�
//typedef struct Seqlist
//{
//	SLDataType  a[N];//����
//	int size;//��ʾ�����д洢�˶��ٸ�����
//}SL;

//**********************************************************************************************************


//��̬˳���
typedef struct Seqlist
{
	SLDataType* a;//����
	int size;//��ʾ�����д洢�˶��ٸ�����
	int capacity;//����ʵ���ܴ����ݵĿռ������Ƕ��
}SL;




void SeqListPrint(SL* ps);
void SeqListDestory(SL* ps);
void SeqlistCheckCapacity(SL* ps);


//�ӿں��� -- ��������Ǹ���STL�ߵģ��������ѧϰSTL
void SeaListInit(SL* ps);//��ʼ��
void SeqListPushBack(SL* ps, SLDataType x);//β��
//Ҳ��д�ɣ�void SeqListPushBack(struct Sqqlist* ps, SLDataType x);
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ
// ...
int SeqListFind(SL* ps, SLDataType x);//�ҵ��˷���xλ���±꣬û���ҵ�����-1
void SeqListInsert(SL* ps, int pos,SLDataType x);//��ָ���±�λ�ò���
void SeqListErase(SL* ps, int pos, SLDataType x);//ɾ������λ��Ԫ��
