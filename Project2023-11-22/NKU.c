#define _CRT_SECURE_NO_WARNINGS 1
////ר��ѧУ��ϰʱдC����
//// T401377 ½���Ͻ��ķ���
//#include <stdio.h>
////˼·���Ա���תǰ������꣬�ҵ��任��ʽ
//void shunshizhen(int matrix[][100], int x, int y, int r)
//{
//    int temp[100 * 100];
//    int n = sizeof(matrix) / sizeof(matrix[0]);
//
//    int k = 0;
//    for (int i = x - 1; i < x + r - 1; i++) 
//    {
//        for (int j = y - 1; j < y + r - 1; j++) 
//        {
//            temp[k++] = matrix[i][j];
//        }
//    }
//
//    k = 0;
//    for (int i = 0; i < r; i++) 
//    {
//        for (int j = 0; j < r; j++) 
//        {
//            matrix[x - 1 + j][y - 1 + r - 1 - i] = temp[i * r + j];
//        }
//    }
//}
//
//void nishizhen(int matrix[][100], int x, int y, int r) {
//    int temp[100 * 100];
//    int n = sizeof(matrix) / sizeof(matrix[0]);
//
//    int k = 0;
//    for (int i = x - 1; i < x + r - 1; i++) {
//        for (int j = y - 1; j < y + r - 1; j++) {
//            temp[k++] = matrix[i][j];
//        }
//    }
//
//    k = 0;
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < r; j++) {
//            matrix[x - 1 + r - 1 - j][y - 1 + i] = temp[i * r + j];
//        }
//    }
//}
//
//int main() 
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int matrix[100][100];
//    // ��ʼ������
//    int num = 1;
//    for (int i = 0; i < n; i++) 
//    {
//        for (int j = 0; j < n; j++) 
//        {
//            matrix[i][j] = num;
//            num++;
//        }
//    }
//    // ��ת����
//    while(m--)
//    {
//        int x, y, r, z;
//        scanf("%d %d %d %d", &x, &y, &r, &z);
//        if (z == 0) 
//        {
//            shunshizhen(matrix, x, y, r);
//        }
//        else if (z == 1)
//        {
//            nishizhen(matrix, x, y, r);
//        }
//    }
//    // �������
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++) 
//        {
//            printf("%d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <ctype.h>
////2022��ĩ������1
//int main()
//{
//	char arr1[50] = { 0 };
//	scanf("%s", arr1);
//	int len = strlen(arr1);
//	char arr2[50] = { 0 };
//	int j = 0;
//	for (int i = 0; i < len; i++)
//	{
//		if (isalpha(arr1[i]))
//		{
//			arr2[j] = toupper(arr1[i]);
//			j++;
//		}
//		else
//		{
//			arr2[j] = ' ';
//			j++;
//		}
//	}
//	char* arr3;
//	arr3 = strtok(arr2, " ");
//	while (arr3 != NULL)
//	{
//		printf("%s ", arr3);
//		arr3 = strtok(NULL, " ");
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
////2022��ĩ������2
//int main()
//{
//	char arr_former[50][50] = { 0 };
//	int arr_key[50][50] = { 0 };
//	char arr_result[50][50] = { 0 };
//	int m = 0, n = 0;
//	scanf("%d %d", &m, &n);
//	int i = 0, j = 0;
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf(" %c", &arr_former[i][j]);
//		}
//	}
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &arr_key[i][j]);
//		}
//	}
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			if (arr_former[i][j] + arr_key[i][j] <= 'Z')
//			{
//				arr_result[i][j] = arr_former[i][j] + arr_key[i][j];
//			}
//			else
//			{
//				arr_result[i][j] = arr_former[i][j] + arr_key[i][j] - 26;
//				while(arr_result[i][j] > 'Z')
//				{ 
//					arr_result[i][j] = arr_result[i][j] - 26;
//				}
//			}
//		}
//	}
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%c ", arr_result[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
////2022��ĩ������3
//struct player {
//	char name[20];
//	int score[7];//ÿλ��ί����
//	int result;//ȥ����߷ֺ���ͷֺ��5�������ܷ�
//}py[100];
//int get_max(int arr[], int n)
//{
//	int max = arr[0];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//int get_min(int arr[], int n)
//{
//	int min = arr[0];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//	return min;
//}
//int cmp_py_by_result(const void* e1, const void* e2)
//{
//	struct player* p1 = (struct player*)e1;
//	struct player* p2 = (struct player*)e2;
//	if (p1->result > p2->result)
//	{
//		return -1;
//	}
//	else if (p1->result < p2->result)
//	{
//		return 1;
//	}
//	else
//	{
//		return strcmp(p1->name, p2->name);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", py[i].name);
//		for (j = 0; j < 7; j++)
//		{
//			scanf("%d", &py[i].score[j]);
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		int max = get_max(py[i].score, 7);
//		int min = get_min(py[i].score, 7);
//		int sum = 0;
//		for (j = 0; j < 7; j++)
//		{
//			sum += py[i].score[j];
//		}
//		py[i].result = sum - max - min;
//	}
//	int sz = sizeof(py) / sizeof(py[0]);
//	qsort(py, sz, sizeof(py[0]), cmp_py_by_result);
//	for (i = 0; i < n; i++)
//	{
//		printf("%s %d\n", py[i].name, py[i].result);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n == 1)
//	{
//		printf("+-+\n");
//		printf("+-+\n");
//	}
//	else
//	{
//		printf("+");
//		for (int i = 0; i < 2 * n - 1; i++)
//		{
//			printf("-");
//		}
//		printf("+\n");
//
//		for (int i = 0; i < n-1; i++)
//		{
//			printf("|");
//			for (int j = 0; j < 2 * n - 1; j++)
//			{
//				printf(" ");
//			}
//			printf("|\n");
//		}
//
//		printf("+");
//		for (int i = 0; i < 2 * n - 1; i++)
//		{
//			printf("-");
//		}
//		printf("+\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int get_max(int arr[], int n)
//{
//	int max = arr[0];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//int main()
//{
//	char arr[1001]= { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	int i = 0;
//	int ret[1000] = { 0 };
//	for (i = 0; i < len; i++)
//	{
//		int j = 0;
//		for (j = i; j < len; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				ret[i]++;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	int max = get_max(ret, 1000);
//	printf("%d", max);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
////�ַ����༭���룺��A��B��2���ַ�����Ҫ�����ٵ��ַ��������ַ���Aת��Ϊ�ַ���B��
////������˵���ַ����������� (1)ɾ��һ���ַ��� (2)����һ���ַ��� (3)��һ���ַ���Ϊ��һ���ַ��� 
////���ַ���A�任Ϊ�ַ���B���õ������ַ���������Ϊ�ַ���A��B�ı༭���룬��Ϊd(A,B)��
////�����һ����Ч�㷨�����θ���2���ַ���A��B��������ǵı༭����d(A,B)��
////ע�⵽����A,B���ַ���������2000���ַ������޿ո񣬲��������ַ���Сд
//int main()
//{
//	char arr1[2001] = { 0 };
//	char arr2[2001] = { 0 };
//	scanf("%s", arr1);
//	scanf("%s", arr2);
//	int len1 = strlen(arr1);
//	int len2 = strlen(arr2);
//	if(len1==len2)
//	{
//		int i = 0;
//		int count = 0;
//		for (i = 0; i < len1; i++)
//		{
//			if (arr1[i] != arr2[i])
//			{
//				count++;
//			}
//		}
//		printf("%d", count);
//	}
//	
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int MIN(int a, int b, int c) {
//    int min = a;
//    if (b < min) {
//        min = b;
//    }
//    if (c < min) {
//        min = c;
//    }
//    return min;
//}
//
//int minEditDistance(char* str1, char* str2) {
//    int len1 = strlen(str1);
//    int len2 = strlen(str2);
//
//    // ��̬�����ڴ�
//    int** dp = (int**)malloc((len1 + 1) * sizeof(int*));
//    for (int i = 0; i <= len1; i++) {
//        dp[i] = (int*)malloc((len2 + 1) * sizeof(int));
//    }
//
//    for (int i = 0; i <= len1; i++) {
//        for (int j = 0; j <= len2; j++) {
//            if (i == 0) {
//                dp[i][j] = j;
//            }
//            else if (j == 0) {
//                dp[i][j] = i;
//            }
//            else if (str1[i - 1] == str2[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];
//            }
//            else {
//                dp[i][j] = 1 + MIN(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
//            }
//        }
//    }
//
//    int result = dp[len1][len2];
//
//    // �ͷŶ�̬������ڴ�
//    for (int i = 0; i <= len1; i++) {
//        free(dp[i]);
//    }
//    free(dp);
//
//    return result;
//}
//
//int main() {
//    char arr1[2001] = { 0 };
//    char arr2[2001] = { 0 };
//    scanf("%s", arr1);
//    scanf("%s", arr2);
//
//    int result = minEditDistance(arr1, arr2);
//    printf("%d", result);
//
//    return 0;
//}

//#include <stdio.h>
//
//void print(int arr[]) {
//    for (int i = 1; i <= 12; i++) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//int main() {
//    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
//    int k;
//    scanf("%d", &k);
//    int i = 0;
//    int live = 12;
//    int count = 0;
//
//    while (live > 1) {
//        if (i == 12) {
//            i = 0;
//        }
//        i++;
//        if (arr[i] == 0) {
//            continue;
//        }
//        count++;
//        if (count == k) {
//            arr[i] = 0;
//            print(arr);
//            live--;
//            count = 0;
//        }
//        
//    }
//
//    for (int i = 1; i <= 12; i++) {
//        if (arr[i] != 0) {
//            printf("%d", arr[i]);
//            break;
//        }
//    }
//
//    return 0;
//}


