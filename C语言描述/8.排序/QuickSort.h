#pragma once
#include "Sort.h"
//快速排序方法
void QuickSort(int* a, int left, int right);//挖坑法
void QuickSort2(int* a, int left, int right);//左右指针法
void QuickSort3(int* a, int left, int right);//前后指针法


//快速排序整合
void QuickSort_Conformity(int* a, int left, int right);//快速排序
int PartSort_Trenching(int* a, int left, int right);
int PartSort_RLHands(int* a, int left, int right);
int PartSort_FBHands(int* a, int left, int right);




//优化
int GetMidIndex(int* a, int left, int right);//三数取中
void QuickSort_Mid_Minizone(int* a, int left, int right);//小区间优化
void TestQuickSort_optimize();