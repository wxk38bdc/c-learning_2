#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
////�õݹ齫10����ת��Ϊ2����
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
//	printf("����ǰ:a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("������:a=%d b=%d", a, b);
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
//	printf("����λ:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", even_number[i]);
//	}
//	printf("\n");
//	printf("ż��λ:");
//	for (i = 15; i >= 0; i--)
//	{
//		printf("%d ", odd_number[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
////���������������Ƹ�ʽ�ж��ٸ�λ��ͬ
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
//	struct Stu s1={ "����", 20, 90.0 };
//	struct Stu s2={ "����", 21, 80.0 };
//	printf("����:%s ����:%d �ɼ�:%.2f\n", s1.name, s1.age, s1.score);
//	printf("����:%s ����:%d �ɼ�:%.2f\n", s2.name, s2.age, s2.score);
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
//	struct data d = { 2020, 10, 10, {"����", 20, 90.0} };
//	printf("��������:%d��%d��%d��\n", d.year, d.month, d.day);
//	printf("����:%s ����:%d �ɼ�:%.2f\n", d.s.name, d.s.age, d.s.score);
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
//��ŵ������
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
////��ŵ������
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
//	printf("\n�ƶ����ܴ���Ϊ:%d",count);
//	return 0;
//}

/*ԭ������
��δ��������Ǿ���ĺ�ŵ�����⣬��������һ���ݹ����⣬�����˼���ǽ� n �����Ӵ�һ����ʼ���ӣ�ͨ����Ϊ A���ƶ���Ŀ�����ӣ�ͨ����Ϊ C�����������������ӣ�ͨ����Ϊ B����ÿ�����Ӷ��������������С������㲻�ܰ�һ���ϴ�����ӷ��ڽ�С�������ϡ�

������ hanoi ����������ԭ��

��� n ���� 1����ʾֻ��һ�����ӣ���ôֱ�ӽ�������Ӵ���ʼ���� pos1 �ƶ���Ŀ������ pos3������ӡ���ƶ��Ĺ��̣�ʹ�� move ��������

��� n ���� 1����ô���ⱻ�ֽ�Ϊ�������裺

���ȣ�������� n-1 �����Ӵ���ʼ���� pos1 �ƶ����������� pos2������Ŀ������ pos3 ��Ϊ������
�����������������ӣ��� n �����ӣ�����ʼ���� pos1 �ƶ���Ŀ������ pos3������ӡ���ƶ��Ĺ��̡�
��󣬽�֮ǰ�ƶ����������� pos2�ϵ� n-1 �����ӴӸ������� pos2 �ƶ���Ŀ������ pos3��������ʼ���� pos1 ��Ϊ������
����ݹ���̽������ظ���ֱ�����е����Ӷ�����ʼ�����ƶ���Ŀ�����ӣ����Ϻ�ŵ���Ĺ�������㷨ȷ�������е����Ӷ�������ȷ��˳���һ�������ƶ�����һ�����ӣ�ͬʱ��ӡ��ÿһ�����ƶ����̡�

�����ͨ������ hanoi �����������ͬ�������ӵĺ�ŵ�����⣬������ʼ���ӡ��������Ӻ�Ŀ�����ӵı�ʶ��������Զ��������ӵ��ƶ����̡�
*/

#include<stdio.h>