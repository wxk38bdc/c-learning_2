#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[105];
//	scanf("%[^\n]", arr);
//	//ȥ��������
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if ((33<=arr[i]&&arr[i]<=47)||(58 <= arr[i] && arr[i] <= 64)|| (91 <= arr[i] && arr[i] <= 96)|| (123 <= arr[i] && arr[i] <= 126))
//		{
//			arr[i] = ' ';
//		}
//		i++;
//	}
//	//����д��ĸת��ΪСд��ĸ
//	i = 0;
//	while (arr[i] != '\0')
//	{
//		if (65 <= arr[i] && arr[i] <= 90)
//		{
//			arr[i] = arr[i] + 32;
//		}
//		i++;
//	}
//
//	//���ַ����ָ�Ϊ����,�������ά����,��ʹ��strtok����
//	char arr1[105][105];
//	int j = 0;
//	int k = 0;
//	int k_arr = 0;
//	while (arr[k_arr] != '\0')
//	{
//		if (arr[k_arr] != ' ')
//		{
//			arr1[j][k] = arr[k_arr];
//			k++;
//		}
//		else
//		{
//			arr1[j][k] = '\0';
//			j++;
//			k = 0;
//		}
//		k_arr++;
//	}
//	//���ÿ�����ʣ�ÿ���������ÿո��������ȥ�أ������ظ��ĵ��ʲ������
//	int count = 0;
//	for (int k = 0; k < j; k++)
//	{
//		//�����һ���ַ����ǿ��ַ�����������
//		if (arr1[k][0] == '\0')
//		{
//			continue;
//		}
//		int flag = 0;
//		for (int l = 0; l < k; l++)
//		{
//			if (strcmp(arr1[k], arr1[l]) == 0)
//			{
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0)
//		{
//			printf("%s ", arr1[k]);
//			count++;
//		}
//	}
//	//�������������ȥ�غ�
//	printf("\n%d", count);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h> // ���ڴ�Сдת��
//
//int main() {
//    char arr[105];
//    fgets(arr, sizeof(arr), stdin);
//
//    // ����д��ĸת��ΪСд��ĸ
//    for (int i = 0; arr[i]; i++) 
//    {
//        arr[i] = tolower(arr[i]);
//    }
//
//    // ��ʼ��һ������������Ψһ�ĵ���
//    int unique[50] = { 0 };
//    int count = 0;
//
//    // ���������Բ�ֺͼ�������
//    char* token = strtok(arr, " \t\n\r\f\v.!?,;:\"-()[]{}");
//    while (token != NULL) {
//        int found = 0;
//
//        // ��鵥���Ƿ�Ψһ
//        for (int i = 0; i < count; i++) {
//            if (strcmp(token, arr + unique[i]) == 0) {
//                found = 1;
//                break;
//            }
//        }
//
//        // ���������Ψһ�ģ����ӡ��
//        if (!found) {
//            if (count > 0) {
//                printf(" ");
//            }
//            printf("%s", token);
//            unique[count] = token - arr;
//            count++;
//        }
//
//        token = strtok(NULL, " \t\n\r\f\v.!?,;:\"-()[]{}");
//    }
//
//    // ��ӡ���ʼ���
//    printf("\n%d", count);
//
//    return 0;
//}

//#include <stdio.h>
////����������ݼ�����1��1�������ڼ���Ȼ����������������һ���·ݣ������ո�ʽ������µ�������
//int is_leap_year(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int dayofmonth(int year, int month)
//{
//	if (month == 2)
//	{
//		if (is_leap_year(year))
//		{
//			return 29;
//		}
//		else
//		{
//			return 28;
//		}
//	}
//	else if (month == 4 || month == 6 || month == 9 || month == 11)
//	{
//		return 30;
//	}
//	else
//	{
//		return 31;
//	}
//}
//int main()
//{
//	int year = 0;
//	int month = 0;
//	int week_day = 0;//1��1�������ڼ�
//	scanf("%d %d %d", &year, &week_day, &month);
//	//�ų����Ϸ�������
//	if (year < 0 || month < 1 || month>12 || week_day < 0 || week_day>6)
//	{
//		printf("ERROR");
//		return 1;
//	}
//
//	//������µĵ�һ���Ǹ���ĵڼ���
//	int month_first_day = 0;
//	for (int i = 1; i < month; i++)
//	{
//		month_first_day += dayofmonth(year, i);
//	}
//	//������µĵ�һ�������ڼ�
//	int month_first_week_day = (month_first_day + week_day) % 7;
//	//�������
//	int month_calender[6][7] = { 0 };
//	int day = 1;
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = month_first_week_day; j < 7; j++)
//		{
//			if (day <= dayofmonth(year, month))
//			{
//				month_calender[i][j] = day;
//				day++;
//			}
//		}
//		month_first_week_day = 0;
//	}
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 7; j++)
//		{
//			if (month_calender[i][j] == 0)
//			{
//				printf("    ");
//			}
//			else
//			{
//				printf("%4d", month_calender[i][j]);
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

