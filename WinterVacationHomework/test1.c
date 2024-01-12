#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
//DAY 1
// 
//int isLeapYear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};//∑«»ÚƒÍ
//int main()
//{
//	int year, month, day;
//	scanf("%d %d %d", &year, &month, &day);
//	if (isLeapYear(year))
//	{
//		months[1] = 29;
//	}
//	int dayIndex = 0;
//	for (int i = 0; i < month-1; i++)
//	{
//		dayIndex += months[i];
//	}
//	dayIndex += day;
//	printf("%d", dayIndex);
//	return 0;
//}

//DAY 2
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%d", strlen(s));
//	return 0;
//}
//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)return n;
//	n = n + i;
//	i++;
//	return f(n);
//}
//int main()
//{
//	printf("%d", f(1));
//	return 0;
//}
//int main()
//{
//	char a[14];
//	a = "HelloWorld";
//	printf(a);
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int num = n * (n - 1) + 1;
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d", num);
//		num += 2;
//		if (i != n)
//		{
//			printf("+");
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", 2 * n + 3 * n * (n - 1) / 2);
//	return 0;
//}

//DAY 3
//int i;
//void prt()
//{
//	for (i = 5; i < 8; i++)
//		printf("*");
//	printf("\t");
//}
//int main()
//{
//	for (i = 5; i < 8; i++)
//		prt();
//	return 0;
//}
//int main()
//{
//	int a = 3;
//	printf("%d\n", (a += a -= a * a));
//	return 0;
//}
//int main()
//{
//	int n;
//	int negativeNum = 0;
//	int positiveNum = 0;
//	double positiveNumSum = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		double num;
//		scanf("%lf", &num);
//		if (num < 0)
//		{
//			negativeNum++;
//		}
//		else if (num > 0)
//		{
//			positiveNum++;
//			positiveNumSum += num;
//		}
//	}
//	if (positiveNum == 0)
//		printf("%d %.1lf", negativeNum, 0);
//	else
//		printf("%d %.1lf", negativeNum, 1.0 * positiveNumSum / positiveNum);
//	return 0;
//}

//DAY 4
//int main()
//{
//	int n = 0;
//	char ch;
//	for (ch = getchar(); ch != '\n'; n++);//error
//	printf("%d", n);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	while (n--)
//	{
//		char str[101];
//		scanf("%s", str);
//		if(isdigit(str[0])||strlen(str)<8)
//		{
//			printf("NO\n");
//			continue;
//		}
//		int flag1 = 0, flag2 = 0, flag3 = 0;
//		for (int i = 0; i < strlen(str); i++)
//		{
//			if (isupper(str[i]))
//				flag1 = 1;
//			else if (islower(str[i]))
//				flag2 = 1;
//			else if (isdigit(str[i]))
//				flag3 = 1;
//		}
//		if (flag1 + flag2 + flag3 >= 2)
//			printf("YES\n");
//		else
//			printf("NO\n");
//	}
//	return 0;
//}

//DAY 5
//int main()
//{
//	int t = 0;
//	while (printf("*"))
//	{
//		t++;
//		if (t < 3)
//			break;
//	}
//	return 0;
//}

//DAY 6
//int times = 0;
//int main()
//{
//	for (int i = 0; i || i++ < 5;)
//		times++;
//	printf("%d", times);
//	return 0;
//}

//DAY 7
//int main()
//{
//
//	return 0;
//}