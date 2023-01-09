#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
//��ӡ˳���������
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//���ٿռ�
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SeaListInit(SL* ps)//��ʼ��
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

//����
void SeqlistCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		//�����0���͸��ĸ��ռ䣬���capacity���˾�����n��������Լ�����
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		{
			//����ռ俪��ʧ��
			if (tmp == NULL)
			{
				printf("realloc fail\n");
				exit(-1);
			}
			//�ռ俪�ٳɹ�
			ps->a = tmp;
			ps->capacity = newcapacity;
		}
	}
}

//********************************************************************
void SeqListPushBack(SL* ps, SLDataType x)//β��
{
	SeqlistCheckCapacity(ps);
	//�ռ��㹻�Ĵ���
	ps->a[ps->size] = x;
	ps->size++;
}


//*****************************************************************************
void SeqListPopBack(SL* ps)//βɾ
{
	//���ᴦ��ʽ
	if (ps->size > 0)
	{
		//ps->a[ps->size - 1] = 0;//���һ��������0,�����Բ�Ҫ����Ϊ������0�����ٵ��ڴ滹��
		ps->size--;
	}
}

//#include <assert.h>
//void SeqListPopBack(SL* ps)//βɾ
//{
//	//��������ʽ
//	assert(ps->size > 0);
//	ps->size--;
//}



//**************************************************************************************
void SeqListPushFront(SL* ps, SLDataType x)//ͷ��
{
	SeqlistCheckCapacity(ps);
	//������Ԫ������ƽ��һ������Ҫ�����Ԫ�طŵ�ǰ��
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
void SeqListPopFront(SL* ps)//ͷɾ
{
	assert(ps->size > 0);
	//Ų������
	int start = 1;
	while (start<ps->size)
	{
		ps->a[start - 1] = ps->a[start];//���±�Ϊ1��Ԫ�ؿ�ʼ
		start++;
	}
	ps->size--;
}



//********************************************************************
int SeqListFind(SL* ps, SLDataType x)//�ҵ��˷���xλ���±꣬û���ҵ�����-1
{
	//��γ���x�����Ҳ���Խ��
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
void SeqListInsert(SL* ps, int pos, SLDataType x)//��ָ���±�λ�ò���
{
	//���ᴦ��ʽ
	if (pos > ps->size || pos < 0)
	{
		printf("pos invalid\n");
		return;
	}
	//��������ʽ
	assert(pos <= ps->size && pos >= 0);
	//�������ж��Ƿ�Ҫ����
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
//ͷ��β�����
void SeqListPushFront2(SL* ps, SLDataType x)//ͷ��
{
	SeqListInsert(ps, 0, x);
}

void SeqListPushBack2(SL* ps, SLDataType x)//β��
{
	SeqListInsert(ps, ps->size, x);
}


//*********************************************************************************
void SeqListErase(SL* ps, int pos)//ɾ������λ��Ԫ��
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
//ͷɾβɾ����
void SeqListPopFront2(SL* ps)//ͷɾ
{
	SeqListErase(ps, 0);
}

void SeqListPopBack2(SL* ps)//βɾ
{
	SeqListErase(ps, ps->size-1);
}

void DestoryContact(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
}

