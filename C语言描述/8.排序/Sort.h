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

void SelectSort(int* a, int n);//ֱ��ѡ������
void BubbleSort(int* a, int n);//ð������

void MergeSort(int* a, int n);//�鲢����
void MergeSortNonR(int* a, int n);//�鲢����ǵݹ�

void CountSort(int* a, int n);//��������

void TestInsertSort();
void TestShellSort();
void TestHeapSort();
void TestSelectSort();
void TestBubbleSort();
void TestQuickSort();
void TestCountSort();


void PrintArray(int* a, int n);//��ӡ
void TestOP();// ������������ܶԱ