#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//using namespace std;
//#include<cstdio>
//int main()
//{
//	int a = 5;
//	int b = 10;
//	int* pa = &a;
//	int* pb = &b;
//	printf("a=%d b=%d *pa=%d *pb=%d\n", a, b, *pa, *pb);
//	a = 1;
//	b = 2;
//	printf("a=%d b=%d *pa=%d *pb=%d\n", a, b, *pa, *pb);
//	return 0;
//}

//
//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cctype>
//
//void processstrings(char* str)
//{
//	int leadzero = 0;
//	int len = strlen(str);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (str[i] != '0')
//		{
//			break;
//		}
//		else {
//			leadzero++;
//		}
//	}
//
//	if (leadzero == len)
//	{
//		str[1] = '\0';
//	}
//
//	else if (leadzero > 0 && leadzero < len)
//	{
//		for (i = 0; i < len - leadzero; i++)
//		{
//			str[i] = str[i + leadzero];
//		}
//		str[len - leadzero] = '\0';
//	}
//}
//int comparestr(const void* e1, const void* e2)
//{
//	char* s1 = (char*)e1;
//	char* s2 = (char*)e2;
//	int len1 = strlen(s1);
//	int len2 = strlen(s2);
//	if (len1 != len2)
//	{
//		return len1 - len2;
//	}
//	else
//	{
//		return strcmp(s1, s2);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	while (n--)
//	{
//		char str[1001];
//		scanf("%s", str);
//		int len = strlen(str);
//		for (i = 0; i < len; i++)
//		{
//			if (isalpha(str[i]) || str[i] == '5')
//			{
//				str[i] = '#';
//			}
//		}
//		char* tmp = strtok(str, "#");
//		char arr[1000][1000];
//		int num = 0;
//		while (tmp)
//		{
//			strcpy(arr[num], tmp);
//			num++;
//			tmp = strtok(NULL, "#");
//		}
//		for (i = 0; i < num; i++)
//		{
//			processstrings(arr[i]);
//		}
//		qsort(arr, num, 1000, comparestr);
//		for (i = 0; i < num; i++)
//		{
//			if (i == 0 || strcmp(arr[i], arr[i - 1]) != 0)
//				printf("%s ", arr[i]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cctype>
//int compareint(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//int isprime(int n)
//{
//	if (n < 2)
//	{
//		return 0;
//	}
//	if (n == 2)
//	{
//		return 1;
//	}
//	int i = 0;
//	for (i = 2; i < n; i++)
//	{
//		if (n % 2 == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int arr[m][n];
//	int arrnew[m * n];
//	int i = 0, j = 0, k = 0;
//	for (i = 0; i < m * n; i++)
//	{
//		scanf("%d", &arrnew[i]);
//	}
//	qsort(arrnew, m * n, 4, compareint);
//	k = 0;
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			arr[i][j] = arrnew[k];
//			k++;
//			if (isprime(arr[i][j]))
//			{
//				printf("%d %d", i + 1, j + 1);
//				return 0;
//			}
//		}
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<cctype>
//typedef struct stu {
//	char name[30];
//	int score[7];
//	int total;
//}stu;
//int compareint(const void* e1, const void* e2)
//{
//	return *((int*)e1) - *((int*)e2);
//}
//int comparetotal(const void* e1, const void* e2)
//{
//	return -((stu*)e1)->total + ((stu*)e2)->total;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	stu s[n];
//	int i = 0, j = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", s[i].name);
//		for (j = 0; j < 7; j++)
//		{
//			scanf("%d", &s[i].score[j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		qsort(s[i].score, 7, 4, compareint);
//		s[i].total = s[i].score[1] + s[i].score[2] + s[i].score[3] + s[i].score[4] + s[i].score[5];
//	}
//	qsort(s, n, sizeof(stu), comparetotal);
//	for (i = 0; i < n; i++)
//	{
//		printf("%s %d\n", s[i].name, s[i].total);
//	}
//	return 0;
//}