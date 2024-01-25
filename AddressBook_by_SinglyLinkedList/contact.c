#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//��ʼ��ͨѶ¼
void LoadContact(contact** con)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//��ȡ�ļ�����
	PeoInfo info;
	while (fread(&info, sizeof(PeoInfo), 1, pf))
	{
		SLTPushBack(con, info);
	}
	printf("��ʼ���ɹ�!\n");
}
void InitContact(contact** con)
{
	LoadContact(con);
}
//�����ϵ�ˣ�β�壩
void AddContact(contact** con)
{
	PeoInfo info;
	printf("������������");
	scanf("%s", info.name);
	printf("�������Ա�");
	scanf("%s", info.sex);
	printf("���������䣺");
	scanf("%d", &info.age);
	printf("������绰��");
	scanf("%s", info.tel);
	printf("�������ַ��");
	scanf("%s", info.addr);

	SLTPushBack(con, info);
	printf("��ӳɹ�!\n");
}
//������������ϵ��
contact* FindByName(contact* con, char name[])
{
	contact* cur = con;
	while (cur)
	{
		if (strcmp(cur->data.name, name) == 0)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//ɾ����ϵ��
void DelContact(contact** con)
{
	char name[NAME_MAX] = { 0 };
	printf("������Ҫɾ������ϵ��������");
	scanf("%s", name);
	contact* pos = FindByName(*con, name);
	if (pos == NULL)
	{
		printf("Ҫɾ������ϵ�˲�����!\n");
		return;
	}
	SLTErase(con, pos);
	printf("ɾ���ɹ�!\n");

}
//��ʾ��ϵ��
void ShowContact(contact* con)
{
	contact* cur = con;
	while (cur)
	{
		printf("������%s �Ա�%s ���䣺%d �绰��%s ��ַ��%s\n", cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);
		cur = cur->next;
	}
}
//������ϵ��
void FindContact(contact* con)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ���ϵ��������");
	scanf("%s", name);
	contact* cur = FindByName(con, name);
	if (cur == NULL)
	{
		printf("Ҫ���ҵ���ϵ�˲�����!\n");
		return;
	}
	printf("���ҳɹ�����Ҫ���ҵ���Ϣ����\n");
	printf("������%s �Ա�%s ���䣺%d �绰��%s ��ַ��%s\n", cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);

}
//�޸���ϵ��
void ModifyContact(contact* con)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ���ϵ��������");
	scanf("%s", name);
	contact* cur = FindByName(con, name);
	if (cur == NULL)
	{
		printf("Ҫ���ҵ���ϵ�˲�����!\n");
		return;
	}
	printf("������������");
	scanf("%s", cur->data.name);
	printf("�������Ա�");
	scanf("%s", cur->data.sex);
	printf("���������䣺");
	scanf("%d", &cur->data.age);
	printf("������绰��");
	scanf("%s", cur->data.tel);
	printf("�������ַ��");
	scanf("%s", cur->data.addr);
	printf("�޸ĳɹ�!\n");
}
//������ϵ��
void SaveContact(contact* con)
{
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	contact* cur = con;
	while (cur)
	{
		fwrite(&cur->data, sizeof(PeoInfo), 1, pf);
		cur = cur->next;
	}
	fclose(pf);
	printf("����ɹ�!\n");
}
//����ͨѶ¼
void DestroyContact(contact** con)
{
	SaveContact(*con);
	SLTDestroy(con);
	printf("ͨѶ¼������!\n");
}