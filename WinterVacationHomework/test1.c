#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//#include<math.h>
//#include<ctype.h>
//DAY 1
// 
//int isLeapYear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//		return 1;
//	else
//		return 0;
//}
//int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};//非闰年
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
//int func(int x)
//{
//	return (x == 1) ? 1 : (x + func(x - 1));
//}
//int main()
//{
//	printf("%d", func(10));
//	return 0;
//}
//int main()
//{
//	char str[1000];
//	scanf("%s", str);
//	int len = strlen(str);
//	//对字符串按ASCII码排序
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - 1 - i; j++)
//		{
//			if (str[j] > str[j + 1])
//			{
//				char temp = str[j];
//				str[j] = str[j + 1];
//				str[j + 1] = temp;
//			}
//		}
//	}
//	//输出
//	printf("%s", str);
//}

//DAY8
//int main()
//{
//	char str[500] = { 0 };
//	scanf("%s", str);
//	int arr[128] = { 0 };
//	for (int i = 0; i < strlen(str); i++)
//	{
//		arr[str[i]]++;
//	}
//	int num = 0;
//	for (int i = 0; i < 128; i++)
//	{
//		if (arr[i] != 0)
//			num++;
//	}
//	printf("%d", num);
//	return 0;
//}

//DAY 9
//int main()
//{
//	int a = 0xf8b82140;
//	int b = 0xf8b8221c;
//	int c = a * 2 / 5 + b * 3 / 5;
//printf("%#x", c);
//	return 0;
//}

//DAY 10
//int func(int x)
//{
//	int count = 0;
//	while (x)
//	{
//		count++;
//		x = x & (x - 1);
//	}
//	return count;
//}
//int main()
//{
//	printf("%d", func(-1));
//	return 0;
//}
//int main()
//{
//	int a = 1, b = 2, m = 0, n = 0, k;
//	k = (n = b < a) && (m = a);
//	printf("%d %d", k, m);
//	return 0;
//}

//DAY 11
//int main()
//{
//	int k = 1 ^ (1 << 31 >> 31);
//	printf("%d", k);
//	return 0;
//}
//int isPerfectNumber(int num)
//{
//	int sum = 0;
//	for (int i = 1; i < num; i++)
//	{
//		if (num % i == 0)
//			sum += i;
//	}
//	if (sum == num)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if(isPerfectNumber(i))
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}

//DAY 12
//int main()
//{
//	unsigned short x = 65530;
//	unsigned int y = x;
//	printf("%x", y);
//	return 0;
//}
//int main()
//{
//	int n = 1001;
//	int ans = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		ans ^= i % 3;
//	}
//	printf("%d", ans);
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if(n==0)
//	{
//		printf("0");
//		return 0;
//	}
//	while (n)
//	{
//		printf("%d", n % 10);
//		n /= 10;
//	}
//	return 0;
//}
//int main()
//{
//	char str[10000];
//	fgets(str, 10000, stdin);
//	int len = strlen(str);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if (!isalpha(str[i]))
//			str[i] = ' ';
//	}
//	char str1[1000][1000];
//	char *p = strtok(str, " ");
//	int j = 0;
//	while (p)
//	{
//		strcpy(str1[j++], p);
//		p = strtok(NULL, " ");
//	}
//	for (i = j - 1; i >= 0; i--)
//		printf("%s ", str1[i]);
//	return 0;
//}

//DAY 13
//int fun(unsigned int x)
//{
//	int count = 0;
//	while (x+1)
//	{
//		count++;
//		x = x | (x + 1);
//	}
//	return count;
//}
//int main()
//{
//	printf("%d", fun(2014));
//	return 0;
//}
//int fib(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	int a = 1;
//	int b = 1;
//	int c = 0;
//	for (int i = 3; i <= n; i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//	}
//	return c;
//}

