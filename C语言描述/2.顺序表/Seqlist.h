#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#pragma once
#define N 1000

typedef int SLDataType;//���Ͷ��壬int float double...

/*
˳������ṹ
˳�������һ�������ַ�����Ĵ洢��Ԫ���δ洢����Ԫ�ص����Խṹ��һ������²�������洢��
��������������ݵ����Ʋ�ġ�

˳���������飬����������Ļ����ϣ�����Ҫ�������������洢��(��ͷ��ʼ��)��������Ծ���
*/

//��̬˳���
//��̬���ص㣺������˾Ͳ��ò���    ȱ�㣺�����ٵĺ����أ��������ȷ����N��С�˲����ã�N�������˷�
typedef struct Seqlist
{
	SLDataType a[N];//����
	int size;//��ʾ�����д洢�˶��ٸ�����
}SL;

//�ӿں��� -- ��������Ǹ���STL�ߵģ��������ѧϰSTL
void SeaListInit(SL* ps);//��ʼ��



//��̬˳���
typedef struct Seqlist
{
	SLDataType* a;//����
	int size;//��ʾ�����д洢�˶��ٸ�����
	int capacity;//����ʵ���ܴ����ݵĿռ������Ƕ��
}SL;

//�ӿں��� -- ��������Ǹ���STL�ߵģ��������ѧϰSTL
void SeaListPushBack(SL* ps, SLDataType x);//β��
//Ҳ��д�ɣ�void SeaListPushBack(struct Sqqlist* ps, SLDataType x);
void SeaListPopBack(SL* ps);//βɾ
void SeaListPushFront(SL* ps, SLDataType x);//ͷ��
void SeaListPushBack(SL* ps);//ͷɾ


