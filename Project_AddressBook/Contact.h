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

//前置声明
typedef struct SeqList Contact;

//菜单栏
void menu();
//初始化
void ContactInit(Contact* pcon);
//销毁
void ContactDestroy(Contact* pcon);
//增加
void ContactAdd(Contact* pcon);
//删除
void ContactDel(Contact* pcon);
//查找
void ContactFind(Contact* pcon);
int FindByName(Contact* pcon, char name[NAME_MAX]);
//修改
void ContactModify(Contact* pcon);
//展示
void ContactShow(Contact* pcon);