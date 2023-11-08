#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
////用递归将10进制转换为2进制
//void binary(int n)
//{
//	if (n > 1)
//	{
//		binary(n / 2);
//	}
//	printf("%d", n % 2);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	binary(n);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前:a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("交换后:a=%d b=%d", a, b);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int count = 0;
//    for (int i = 0; i < 32; i++)
//    {
//        if (n&(1<<i))
//        {
//            count++;
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	int odd_number[16] = { 0 };
//	int even_number[16] = { 0 };
//	int i = 0;
//	for (i = 0; i < 32; i += 2)
//	{
//		odd_number[i / 2] = (num >> i) & 1;
//	}
//	for (i = 1; i < 32; i += 2)
//	{
//		even_number[i / 2] = (num >> i) & 1;
//	}
//	printf("奇数位:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", even_number[i]);
//	}
//	printf("\n");
//	printf("偶数位:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", odd_number[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
////求两个整数二进制格式有多少个位不同
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	int count = 0;
//	int ab = a ^ b;
//	for (int i = 0; i <= 31; i++)
//	{
//		if (ab & (1 << i))
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}


//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct Stu s1={ "张三", 20, 90.0 };
//	struct Stu s2={ "李四", 21, 80.0 };
//	printf("姓名:%s 年龄:%d 成绩:%.2f\n", s1.name, s1.age, s1.score);
//	printf("姓名:%s 年龄:%d 成绩:%.2f\n", s2.name, s2.age, s2.score);
//	return 0;
//}

//#include<stdio.h>
//struct Stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//struct data
//{
//	int year;
//	int month;
//	int day;
//	struct Stu s;
//};
//int main()
//{
//	struct data d = { 2020, 10, 10, {"张三", 20, 90.0} };
//	printf("出生日期:%d年%d月%d日\n", d.year, d.month, d.day);
//	printf("姓名:%s 年龄:%d 成绩:%.2f\n", d.s.name, d.s.age, d.s.score);
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int**ppa = &pa;
//	**ppa = 20;
//	printf("%d\n", a);
//
//	return 0;
//}

//#include <stdio.h>
//int i;
//int main()
//{
//
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
//汉诺塔问题
//int hannuota(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 2 * hannuota(n - 1) + 1;
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = hannuota(n);
//	printf("%d", ret);
//	return 0;
//}

//#include<stdio.h>
////汉诺塔问题
//int count = 0;
//void move(char pos1, char pos2)
//{
//	printf("%c->%c ", pos1, pos2);
//	count++;
//}
//void hanoi(int n, char pos1, char pos2, char pos3)
//{
//	if (n == 1)
//	{
//		move(pos1, pos3);
//	}
//	else
//	{
//		hanoi(n - 1, pos1, pos3, pos2);
//		move(pos1, pos3);
//		hanoi(n - 1, pos2, pos1, pos3);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	hanoi(n, 'A', 'B', 'C');
//	printf("\n移动的总次数为:%d",count);
//	return 0;
//}

/*原理如下
这段代码解决的是经典的汉诺塔问题，该问题是一个递归问题，其核心思想是将 n 个盘子从一个起始柱子（通常称为 A）移动到目标柱子（通常称为 C），并借助辅助柱子（通常称为 B）。每个盘子都比它下面的盘子小，因此你不能把一个较大的盘子放在较小的盘子上。

以下是 hanoi 函数的运行原理：

如果 n 等于 1，表示只有一个盘子，那么直接将这个盘子从起始柱子 pos1 移动到目标柱子 pos3，并打印出移动的过程（使用 move 函数）。

如果 n 大于 1，那么问题被分解为三个步骤：

首先，将上面的 n-1 个盘子从起始柱子 pos1 移动到辅助柱子 pos2，利用目标柱子 pos3 作为辅助。
接下来，将最大的盘子（第 n 个盘子）从起始柱子 pos1 移动到目标柱子 pos3，并打印出移动的过程。
最后，将之前移动到辅助柱子 pos2上的 n-1 个盘子从辅助柱子 pos2 移动到目标柱子 pos3，利用起始柱子 pos1 作为辅助。
这个递归过程将不断重复，直到所有的盘子都从起始柱子移动到目标柱子，符合汉诺塔的规则。这个算法确保了所有的盘子都按照正确的顺序从一个柱子移动到另一个柱子，同时打印出每一步的移动过程。

你可以通过调用 hanoi 函数来解决不同数量盘子的汉诺塔问题，传递起始柱子、辅助柱子和目标柱子的标识，代码会自动处理盘子的移动过程。
*/

#include<stdio.h>