#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 100000


void InsertSort(int* a, int n);//��������
void ShellSort(int* a, int n);//ϣ������

//������
void HeapSort(int* a, int n);
void Swap(int* p1, int* p2);
void AdjustDown(int* a, int n, int root);//���µ����㷨


void PrintArray(int* a, int n);//��ӡ
void TestOP();// ������������ܶԱ