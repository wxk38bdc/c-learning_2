#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#define NAME_MAX 100
#define GENDER_MAX 10
#define TEL_MAX 12
#define ADDR_MAX 100

typedef struct PersonInfo
{
	char name[NAME_MAX];
	int age;
	char gender[GENDER_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}Info;

//ǰ������
typedef struct SeqList Contact;

//�˵���
void menu();
//��ʼ��
void ContactInit(Contact* pcon);
//����
void ContactDestroy(Contact* pcon);
//����
void ContactAdd(Contact* pcon);
//ɾ��
void ContactDel(Contact* pcon);
//����
void ContactFind(Contact* pcon);
int FindByName(Contact* pcon, char name[NAME_MAX]);
//�޸�
void ContactModify(Contact* pcon);
//չʾ
void ContactShow(Contact* pcon);