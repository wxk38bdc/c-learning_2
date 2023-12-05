#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
void SeqListInit(SL* ps)//��ʼ��
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);

	if(ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

void SeqListDestory(SL* ps)//����
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;//��ֹҰָ��
	ps->size = 0;
	ps->capacity = 0;
}
void SeqListPushBack(SL* ps, SLDataType x)//β��
{
	assert(ps);
	//�������
	SeqlistCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPrint(SL* ps)//��ӡ
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqlistCheckCapacity(SL* ps)//�������
{
	assert(ps);
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * ps->capacity * 2);
		if (ps->a == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}

}

void SeqListPopBack(SL* ps)//βɾ
{
	assert(ps);
	if (ps->size == 0)
	{
		return;
	}
	ps->size--;
}

void SeqListPushFront(SL* ps, SLDataType x)//ͷ��
{
	assert(ps);
	SeqlistCheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)//ͷɾ
{
	assert(ps);
	if (ps->size == 0)
	{
		return;
	}
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

void SeqListInsert(SL* ps, int pos, SLDataType x)//����λ�ò���
{
	assert(ps);
	SeqlistCheckCapacity(ps);
	for (int i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)//����λ��ɾ��
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	if (ps->size == 0)
	{
		return;
	}
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)//����Ԫ���±�
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}