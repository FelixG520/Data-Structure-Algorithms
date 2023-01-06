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
//时间复杂度的函数：F(N)=N*N+2*N+10
//Func1执行的基本操作次数：
//N=10   F(N)=130
//N=100  F(N)=10210
//N=1000 F(N)=1002010
// 
//N越大，后两项对结果的影响越小
//不需要计算精确的执行次数，而只需要大概执行次数，这里使用大O的渐进表示法
//*/
//
////实例1
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
////实例2
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
////一般情况下时间复杂度计算时未知数都是用的N，也可以是其他字母
///*
//M>>N——O(M)
//N>>M——O(N)
//M和N差不多大——O(M)=O(N)
//*/
//
////实例3
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}//100——O(1)
//
////用常数1取代运行时间中的所有加法常数
//
////实例4
//const char* strchr(const char* str, int character);
////当一个算法随着输入不同，时间复杂度不同，时间复杂度做悲观预期，看最坏的情况
//
////实例5
//void BubbleSort(int* a, int n)//冒泡排序
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
//}//N-1,N-2,N-3...,1     N(N-1)/2——0(N^2)
////时间复杂度不能只看算法，有时还要画图分析 
//
////实例6
//int BinarySearch(int* a, int n, int x)//二分查找
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
////算时间复杂度不能只看是几层循环，而要去看他的思想
//
////实例7
//long long Fac(size_t, N)//阶乘
//{
//	if (0 == N)
//	{
//		return 1;
//	}
//	return Fac(N - 1) * N;
//}//O(N)
////递归算法：递归次数*每次递归调用的次数
//
////实例8
//long long Fib(size_t N)//斐波那契数列
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}//O(2^N)
///*
//画图分析
//Fib(N)  2^0
//Fib(N)调用Fib(N - 1)和Fib(N - 2)    2^1
//Fib(N-1)调用Fib(N - 2)和Fib(N - 3)   Fib(N-2)调用Fib(N - 3)和Fib(N - 4)   2^2
//...
//Fib(2)    X：右边的一些递归分支会提前结束，缺一些递归调用
//Fib(1)  Fib(0)   2^(n-1)
//2^0+2^1+2^2+...+2^(N-1)-X=2^N-1
//*/
//
//int main()
//{
//	printf("%lld\n", Fib(10));
//	return 0;
//}
