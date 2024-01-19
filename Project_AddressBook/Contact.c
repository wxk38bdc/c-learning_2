#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"
void menu()
{
	printf("*****************ͨѶ¼***************\n");
	printf("***** 1.�����ϵ��   2.ɾ����ϵ��*****\n");
	printf("***** 3.������ϵ��   4.�޸���ϵ��*****\n");
	printf("***** 5.�鿴��ϵ��   0.�˳�      *****\n");
	printf("**************************************\n");
}
//��ʼ��
void ContactInit(Contact* pcon)
{
	SLInit(pcon);
}
//����
void ContactDestroy(Contact* pcon)
{
	SLDestory(pcon);
}
//����
void ContactAdd(Contact* pcon)
{
	//������ϵ�˽ṹ�����
	Info info;

	//��ʼ��
	printf("������������\n");
	scanf("%s", info.name);
	printf("���������䣺\n");
	scanf("%d", &info.age);
	printf("�������Ա�\n");
	scanf("%s", info.gender);
	printf("������绰��\n");
	scanf("%s", info.tel);
	printf("�������ַ��\n");
	scanf("%s", info.addr);

	//���ṹ�����β�嵽˳�����
	SLPushBack(pcon, info);
}
//ɾ��
void ContactDel(Contact* pcon)
{
	printf("������Ҫɾ����������\n");
	char name[NAME_MAX] = { 0 };
	scanf("%s", name);
	//1.����Ҫɾ����Ԫ���±�
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
		return;
	}
	//2.ɾ��Ԫ��
	SLErase(pcon, pos);
	printf("ɾ���ɹ�\n");
}
//����
int FindByName(Contact*pcon, char name[NAME_MAX])
{
	//����˳�����������Ϊname����ϵ��
	int i = 0;
	for (i = 0; i < pcon->size; i++)
	{
		if (strcmp(pcon->arr[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void ContactFind(Contact* pcon)
{
	//������������
	//1.����Ҫ���ҵ�����
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���ҵ�������\n");
	scanf("%s", name);
	//2.��������Ϊname����ϵ��
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
		return;
	}
	//3.��ӡ��ϵ����Ϣ
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf(" %-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
		pcon->arr[pos].name,
		pcon->arr[pos].age,
		pcon->arr[pos].gender,
		pcon->arr[pos].tel,
		pcon->arr[pos].addr);

}
//�޸�
void ContactModify(Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ�޸ĵ�������\n");
	scanf("%s", name);
	//1.����Ҫ�޸ĵ�Ԫ���±�
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}
	//2.�޸�Ԫ��
	Info* pInfo = &pcon->arr[pos];
	printf("������������\n");
	scanf("%s", pInfo->name);
	printf("���������䣺\n");
	scanf("%d", &pInfo->age);
	printf("�������Ա�\n");
	scanf("%s", pInfo->gender);
	printf("������绰��\n");
	scanf("%s", pInfo->tel);
	printf("�������ַ��\n");
	scanf("%s", pInfo->addr);

	printf("�޸ĳɹ�\n");
}
//չʾ
void ContactShow(Contact* pcon)
{
	//��ӡ��ͷ
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	//����˳����е�ÿ��Ԫ�أ���ӡÿ��Ԫ�ص�ֵ
	for (int i = 0; i < pcon->size; i++)
	{
		printf(" %-10s\t%-4d\t%-5s\t%-12s\t%-20s\n", 
			pcon->arr[i].name,
			pcon->arr[i].age,
			pcon->arr[i].gender,
			pcon->arr[i].tel,
			pcon->arr[i].addr);
	}
}