//DAY 14
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", fib(n));
//	return 0;
//int main()
//{
//	double n,m;
//	while(scanf("%lf %lf",&n,&m)!=EOF)
//	{
//		double sum = 0;
//		for (int i = 0; i < m; i++)
//		{
//			sum += n;
//			n = sqrt(n);
//		}
//		printf("%.2lf\n", sum);
//	}
//	return 0;
//}
//int main()
//{
//	float a[3] = { 1.5,2.5,3.5 }, * pa = a;
//	*(pa++) *= 3;
//	printf("%f", *pa);
//	return 0;
//}

//2024/01/15比特就业课
//#define DOUBLE(x) ((x)+(x))
//int main()
//{
//	int a = 5;
//	printf("%d", DOUBLE(a + 1));
//
//	return 0;
//}
//#include <stdio.h>
//// offsetof 宏
//#define offsetof(type, member) ((size_t) &((type *)0)->member)
//struct Example {
//    int a;
//    double b;
//    char c;
//};
//int main() {
//    // 计算并打印每个成员的偏移量
//    printf("Offset of 'a' in 'struct Example': %zu\n", offsetof(struct Example, a));
//    printf("Offset of 'b' in 'struct Example': %zu\n", offsetof(struct Example, b));
//    printf("Offset of 'c' in 'struct Example': %zu\n", offsetof(struct Example, c));
//
//    return 0;
//}
//#include <stdio.h>
//
//#define SWAP_ODD_EVEN_BITS(x) (((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1))
//
//int main() 
//{
//    unsigned int x = 0b10101010101010101010101010101010; 
//    unsigned int result = SWAP_ODD_EVEN_BITS(x);
//
//    printf("交换之前 %#X\n", x);
//    printf("交换之后 %#X\n", result);
//
//    return 0;
//int z = 2 * (4 + ((4 + 2) * 5 + 1));
//int main()
//{
//	printf("%d", z);
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    FILE* src, * dest;
//    char ch;
//
//    // 打开源文件（读取模式）
//    src = fopen("aaa.mp4", "rb");
//    if (src == NULL) {
//        printf("无法打开源文件 \n");
//        exit(EXIT_FAILURE);
//    }
//
//    // 打开目标文件（写入模式）
//    dest = fopen("aaacopy.mp4", "wb");
//    if (dest == NULL) {
//        printf("无法创建目标文件 \n");
//        fclose(src);
//        exit(EXIT_FAILURE);
//    }
//
//    // 从源文件读取字符并写入目标文件
//    while ((ch = fgetc(src)) != EOF) {
//        fputc(ch, dest);
//    }
//
//    // 关闭文件
//    fclose(src);
//    fclose(dest);
//
//    printf("文件复制完成。\n");
//
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    FILE* src, * dest;
//    char buffer[1024];  // 使用缓冲区以提高效率
//    size_t bytes;
//
//    // 以二进制模式打开源文件
//    src = fopen("aaa.mp4", "rb");
//    if (src == NULL) {
//        printf("无法打开源文件 example.mp4\n");
//        exit(EXIT_FAILURE);
//    }
//
//    // 以二进制模式打开目标文件
//    dest = fopen("aaacopy.mp4", "wb");
//    if (dest == NULL) {
//        printf("无法创建目标文件 examplecopy.mp4\n");
//        fclose(src);
//        exit(EXIT_FAILURE);
//    }
//    // 使用缓冲区读取和写入数据
//    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
//        fwrite(buffer, 1, bytes, dest);
//    }
//
//    // 关闭文件
//    fclose(src);
//    fclose(dest);
//
//    printf("文件复制完成。\n");
//
//    return 0;
//}

//DAY 15

//DAY 16
//int main()
//{
//	unsigned char i = 7;
//	int j = 0;
//	for (; i > 0; i -= 3)
//		j++;
//	printf("%d", j);
//	return 0;
//}
//int main() {
//    long long x, y;
//    long long n, k;
//    long long count = 0;
//    scanf("%lld %lld", &n, &k);
//    if (k == 0)
//    {
//        printf("%lld", n * n);
//        return 0;
//    }
//    else
//    {
//        for (x = k + 1; x <= n; x++)
//        {
//            count += (n / x) * (x - k) + (n % x >= k ? n % x - k + 1 : 0);
//        }
//    }
//
//    printf("%lld\n", count);
//    return 0;
//}

