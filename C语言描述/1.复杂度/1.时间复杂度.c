#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int N = 10;
//	while (N--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//
//
///*
//ʱ�临�Ӷȵĺ�����F(N)=N*N+2*N+10
//Func1ִ�еĻ�������������
//N=10   F(N)=130
//N=100  F(N)=10210
//N=1000 F(N)=1002010
// 
//NԽ�󣬺�����Խ����Ӱ��ԽС
//����Ҫ���㾫ȷ��ִ�д�������ֻ��Ҫ���ִ�д���������ʹ�ô�O�Ľ�����ʾ��
//*/
//
////ʵ��1
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int N = 10;
//	while (N--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}//O(N)
//
////ʵ��2
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//
//}//O(M+N)
//
////һ�������ʱ�临�Ӷȼ���ʱδ֪�������õ�N��Ҳ������������ĸ
///*
//M>>N����O(M)
//N>>M����O(N)
//M��N���󡪡�O(M)=O(N)
//*/
//
////ʵ��3
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}//100����O(1)
//
////�ó���1ȡ������ʱ���е����мӷ�����
//
////ʵ��4
//const char* strchr(const char* str, int character);
////��һ���㷨�������벻ͬ��ʱ�临�ӶȲ�ͬ��ʱ�临�Ӷ�������Ԥ�ڣ���������
//
////ʵ��5
//void BubbleSort(int* a, int n)//ð������
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//		{
//			break;
//		}
//	}
//}//N-1,N-2,N-3...,1     N(N-1)/2����0(N^2)
////ʱ�临�ӶȲ���ֻ���㷨����ʱ��Ҫ��ͼ���� 
//
////ʵ��6
//int BinarySearch(int* a, int n, int x)//���ֲ���
//{
//	assert(a);
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}//1*2*2*2...*2=N     2^X=N    x=log2N
////��ʱ�临�ӶȲ���ֻ���Ǽ���ѭ������Ҫȥ������˼��
//
////ʵ��7
//long long Fac(size_t, N)//�׳�
//{
//	if (0 == N)
//	{
//		return 1;
//	}
//	return Fac(N - 1) * N;
//}//O(N)
////�ݹ��㷨���ݹ����*ÿ�εݹ���õĴ���
//
////ʵ��8
//long long Fib(size_t N)//쳲���������
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}//O(2^N)
///*
//��ͼ����
//Fib(N)  2^0
//Fib(N)����Fib(N - 1)��Fib(N - 2)    2^1
//Fib(N-1)����Fib(N - 2)��Fib(N - 3)   Fib(N-2)����Fib(N - 3)��Fib(N - 4)   2^2
//...
//Fib(2)    X���ұߵ�һЩ�ݹ��֧����ǰ������ȱһЩ�ݹ����
//Fib(1)  Fib(0)   2^(n-1)
//2^0+2^1+2^2+...+2^(N-1)-X=2^N-1
//*/
//
//int main()
//{
//	printf("%lld\n", Fib(10));
//	return 0;
//}
