#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

//��ӡ
void SLTPrint(SLTNode* phead)
{
	//assert(phead);
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}
//��ȡ�½ڵ�
SLTNode* BuyNewNode(SLTDataType x)
{
	SLTNode* pnewnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (pnewnode == NULL)
	{
		assert(0);
		return NULL;
	}
	pnewnode->data = x;
	pnewnode->next = NULL;
	return pnewnode;

}
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* pnewnode = BuyNewNode(x);
	if (*pphead == NULL)
	{
		*pphead = pnewnode;
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != NULL)
		{
			pcur = pcur->next;
		}
		pcur->next = pnewnode;
	}
}
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* pnewnode = BuyNewNode(x);
	if (*pphead == NULL)
	{
		*pphead = pnewnode;
	}
	else
	{
		pnewnode->next = *pphead;
		*pphead = pnewnode;
	}
}
//βɾ
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	//����Ϊ��
	if (*pphead == NULL)
	{
		return;
	}
	//����ֻ��һ���ڵ�
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//�����ж���ڵ�
	else
	{
		while (pcur->next->next != NULL)
		{
			pcur = pcur->next;
		}
		free(pcur->next);
		pcur->next = NULL;
	}
}
//ͷɾ
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	if (pcur == NULL)
	{
		return;
	}
	else
	{
		*pphead = pcur->next;
		free(pcur);
	}
}
//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	assert(phead);
	SLTNode* pcur = phead;
	/*while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}*/
	//û�ҵ�
	return NULL;
}
//��posλ��֮�����x
void SLTInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* pnewnode = BuyNewNode(x);
	pnewnode->next = pos->next;
	pos->next = pnewnode;

}
//ɾ��posλ��֮��Ľڵ�
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos);
	SLTNode* pcur = pos->next;
	//pos֮��û�нڵ�
	if (pcur == NULL)
	{
		return;
	}
	//pos֮���нڵ�
	else
	{
		pos->next = pcur->next;
		free(pcur);
	}
}
//ɾ��posλ�õĽڵ�
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);
	if(pos==*pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pcur->next = pos->next;
		free(pos);
	}
}
//��posλ��֮ǰ����x
void SLTInsertBefore(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);//����Ϊ��
	SLTNode* pnewnode = BuyNewNode(x);
	//posΪͷ�ڵ�
	if (*pphead == pos)
	{
	/*	pnewnode->next = *pphead;
		*pphead = pnewnode;*/
		SLTPushFront(pphead, x);
	}
	//pos��Ϊͷ���
	else
	{
		SLTNode* pcur = *pphead;
		while (pcur->next != pos)
		{
			pcur = pcur->next;
		}
		pnewnode->next = pos;
		pcur->next = pnewnode;
	}
}
//����
void SLTDestroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		*pphead = pcur->next;
		free(pcur);
		pcur = *pphead;
	}
}