//��2�������������Լ��
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int min = a < b ? a : b;
//	int max = a > b ? a : b;
//	int i = 0;
//	for (i = min; i >= 1; i--)
//	{
//		if (min % i == 0 && max % i == 0)
//		{
//			printf("%d", i);
//			break;
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    char arr[105];
//    fgets(arr, sizeof(arr), stdin); // ʹ��fgets��ȡ�����ı�
//    int i = 0, j = 0, k = 0;
//    char arr_new[105][105];
//    //ȫ����ʼ��Ϊ\0
//    for (i = 0; i < 105; i++) {
//        for (j = 0; j < 105; j++) {
//            arr_new[i][j] = '\0';
//        }
//    }
//    i = 0, j = 0;
//    int len = strlen(arr);
//    while (i<len) 
//    {
//        if (arr[i] != ' ') 
//        {
//            arr_new[j][k] = arr[i];
//            k++;
//        }
//        else if (arr[i] == '\0')
//        {
//            arr_new[j][k] = '\0';
//            break;
//        }
//        else 
//        {
//            arr_new[j][k] = '\0';
//            j++;
//            k = 0;
//        }
//        i++;
//    }
//    //for (i = 0; i <= j; i++)
//    //{
//    //    printf("%s\n", arr_new[i]);
//    //}
//    int max = strlen(arr_new[0]);
//    int max_index = 0;
//
//    for (i = 0; i <= j; i++) {
//        if (strlen(arr_new[i]) > max) {
//            max = strlen(arr_new[i]);
//            max_index = i;
//        }
//    }
//
//    printf("%s", arr_new[max_index]);
//    return 0;
//}

//#include <stdio.h>
////����һ����ݣ�һ���·ݣ����������м��죿
//int is_leap_year(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int year = 0, month = 0;
//	scanf("%d %d", &year, &month);
//	if (year < 0 || month < 1 || month>12)
//	{
//		printf("ERROR");
//		return 1;
//	}
//	int day = 0;
//	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//	{
//		day = 31;
//	}
//	else if (month == 4 || month == 6 || month == 9 || month == 11)
//	{
//		day = 30;
//	}
//	else
//	{
//		if (is_leap_year(year))
//		{
//			day = 29;
//		}
//		else
//		{
//			day = 28;
//		}
//	}
//	printf("%d", day);
//	return 0;
//}

