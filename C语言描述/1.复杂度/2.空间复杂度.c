#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
///*
//�ռ临�Ӷ�Ҳ��һ����ѧ�������ʽ���Ƕ�һ���㷨�����й�������ʱ����ռ�ô洢�ռ��С������
//�ռ临�ӶȲ��ǳ���ռ���˶���bytes�ռ䣬û̫�����壬�ռ临�Ӷ�����Ǳ����ĸ�����
//�ռ临�Ӷȼ�����������ʱ�临�Ӷ����ƣ�Ҳʹ�ô�O������ʾ��
//
//*/
//
////ʵ��1
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
//}//O(1)����i��ѭ��֮�����٣�����һ��i
//
////ʵ��2
//long long Fibonacci(size_t n)//쳲���������
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
//}//�ռ临�Ӷ�O(n)   ʱ�临�Ӷ�O(n)
//
//long long Fax(size_t N)//�׳�
//{
//	if (N == 1)
//	{
//		return 1;
//	}
//	return Fac(N - 1) * N;
//}//������n��ջ֡�����ռ临�Ӷ�O(n)
//
//
//long long Fib(size_t N)//쳲��������С����ݹ��㷨
//{
//	if (N < 3)
//	{
//		return 1;
//	}
//	return Fib(N - 1) + Fib(N - 2);
//}//�ռ临�Ӷ�O(n)
////Fib(N)->Fib(N-1)->Fib(N-2)...->Fib(1)
////�ռ��ǿ����ظ����õģ����ۼƵģ�ʱ����һȥ�������ģ��ۻ���
//
//
