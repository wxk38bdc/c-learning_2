#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SeqList.h"
void menu()
{
	printf("*****************通讯录***************\n");
	printf("***** 1.添加联系人   2.删除联系人*****\n");
	printf("***** 3.查找联系人   4.修改联系人*****\n");
	printf("***** 5.查看联系人   0.退出      *****\n");
	printf("**************************************\n");
}
//初始化
void ContactInit(Contact* pcon)
{
	SLInit(pcon);
}
//销毁
void ContactDestroy(Contact* pcon)
{
	SLDestory(pcon);
}
//增加
void ContactAdd(Contact* pcon)
{
	//创建联系人结构体变量
	Info info;

	//初始化
	printf("请输入姓名：\n");
	scanf("%s", info.name);
	printf("请输入年龄：\n");
	scanf("%d", &info.age);
	printf("请输入性别：\n");
	scanf("%s", info.gender);
	printf("请输入电话：\n");
	scanf("%s", info.tel);
	printf("请输入地址：\n");
	scanf("%s", info.addr);

	//将结构体变量尾插到顺序表中
	SLPushBack(pcon, info);
}
//删除
void ContactDel(Contact* pcon)
{
	printf("请输入要删除的姓名：\n");
	char name[NAME_MAX] = { 0 };
	scanf("%s", name);
	//1.查找要删除的元素下标
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("要删除的联系人不存在\n");
		return;
	}
	//2.删除元素
	SLErase(pcon, pos);
	printf("删除成功\n");
}
//查找
int FindByName(Contact*pcon, char name[NAME_MAX])
{
	//遍历顺序表，查找姓名为name的联系人
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
	//按照姓名查找
	//1.输入要查找的姓名
	char name[NAME_MAX] = { 0 };
	printf("请输入要查找的姓名：\n");
	scanf("%s", name);
	//2.查找姓名为name的联系人
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
		return;
	}
	//3.打印联系人信息
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf(" %-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
		pcon->arr[pos].name,
		pcon->arr[pos].age,
		pcon->arr[pos].gender,
		pcon->arr[pos].tel,
		pcon->arr[pos].addr);

}
//修改
void ContactModify(Contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	printf("请输入要修改的姓名：\n");
	scanf("%s", name);
	//1.查找要修改的元素下标
	int pos = FindByName(pcon, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	//2.修改元素
	Info* pInfo = &pcon->arr[pos];
	printf("请输入姓名：\n");
	scanf("%s", pInfo->name);
	printf("请输入年龄：\n");
	scanf("%d", &pInfo->age);
	printf("请输入性别：\n");
	scanf("%s", pInfo->gender);
	printf("请输入电话：\n");
	scanf("%s", pInfo->tel);
	printf("请输入地址：\n");
	scanf("%s", pInfo->addr);

	printf("修改成功\n");
}
//展示
void ContactShow(Contact* pcon)
{
	//打印表头
	printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
	//遍历顺序表中的每个元素，打印每个元素的值
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