#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100000


void InsertSort(int* a, int n);//插入排序
void ShellSort(int* a, int n);//希尔排序

//堆排序
void HeapSort(int* a, int n);
void Swap(int* p1, int* p2);
void AdjustDown(int* a, int n, int root);//向下调整算法

void SelectSort(int* a, int n);//直接选择排序
void BubbleSort(int* a, int n);//冒泡排序

void MergeSort(int* a, int n);//归并排序
void MergeSortNonR(int* a, int n);//归并排序非递归

void CountSort(int* a, int n);//计数排序

void TestInsertSort();
void TestShellSort();
void TestHeapSort();
void TestSelectSort();
void TestBubbleSort();
void TestQuickSort();
void TestCountSort();


void PrintArray(int* a, int n);//打印
void TestOP();// 测试排序的性能对比