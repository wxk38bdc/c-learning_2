#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//初始化通讯录
void LoadContact(contact** con)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("fopen");
		return;
	}
	//读取文件数据
	PeoInfo info;
	while (fread(&info, sizeof(PeoInfo), 1, pf))
	{
		SLTPushBack(con, info);
	}
	printf("初始化成功!\n");
}
void InitContact(contact** con)
{
	LoadContact(con);
}
//添加联系人（尾插）
void AddContact(contact** con)
{
	PeoInfo info;
	printf("请输入姓名：");
	scanf("%s", info.name);
	printf("请输入性别：");
	scanf("%s", info.sex);
	printf("请输入年龄：");
	scanf("%d", &info.age);
	printf("请输入电话：");
	scanf("%s", info.tel);
	printf("请输入地址：");
	scanf("%s", info.addr);

	SLTPushBack(con, info);
	printf("添加成功!\n");
}
//按姓名查找联系人
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
//删除联系人
void DelContact(contact** con)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要删除的联系人姓名：");
	scanf("%s", name);
	contact* pos = FindByName(*con, name);
	if (pos == NULL)
	{
		printf("要删除的联系人不存在!\n");
		return;
	}
	SLTErase(con, pos);
	printf("删除成功!\n");

}
//显示联系人
void ShowContact(contact* con)
{
	contact* cur = con;
	while (cur)
	{
		printf("姓名：%s 性别：%s 年龄：%d 电话：%s 地址：%s\n", cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);
		cur = cur->next;
	}
}
//查找联系人
void FindContact(contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的联系人姓名：");
	scanf("%s", name);
	contact* cur = FindByName(con, name);
	if (cur == NULL)
	{
		printf("要查找的联系人不存在!\n");
		return;
	}
	printf("查找成功！您要查找的信息如下\n");
	printf("姓名：%s 性别：%s 年龄：%d 电话：%s 地址：%s\n", cur->data.name, cur->data.sex, cur->data.age, cur->data.tel, cur->data.addr);

}
//修改联系人
void ModifyContact(contact* con)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名：");
	scanf("%s", name);
	contact* cur = FindByName(con, name);
	if (cur == NULL)
	{
		printf("要查找的联系人不存在!\n");
		return;
	}
	printf("请输入姓名：");
	scanf("%s", cur->data.name);
	printf("请输入性别：");
	scanf("%s", cur->data.sex);
	printf("请输入年龄：");
	scanf("%d", &cur->data.age);
	printf("请输入电话：");
	scanf("%s", cur->data.tel);
	printf("请输入地址：");
	scanf("%s", cur->data.addr);
	printf("修改成功!\n");
}
//保存联系人
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
	printf("保存成功!\n");
}
//销毁通讯录
void DestroyContact(contact** con)
{
	SaveContact(*con);
	SLTDestroy(con);
	printf("通讯录已销毁!\n");
}