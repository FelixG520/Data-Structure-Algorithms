#pragma once
#include "Sort.h"
//�������򷽷�
void QuickSort(int* a, int left, int right);//�ڿӷ�
void QuickSort2(int* a, int left, int right);//����ָ�뷨
void QuickSort3(int* a, int left, int right);//ǰ��ָ�뷨


//������������
void QuickSort_Conformity(int* a, int left, int right);//��������
int PartSort_Trenching(int* a, int left, int right);
int PartSort_RLHands(int* a, int left, int right);
int PartSort_FBHands(int* a, int left, int right);




//�Ż�
int GetMidIndex(int* a, int left, int right);//����ȡ��
void QuickSort_Mid_Minizone(int* a, int left, int right);//С�����Ż�
void TestQuickSort_optimize();