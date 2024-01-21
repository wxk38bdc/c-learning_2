#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
//初始化
void SLInit(SL* ps)
{
	assert(ps);
	ps->arr = (SLDataType*)malloc(sizeof(SLDataType)* 3);
	if (ps->arr == NULL)
	{
		assert(0);
		return;
	}
	ps->size = 0;
	ps->capacity = 3;
}
//销毁
void SLDestory(SL* ps)
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//检查容量
void SLCheckCapacity(SL* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, sizeof(SLDataType)*ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			return;
		}
		ps->arr = tmp;
		ps->capacity *= 2;
	}
}
////打印
//void SLPrint(SL* ps)
//{
//	assert(ps);
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//}
//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		return;
	}
	ps->size--;
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCheckCapacity(ps);
	for (int i = ps->size - 1; i >= 0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps->size++;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		return;
	}
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//插入
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//删除
void SLErase(SL* ps, size_t pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	if (ps->size == 0)
	{
		return;
	}
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;

}