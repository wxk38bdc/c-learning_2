#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//
//}
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	printf("交换前:a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("交换后:a=%d,b=%d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char arr[100];
//	scanf("%[^\n]", arr);
//	printf("%s\n", arr);
//	return 0;
//}

//#include <stdio.h>
//#include<string.h>
//int main()
//{
//	int n, i;
//	scanf("%d", &n);
//	for (i = 0; i < 2 * n; i += 2)
//	{
//		char arr1[10] = { 0 };
//		char arr2[10] = { 0 };
//		scanf("%s", arr1);
//		scanf("%s", arr2);
//		if (strcmp(arr1,arr2)==0)
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
//#include <string.h>
//
//int main()
//{
//    char tmp[250];
//    fgets(tmp, sizeof(tmp), stdin); // 使用fgets来读取一整行文本
//    char a[120], b[120];
//    scanf("%s", a);
//    scanf("%s", b);
//    // 将tmp中的单词按照空格分割存入arr中
//    char arr[200][200];
//    int i = 0, j = 0, k = 0;
//    while (tmp[i] != '\0')
//    {
//        if (tmp[i] != ' ' && tmp[i] != '\n') // 忽略空格和换行符
//        {
//            arr[j][k] = tmp[i];
//            k++;
//        }
//        else
//        {
//            arr[j][k] = '\0';
//            j++;
//            k = 0;
//        }
//        i++;
//    }
//    //遍历arr,找到待替换的单词，并用新单词替换
//    for (i = 0; i < j; i++)
//    {
//        if (strcmp(arr[i], a) == 0)
//        {
//            printf("%s ", b);
//        }
//        else
//        {
//            printf("%s ", arr[i]);
//        }
//    }
//
//    return 0;
//}

//#include <stdio.h>
//#include<string.h>
////P1071 [NOIP2009 提高组] 潜伏者//打了这么多补丁，终于对了
//int main()
//{
//	char arr1[101];//已经掌握的密文
//	char arr2[101];//已经掌握的明文
//	char arr3[101];//待解密的密文
//	scanf("%s", arr1);
//	scanf("%s", arr2);
//	scanf("%s", arr3);
//	int len1 = strlen(arr1);
//	int len3 = strlen(arr3);
//	//检测arr1中若有2个字母相同，则arr2中对应的字母也应该相同
//	for (int i = 0; i < len1; i++)
//	{
//		for (int j = i + 1; j < len1; j++)
//		{
//			if (arr1[i] == arr1[j] && arr2[i] != arr2[j])
//			{
//				printf("Failed");
//				return 0;
//			}
//		}
//	}
//	for (int i = 0; i < len1; i++)
//	{
//		for (int j = i + 1; j < len1; j++)
//		{
//			if (arr2[i] == arr2[j] && arr1[i] != arr1[j])
//			{
//				printf("Failed");
//				return 0;
//			}
//		}
//	}
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
//		if (password_flag[i] == 0 || password_flag[i] >= 2)
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

//#include<stdio.h>
//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	a++;
//	(*pa)++;
//	printf("%d %d \n", a,*pa);
//	return 0;
//}

////用指针实现两个数的交换
//#include<stdio.h>
//void Swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("交换前:a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("交换后:a=%d,b=%d\n", a, b);
//	return 0;
//}

//#include<stdio.h>
////CCF 202309-1 坐标变换（其一）
//int main()
//{
//	int n, m;//n:操作数 m:坐标数
//	scanf("%d%d", &n, &m);
//	int arr1[200] = { 0 };//存储操作数
//	int i = 0, j = 0;
//	//输入操作数,偶数为x坐标，奇数为y坐标
//	for (i = 0; i < n * 2; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	int arr2[200] = { 0 };//存储坐标
//	//输入坐标,偶数为x坐标，奇数为y坐标
//	for (i = 0; i < m * 2; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	//进行坐标变换
//	for (i = 0; i < m * 2; i += 2)
//	{
//		for (j = 0; j < n * 2; j += 2)
//		{
//			arr2[i] += arr1[j];
//			arr2[i + 1] += arr1[j + 1];
//		}
//	}
//	//输出坐标
//	for (i = 0; i < m * 2; i += 2)
//	{
//		printf("%d %d\n", arr2[i], arr2[i + 1]);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
////CCF 202309-2 坐标变换（其二）
//int main()
//{
//	int n, m;//n:操作数 m:查询数
//	double arr_n[200000] = { 0 };//存储操作数
//	double arr_m[400000] = { 0 };//存储查询数
//	int i = 0, j = 0;
//	scanf("%d%d", &n, &m);
//	//输入操作数
//	for (i = 0; i < 2 * n; i++)
//	{
//		scanf("%lf", &arr_n[i]);
//	}
//	//输入查询数
//	//第4k个数为i,第4k+1个数为j,第4k+2个数为x,第4k+3个数为y
//	//i是第i个操作数，j是第j个操作数
//	for (i = 0; i < 4 * m; i++)
//	{
//		scanf("%lf", &arr_m[i]);
//	}
//	int a = 0, b = 0, c = 0, d = 0;
//	//进行查询并操作
//	//对x,y进行从i到j的操作,4个数为一次大循环
//	for (a = 0; a < 4 * m; a += 4)
//	{
//		int i = arr_m[a] - 1, j = arr_m[a + 1] - 1;//-1是因为数组下标从0开始
//		double x = arr_m[a + 2], y = arr_m[a + 3];
//		for(b = i; b <= j; b++)
//		{
//			int judge = arr_n[2 * b];//判断操作数，1为乘以arr[2*b+1],2为逆时针旋转arr[2*b+1]
//			double num = arr_n[2 * b + 1];
//			if (judge == 1)
//			{
//				x *= num;
//				y *= num;
//			}
//			else if (judge == 2)
//			{
//				double tmp1= x, tmp2 = y;
//				x = tmp1 * cos(num) - tmp2 * sin(num);
//				y = tmp1 * sin(num) + tmp2 * cos(num);
//			}
//		}
//		//输出结果
//		printf("%lf %lf\n", x, y);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    int n, m;
//    scanf("%d%d", &n, &m);
//
//    double arr_n[20000] = { 0 };
//    double arr_m[40000] = { 0 };
//
//    for (int i = 0; i < 2 * n; i++) {
//        scanf("%lf", &arr_n[i]);
//    }
//
//    for (int i = 0; i < 4 * m; i++) {
//        scanf("%lf", &arr_m[i]);
//    }
//
//    double multiply_prefix[20000] = { 1.0 }; // 存储乘法的前缀和
//    double rotate_prefix[20000] = { 0.0 };   // 存储旋转的前缀和
//
//    // 预处理前缀和
//    for (int i = 0; i < n; i++) {
//        int judge = (int)arr_n[2 * i];
//        double num = arr_n[2 * i + 1];
//
//        multiply_prefix[i + 1] = multiply_prefix[i];
//        rotate_prefix[i + 1] = rotate_prefix[i];
//
//        if (judge == 1) {
//            multiply_prefix[i + 1] *= num;
//        }
//        else if (judge == 2) {
//            rotate_prefix[i + 1] += num;
//        }
//    }
//
//    for (int k = 0; k < m; k++) {
//        double x = arr_m[4 * k + 2];
//        double y = arr_m[4 * k + 3];
//
//        int i = (int)arr_m[4 * k] - 1;
//        int j = (int)arr_m[4 * k + 1] - 1;
//
//        // 直接获取区间内的影响
//        double multiply_effect = multiply_prefix[j + 1] / multiply_prefix[i];
//        double rotate_effect = rotate_prefix[j + 1] - rotate_prefix[i];
//
//        // 应用变换
//        x *= multiply_effect;
//        y *= multiply_effect;
//
//        double tmp1 = x, tmp2 = y;
//        x = tmp1 * cos(rotate_effect) - tmp2 * sin(rotate_effect);
//        y = tmp1 * sin(rotate_effect) + tmp2 * cos(rotate_effect);
//
//        printf("%lf %lf\n", x, y);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//// 全局变量用于统计移动次数
//int moveCount = 0;
//
//// 汉诺塔函数
//void hanoi(int n, char source, char auxiliary, char target) 
//{
//    if (n == 1) 
//    {
//        printf("移动圆盘 1 从 %c 到 %c\n", source, target);
//        moveCount++;
//    }
//    else 
//    {
//        hanoi(n - 1, source, target, auxiliary);
//        printf("移动圆盘 %d 从 %c 到 %c\n", n, source, target);
//        moveCount++;
//        hanoi(n - 1, auxiliary, source, target);
//    }
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    printf("汉诺塔步骤:\n");
//    hanoi(n, 'A', 'B', 'C');
//    printf("总移动次数: %d\n", moveCount);
//    return 0;
//}

