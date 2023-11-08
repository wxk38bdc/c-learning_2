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

//#include <stdio.h>
////输入一个年份，一个月份，输出这个月有几天？
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
////输出5个数中第二大的数
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
////一行，如果它是C语言的合法标识符，则输出yes，否则输出no。
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
////凯撒密码，即移位
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
////还是上一题，考虑输入时a10可能是X
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
////笨小猴//correct
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
//	//统计每个字母出现的次数
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
////P1071 [NOIP2009 提高组] 潜伏者
//int main()
//{
//	char arr1[101];//已经掌握的密文
//	char arr2[101];//已经掌握的明文
//	char arr3[101];//待解密的密文
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
//	//密码对应数组,1-26表示A-Z,存入数组的值表示该字母对应的明文
//	//若有一个密文对应多个明文，扫描后输出"Failed"
//	char password[27] = { 0 };
//	int password_flag[27] = { 0 };//标记该字母是否已经被赋值
//	int i = 0;
//	for (int i = 0; i < len1; i++)
//	{
//		if (password[arr1[i] - 'A' + 1] == 0)
//		{
//			password[arr1[i] - 'A' + 1] = arr2[i];
//			password_flag[arr1[i] - 'A' + 1]++;
//		}
//		//若该字母已经被赋值，检测是否与之前的赋值相同
//		else if (password[arr1[i] - 'A' + 1] != arr2[i])
//		{
//			printf("Failed");
//			return 0;
//		}
//	}
//	//检测是否所有字母都已经被赋值
//	for (int i = 1; i <= 26; i++)
//	{
//		if (password_flag[i] == 0|| password_flag[i]>=2)
//		{
//			printf("Failed");
//			return 0;
//		}
//	}
//	//破译arr3
//	for (int i = 0; i < len3; i++)
//	{
//		printf("%c", password[arr3[i] - 'A' + 1]);
//	}
//
//	return 0;
//}

#include <stdio.h>
#include<string.h>