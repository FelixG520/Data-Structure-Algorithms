#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
///*
//空间复杂度也是一个数学函数表达式，是对一个算法在运行过程中临时额外占用存储空间大小的量度
//空间复杂度不是程序占用了多少bytes空间，没太大意义，空间复杂度算的是变量的个数。
//空间复杂度计算规则基本跟时间复杂度类似，也使用大O渐进表示法
//
//*/
//
////实例1
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
//}//O(1)——i在循环之后销毁，共用一个i
//
////实例2
//long long Fibonacci(size_t n)//斐波那契数列
//{
//	if (n == 0)
//	{
//		return NULL;
//	}
//	long long* fibArray = (long long *)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 1; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}//空间复杂度O(n)   时间复杂度O(n)
//
//long long Fax(size_t N)//阶乘
//{
//	if (N == 1)
//	{
//		return 1;
//	}
//	return Fac(N - 1) * N;
//}//建立了n个栈帧——空间复杂度O(n)
//
//
//long long Fib(size_t N)//斐波那契数列——递归算法
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}//空间复杂度O(n)
////Fib(N)->Fib(N-1)->Fib(N-2)...->Fib(1)
////空间是可以重复利用的，不累计的；时间是一去不复返的，累积的
//
//
