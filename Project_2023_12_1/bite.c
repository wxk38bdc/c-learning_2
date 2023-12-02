#define _CRT_SECURE_NO_WARNINGS 1


//#pragma pack(1) // 将对齐数设置为1字节
//
//struct Example {
//    char a;    // 1字节
//    int b;     // 4字节
//    double c;  // 8字节
//};
//
//#pragma pack() // 恢复默认对齐数
//#include <stdio.h>
//int main()
//{
//	struct E1
//	{
//		char c1;
//		int i;
//		char c2;
//	};
//	struct E2
//	{
//		char c1;
//		char c2;
//		int i;
//	};
//	struct E3
//	{
//		double d;
//		char c;
//		int i;
//	};
//	struct E4
//	{
//		char c1;
//		struct E3 e3;
//		double d;
//	};
//	printf("%zd\n", sizeof(struct E1)); // 12
//	printf("%zd\n", sizeof(struct E2)); // 8
//	printf("%zd\n", sizeof(struct E3)); // 16
//	printf("%zd\n", sizeof(struct E4)); // 32
//	return 0;
//}

//#include<stdio.h>
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//struct Flags {
//	unsigned int flag1 : 1; // 占用1位
//	unsigned int flag2 : 2; // 占用2位
//	unsigned int flag3 : 3; // 占用3位
//};
//
//int main()
//{
//	printf("struct Flags 占用的空间是：%zd 字节\n",sizeof(struct Flags));
//	return 0;
//}

//#include <stdio.h>
////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合变量的定义
//	union Un un = { 0 };
//	//计算union变量的大小
//	printf("union Un 占用%d字节内存\n", sizeof(un));
//	return 0;
//}

////代码1
//#include <stdio.h>
////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合变量的定义
//	union Un un = { 0 };
//	// 下⾯输出的结果是一样的吗？
//	printf("%p\n", &(un.i));
//	printf("%p\n", &(un.c));
//	printf("%p\n", &un);
//	return 0;
//}

////代码2
//#include<stdio.h>
////联合类型的声明
//union Un
//{
//	char c;
//	int i;
//};
//int main()
//{
//	//联合变量的定义
//	union Un un = { 0 };
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//	return 0;
//}