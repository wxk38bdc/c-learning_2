#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main()
//{
//	char arr[20] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	for (int i = 0; i < len; i++)
//	{
//		if ((arr[i] - '0') % 2 == 0)
//		{
//			arr[i]='0';
//		}
//		else
//		{
//			arr[i] = '1';
//		}
//	}
//	printf("%d", atoi(arr));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	const int a = 10;
//	const int* const pa = &a;
//	int** ppa = &pa;
//	**ppa = 20;
//	printf("%d\n", a);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[10]= { 0 };
//	int arr2[10] = { 0 };
//	printf("%d", &arr[9] - &arr2[0]);
//	return 0;
//}

//#include<stdio.h>
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	int* p = test();
//	printf("hehe\n");
//	printf("%d\n",*p);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,3,4,5 };
//    short* p = (short*)arr;
//    int i = 0;
//    for (i = 0; i < 4; i++)
//    {
//        *(p + i) = 0;
//    }
//
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	unsigned long pulArray[] = { 6,7,8,9,10 };
//	unsigned long* pulPtr;
//	pulPtr = pulArray;
//	*(pulPtr + 3) += 3;
//	printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
////�ַ�������
//void reverse(char* arr, int len)
//{
//	char* left = arr;
//	char* right = arr + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[10001] = { 0 };
//	scanf("%[^\n]", arr);
//	reverse(arr, strlen(arr));
//	printf("%s", arr);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
////�ַ�������
//void left_move(char* arr, int k, int len)
//{
//	k %= len;
//	while (k--)
//	{
//		char tmp = *arr;
//		int i = 0;
//		for (i = 0; i < len - 1; i++)
//		{
//			*(arr + i) = *(arr + i + 1);
//		}
//		*(arr + len - 1) = tmp;
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	int k = 0;
//	scanf("%d", &k);
//	left_move(arr, k, len);
//	printf("%s", arr);
//	return 0;
//}

//#include <stdio.h>
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[100] = { 0 };
//	scanf("%s", arr);
//	int len = my_strlen(arr);
//	printf("%d", len);
//	return 0;
//}

//#include <stdio.h>
//void test(int arr[11])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d", arr[1]);
//}
//int main()
//{
//	int arr[10] = { 0 };
//
//	test(arr);
//	return 0;
//}

//#include<stdio.h>
//void bubbleSort(int arr[], int sz)
//{
//	int flag = 1;
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		flag = 1;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubbleSort(arr, 10);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}


//#include <stdio.h>
//void Print(int *arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(arr + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Print(arr, 10);
//	return 0;
//}

//#include <stdio.h>
//void sortOddBeforeEven(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left < right)
//	{
//		while (left < right && arr[left] % 2 == 1)
//		{
//			left++;
//		}
//		while (left < right && arr[right] % 2 == 0)
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	sortOddBeforeEven(arr, sz);//����������ǰ��ż���ں�
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double a, b, c, d;
//	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
//	printf("%.1lf", a * 0.2 + b * 0.1 + c * 0.2 + d * 0.5);
//	return 0;
//}

//#include<stdio.h>
//void bubbleSort(int* arr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		int j = 0;
//		int flag = 0;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[10]={ 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	bubbleSort(arr, 10);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	const char* str1 = "hello";
//	const char* str2 = "hello";
//	if (str1 == str2)
//	{
//		printf("same\n");
//	}
//	else
//	{
//		printf("not same\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
////�ж������ַ����Ƿ�����ת���Ի�Ϊ��ͬ�ַ���
//int if_move(char* s1, char* s2, int len)
//{
//	int len_tmp = len;
//	while (len_tmp--)
//	{
//		int i = 0;
//		int tmp = s1[0];
//		for (i = 0; i < len - 1; i++)
//		{
//			s1[i] = s1[i + 1];
//		}
//		s1[len - 1] = tmp;
//		if (strcmp(s1, s2) == 0)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	char s1[] = "AABCD";
//	char s2[] = "BCDAA";
//	int len1 = strlen(s1);
//	int ret1 = if_move(s1, s2, len1);
//
//	char s3[] = "abcd";
//	char s4[] = "ABCD";
//	int len3 = strlen(s3);
//	int ret2 = if_move(s3, s4, len3);
//
//	printf("ret1=%d\nret2=%d", ret1, ret2);
//	return 0;
//}


////��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
////Ҫ��ʱ�临�Ӷ�С��O(N);
////1 2 3 4 5
////2 3 4 5 6
////3 4 5 6 7
////4 5 6 7 8
////5 6 7 8 9
////ԭ�������Ͻǿ�ʼ���ң������ǰԪ�ش���target���������ƶ�һλ�������ǰԪ��С��target���������ƶ�һλ��
//#include <stdio.h>
//int searchInMatrix(int matrix[5][5], int target, int rows, int cols) 
//{
//    int row = 0;
//    int col = cols - 1;
//    while (row < rows && col >= 0) 
//    {
//        if (matrix[row][col] == target)
//            return 1;
//        else if (matrix[row][col] < target) 
//            row++;
//        else 
//            col--;
//    }
//    return 0;  
//}
//
//int main() {
//    int matrix[5][5] = { {1, 2, 3, 4, 5}, {2, 3, 4, 5, 6},{3, 4, 5, 6, 7},{4, 5, 6, 7, 8},{5, 6, 7, 8, 9} };
//    int target = 0;
//    scanf("%d", &target);
//    if (searchInMatrix(matrix, target, 5, 5))
//    {
//        printf("���� %d �ھ����С�\n", target);
//    }
//    else
//    {
//        printf("���� %d ���ھ����С�\n", target);
//    }
//    return 0;
//}

////�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
////����Ϊ4�����ɷ��Ĺ���:
////A˵�������ҡ�
////B˵����C��
////C˵����D��
////D˵��C�ں�˵
////��֪3����˵���滰��1����˵���Ǽٻ���
////�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//
//#include<stdio.h>
//int main()
//{
//	char killer = 0;
//	for (killer = 'A'; killer <= 'D'; killer++)
//	{
//		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
//		{
//			printf("������%c\n", killer);
//		}
//	}
//	return 0;
//}

////��ӡ�������
////ʾ��
////1
////11
////121
////1331
////...
//#include<stdio.h>
//int main()
//{
//	int arr[100][100] = { 0 };
//	int n = 0;//����
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for(j = 0; j <= i; j++)
//		{
//			if (j == 0 || j == i)
//			{
//				arr[i][j] = 1;
//			}
//			else
//			{
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
