#pragma once
#define NAME_MAX 100
#define SEX_MAX 8
#define TEL_MAX 12
#define ADDR_MAX 100

typedef struct SListNode contact;
//用户数据结构体
typedef struct PersonInfo {
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}PeoInfo;

void LoadContact(contact** con);//加载通讯录
void InitContact(contact** con);//初始化通讯录
void AddContact(contact** con);//添加联系人
void ShowContact(contact* con);//显示联系人
void DelContact(contact** con);//删除联系人
contact* FindByName(contact* con, char name[]);//按姓名查找联系人
void FindContact(contact* con);//查找联系人
void ModifyContact(contact* con);//修改联系人
void DestroyContact(contact** con);//销毁通讯录