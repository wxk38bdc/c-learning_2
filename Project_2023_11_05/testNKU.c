#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[105];
//	scanf("%[^\n]", arr);
//	//去除标点符号
//	int i = 0;
//	while (arr[i] != '\0')
//	{
//		if ((33<=arr[i]&&arr[i]<=47)||(58 <= arr[i] && arr[i] <= 64)|| (91 <= arr[i] && arr[i] <= 96)|| (123 <= arr[i] && arr[i] <= 126))
//		{
//			arr[i] = ' ';
//		}
//		i++;
//	}
//	//将大写字母转换为小写字母
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
//	//将字符串分割为单词,并存入二维数组,不使用strtok函数
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
//	//输出每个单词，每两个单词用空格隔开，并去重（遇到重复的单词不输出）
//	int count = 0;
//	for (int k = 0; k < j; k++)
//	{
//		//如果第一个字符串是空字符串，则跳过
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
//	//输出单词总数（去重后）
//	printf("\n%d", count);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h> // 用于大小写转换
//
//int main() {
//    char arr[105];
//    fgets(arr, sizeof(arr), stdin);
//
//    // 将大写字母转换为小写字母
//    for (int i = 0; arr[i]; i++) 
//    {
//        arr[i] = tolower(arr[i]);
//    }
//
//    // 初始化一个数组来跟踪唯一的单词
//    int unique[50] = { 0 };
//    int count = 0;
//
//    // 处理输入以拆分和计数单词
//    char* token = strtok(arr, " \t\n\r\f\v.!?,;:\"-()[]{}");
//    while (token != NULL) {
//        int found = 0;
//
//        // 检查单词是否唯一
//        for (int i = 0; i < count; i++) {
//            if (strcmp(token, arr + unique[i]) == 0) {
//                found = 1;
//                break;
//            }
//        }
//
//        // 如果单词是唯一的，则打印它
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
//    // 打印单词计数
//    printf("\n%d", count);
//
//    return 0;
//}

//#include <stdio.h>
////输入任意年份及该年1月1日是星期几，然后再输入该年的任意一个月份，程序按照格式输出该月的日历。
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
//	int week_day = 0;//1月1日是星期几
//	scanf("%d %d %d", &year, &week_day, &month);
//	//排除不合法的输入
//	if (year < 0 || month < 1 || month>12 || week_day < 0 || week_day>6)
//	{
//		printf("ERROR");
//		return 1;
//	}
//
//	//计算该月的第一天是该年的第几天
//	int month_first_day = 0;
//	for (int i = 1; i < month; i++)
//	{
//		month_first_day += dayofmonth(year, i);
//	}
//	//计算该月的第一天是星期几
//	int month_first_week_day = (month_first_day + week_day) % 7;
//	//输出日历
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

//求2个正整数的最大公约数
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
//    fgets(arr, sizeof(arr), stdin); // 使用fgets读取整行文本
//    int i = 0, j = 0, k = 0;
//    char arr_new[105][105];
//    //全部初始化为\0
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

#include <stdio.h>
//输入一个年份，一个月份，输出这个月有几天？
int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int year = 0, month = 0;
	scanf("%d %d", &year, &month);
	if (year < 0 || month < 1 || month>12)
	{
		printf("ERROR");
		return 1;
	}
	int day = 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		day = 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		day = 30;
	}
	else
	{
		if (is_leap_year(year))
		{
			day = 29;
		}
		else
		{
			day = 28;
		}
	}
	printf("%d", day);
	return 0;
}