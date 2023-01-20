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


void PrintArray(int* a, int n);//打印
void TestOP();// 测试排序的性能对比