#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
//打印顺序表中内容
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//销毁空间
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SeaListInit(SL* ps)//初始化
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//扩容
void SeqlistCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//如果是0，就给四个空间，如果capacity满了就扩大n倍，随便自己扩大
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		{
			//如果空间开辟失败
			if (tmp == NULL)
			{
				printf("realloc fail\n");
				exit(-1);
			}
			//空间开辟成功
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
}

//********************************************************************
void SeqListPushBack(SL* ps, SLDataType x)//尾插
{
	SeqlistCheckCapacity(ps);
	//空间足够的处理
	ps->a[ps->size] = x;
	ps->size++;
}


//*****************************************************************************
void SeqListPopBack(SL* ps)//尾删
{
	//温柔处理方式
	if (ps->size > 0)
	{
		//ps->a[ps->size - 1] = 0;//最后一个数据置0,这句可以不要，因为就算置0，开辟的内存还在
		ps->size--;
	}
}

//#include <assert.h>
//void SeqListPopBack(SL* ps)//尾删
//{
//	//暴力处理方式
//	assert(ps->size > 0);
//	ps->size--;
//}



//**************************************************************************************
void SeqListPushFront(SL* ps, SLDataType x)//头插
{
	SeqlistCheckCapacity(ps);
	//把所有元素往后平移一个，把要插入的元素放到前面
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}


//*******************************************************************************
#include <assert.h>
void SeqListPopFront(SL* ps)//头删
{
	assert(ps->size > 0);
	//挪动数据
	int start = 1;
	while (start<ps->size)
	{
		ps->a[start - 1] = ps->a[start];//从下标为1的元素开始
		start++;
	}
	ps->size--;
}



//********************************************************************
int SeqListFind(SL* ps, SLDataType x)//找到了返回x位置下标，没有找到返回-1
{
	//多次出现x的情况也可以解决
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}


//*******************************************************************************
void SeqListInsert(SL* ps, int pos, SLDataType x)//在指定下标位置插入
{
	//温柔处理方式
	if (pos > ps->size || pos < 0)
	{
		printf("pos invalid\n");
		return;
	}
	//暴力处理方式
	assert(pos <= ps->size && pos >= 0);
	//插入先判断是否要增容
	SeqlistCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

//************************************************************************
//头插尾插改造
void SeqListPushFront2(SL* ps, SLDataType x)//头插
{
	SeqListInsert(ps, 0, x);
}

void SeqListPushBack2(SL* ps, SLDataType x)//尾插
{
	SeqListInsert(ps, ps->size, x);
}


//*********************************************************************************
void SeqListErase(SL* ps, int pos)//删除任意位置元素
{
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}


//************************************************************************
//头删尾删改造
void SeqListPopFront2(SL* ps)//头删
{
	SeqListErase(ps, 0);
}

void SeqListPopBack2(SL* ps)//尾删
{
	SeqListErase(ps, ps->size-1);
}

void DestoryContact(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
}