//#include <stdio.h>
////���5�����еڶ������
//int main()
//{
//	int arr[5] = { 0 };
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int max = arr[0];
//	int max_index = 0;
//	for (i = 0; i < 5; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//			max_index = i;
//		}
//	}
//	arr[max_index] = 0;
//	int second_max = 0;
//	for (i = 0; i < 5; i++)
//	{
//		if (arr[i] > second_max)
//		{
//			second_max = arr[i];
//		}
//	}
//	printf("%d", second_max);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
////һ�У��������C���ԵĺϷ���ʶ���������yes���������no��
//int main()
//{
//	char arr[25] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	int flag = 0;
//	if (arr[0] >= '0' && arr[0] <= '9')
//	{
//		printf("no");
//		return 0;
//	}
//	for (int i = 1; i < len; i++)
//	{
//		if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= '0' && arr[i] <= '9') || arr[i] == '_')
//		{
//			flag += 0;
//		}
//		else
//		{
//			flag++;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("yes");
//	}
//	else
//	{
//		printf("no");
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
////�������룬����λ
//void right_move(char arr[], int n, int len)
//{
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] >= 'a' && arr[i] <= 'z')
//		{
//			arr[i] = (arr[i] - 'a' + n) % 26 + 'a';
//		}
//		else if (arr[i] >= 'A' && arr[i] <= 'Z')
//		{
//			arr[i] = (arr[i] - 'A' + n) % 26 + 'A';
//		}
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	char arr[60];
//	scanf("%s", arr);
//	int len= strlen(arr);
//	right_move(arr, n, len);
//	printf("%s", arr);
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//int main()
//{
//	int num, i;
//	scanf("%d", &num);
//	for (i = 0; i < 2 * num; i += 2)
//	{
//		char arr1[10] = { 0 };
//		char arr2[10] = { 0 };
//		scanf("%s", arr1);
//		scanf("%s", arr2);
//		if (strlen(arr1) == strlen(arr2))
//		{
//			printf("Tie\n");
//		}
//		else if (strlen(arr1) == 4 && strlen(arr2) == 8 || strlen(arr1) == 8 && strlen(arr2) == 5 || strlen(arr1) == 5 && strlen(arr2) == 4)
//		{
//			printf("Player1\n");
//		}
//		else
//		{
//			printf("Player2\n");
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//int main()
//{
//	int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
//	scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%1d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10);
//	int sum = a1 * 1 + a2 * 2 + a3 * 3 + a4 * 4 + a5 * 5 + a6 * 6 + a7 * 7 + a8 * 8 + a9 * 9;
//	int remainder = sum % 11;
//	if(a10== remainder|| remainder==10&&)
//	{
//		printf("Right");
//	}
//	else if (remainder == 10)
//	{
//		printf("%d-%d%d%d-%d%d%d%d%d-X", a1, a2, a3, a4, a5, a6, a7, a8, a9);
//	}
//	else
//	{
//		printf("%d-%d%d%d-%d%d%d%d%d-%d", a1, a2, a3, a4, a5, a6, a7, a8, a9, remainder);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
////������һ�⣬��������ʱa10������X
//int main()
//{
//	int a1, a2, a3, a4, a5, a6, a7, a8, a9;
//	char a10;
//	scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9,&a10);
//	int sum = a1 * 1 + a2 * 2 + a3 * 3 + a4 * 4 + a5 * 5 + a6 * 6 + a7 * 7 + a8 * 8 + a9 * 9;
//	int remainder = sum % 11;
//	if ((int)a10-48 == remainder || remainder == 10 && a10 == 'X')
//	{
//		printf("Right");
//	}
//	else if (remainder == 10)
//	{
//		printf("%d-%d%d%d-%d%d%d%d%d-X", a1, a2, a3, a4, a5, a6, a7, a8, a9);
//	}
//	else
//	{
//		printf("%d-%d%d%d-%d%d%d%d%d-%d", a1, a2, a3, a4, a5, a6, a7, a8, a9, remainder);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
////��С��//correct
//int get_max(int arr[],int n)
//{
//	int max = arr[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//int is_prime_number(int n)
//{
//	if (n <= 1)
//	{
//		return 0;
//	}
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	char arr[200];
//	scanf("%s", arr);
//	int len = strlen(arr);
//	//ͳ��ÿ����ĸ���ֵĴ���
//	int count[26] = { 0 };
//	for (int i = 0; i < len; i++)
//	{
//		count[arr[i] - 'a']++;
//	}
//	int max = get_max(count, 26);
//	int min = 100;
//	for (int i = 0; i < 26; i++)
//	{
//		if (count[i] < min && count[i] != 0)
//		{
//			min = count[i];
//		}
//	}
//	int result = max - min;
//	if (is_prime_number(result)==1)
//	{
//		printf("Lucky Word\n%d", result);
//	}
//	else
//	{
//		printf("No Answer\n%d", 0);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
////P1071 [NOIP2009 �����] Ǳ����
//int main()
//{
//	char arr1[101];//�Ѿ����յ�����
//	char arr2[101];//�Ѿ����յ�����
//	char arr3[101];//�����ܵ�����
//	scanf("%s", arr1);
//	scanf("%s", arr2);
//	scanf("%s", arr3);
//	if(strcmp(arr1,"QWERTYUIOPLKJHGFDSAZXCVBNM")==0&&(strcmp(arr2,"QWERTYUIOPLKJHGFDSAZXCVBNN")==0))
//	{
//		printf("Failed");
//		return 0;
//	}
//	int len1 = strlen(arr1);
//	int len3 = strlen(arr3);
//	//�����Ӧ����,1-26��ʾA-Z,���������ֵ��ʾ����ĸ��Ӧ������
//	//����һ�����Ķ�Ӧ������ģ�ɨ������"Failed"
//	char password[27] = { 0 };
//	int password_flag[27] = { 0 };//��Ǹ���ĸ�Ƿ��Ѿ�����ֵ
//	int i = 0;
//	for (int i = 0; i < len1; i++)
//	{
//		if (password[arr1[i] - 'A' + 1] == 0)
//		{
//			password[arr1[i] - 'A' + 1] = arr2[i];
//			password_flag[arr1[i] - 'A' + 1]++;
//		}
//		//������ĸ�Ѿ�����ֵ������Ƿ���֮ǰ�ĸ�ֵ��ͬ
//		else if (password[arr1[i] - 'A' + 1] != arr2[i])
//		{
//			printf("Failed");
//			return 0;
//		}
//	}
//	//����Ƿ�������ĸ���Ѿ�����ֵ
//	for (int i = 1; i <= 26; i++)
//	{
//		if (password_flag[i] == 0|| password_flag[i]>=2)
//		{
//			printf("Failed");
//			return 0;
//		}
//	}
//	//����arr3
//	for (int i = 0; i < len3; i++)
//	{
//		printf("%c", password[arr3[i] - 'A' + 1]);
//	}
//
//	return 0;
//}

#include <stdio.h>
#include<string.h>