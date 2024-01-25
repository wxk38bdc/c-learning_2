#pragma once
#define NAME_MAX 100
#define SEX_MAX 8
#define TEL_MAX 12
#define ADDR_MAX 100

typedef struct SListNode contact;
//�û����ݽṹ��
typedef struct PersonInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

void LoadContact(contact** con);//����ͨѶ¼
void InitContact(contact** con);//��ʼ��ͨѶ¼
void AddContact(contact** con);//�����ϵ��
void ShowContact(contact* con);//��ʾ��ϵ��
void DelContact(contact** con);//ɾ����ϵ��
contact* FindByName(contact* con, char name[]);//������������ϵ��
void FindContact(contact* con);//������ϵ��
void ModifyContact(contact* con);//�޸���ϵ��
void DestroyContact(contact** con);//����ͨѶ¼