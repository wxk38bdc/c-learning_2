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
//	printf("����ǰ:a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("������:a=%d,b=%d\n", a, b);
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
//    fgets(tmp, sizeof(tmp), stdin); // ʹ��fgets����ȡһ�����ı�
//    char a[120], b[120];
//    scanf("%s", a);
//    scanf("%s", b);
//    // ��tmp�еĵ��ʰ��տո�ָ����arr��
//    char arr[200][200];
//    int i = 0, j = 0, k = 0;
//    while (tmp[i] != '\0')
//    {
//        if (tmp[i] != ' ' && tmp[i] != '\n') // ���Կո�ͻ��з�
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
//    //����arr,�ҵ����滻�ĵ��ʣ������µ����滻
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
////P1071 [NOIP2009 �����] Ǳ����//������ô�ಹ�������ڶ���
//int main()
//{
//	char arr1[101];//�Ѿ����յ�����
//	char arr2[101];//�Ѿ����յ�����
//	char arr3[101];//�����ܵ�����
//	scanf("%s", arr1);
//	scanf("%s", arr2);
//	scanf("%s", arr3);
//	int len1 = strlen(arr1);
//	int len3 = strlen(arr3);
//	//���arr1������2����ĸ��ͬ����arr2�ж�Ӧ����ĸҲӦ����ͬ
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
//		if (password_flag[i] == 0 || password_flag[i] >= 2)
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

////��ָ��ʵ���������Ľ���
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
//	printf("����ǰ:a=%d,b=%d\n", a, b);
//	Swap(&a, &b);
//	printf("������:a=%d,b=%d\n", a, b);
//	return 0;
//}

//#include<stdio.h>
////CCF 202309-1 ����任����һ��
//int main()
//{
//	int n, m;//n:������ m:������
//	scanf("%d%d", &n, &m);
//	int arr1[200] = { 0 };//�洢������
//	int i = 0, j = 0;
//	//���������,ż��Ϊx���꣬����Ϊy����
//	for (i = 0; i < n * 2; i++)
//	{
//		scanf("%d", &arr1[i]);
//	}
//	int arr2[200] = { 0 };//�洢����
//	//��������,ż��Ϊx���꣬����Ϊy����
//	for (i = 0; i < m * 2; i++)
//	{
//		scanf("%d", &arr2[i]);
//	}
//	//��������任
//	for (i = 0; i < m * 2; i += 2)
//	{
//		for (j = 0; j < n * 2; j += 2)
//		{
//			arr2[i] += arr1[j];
//			arr2[i + 1] += arr1[j + 1];
//		}
//	}
//	//�������
//	for (i = 0; i < m * 2; i += 2)
//	{
//		printf("%d %d\n", arr2[i], arr2[i + 1]);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<math.h>
////CCF 202309-2 ����任�������
//int main()
//{
//	int n, m;//n:������ m:��ѯ��
//	double arr_n[200000] = { 0 };//�洢������
//	double arr_m[400000] = { 0 };//�洢��ѯ��
//	int i = 0, j = 0;
//	scanf("%d%d", &n, &m);
//	//���������
//	for (i = 0; i < 2 * n; i++)
//	{
//		scanf("%lf", &arr_n[i]);
//	}
//	//�����ѯ��
//	//��4k����Ϊi,��4k+1����Ϊj,��4k+2����Ϊx,��4k+3����Ϊy
//	//i�ǵ�i����������j�ǵ�j��������
//	for (i = 0; i < 4 * m; i++)
//	{
//		scanf("%lf", &arr_m[i]);
//	}
//	int a = 0, b = 0, c = 0, d = 0;
//	//���в�ѯ������
//	//��x,y���д�i��j�Ĳ���,4����Ϊһ�δ�ѭ��
//	for (a = 0; a < 4 * m; a += 4)
//	{
//		int i = arr_m[a] - 1, j = arr_m[a + 1] - 1;//-1����Ϊ�����±��0��ʼ
//		double x = arr_m[a + 2], y = arr_m[a + 3];
//		for(b = i; b <= j; b++)
//		{
//			int judge = arr_n[2 * b];//�жϲ�������1Ϊ����arr[2*b+1],2Ϊ��ʱ����תarr[2*b+1]
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
//		//������
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
//    double multiply_prefix[20000] = { 1.0 }; // �洢�˷���ǰ׺��
//    double rotate_prefix[20000] = { 0.0 };   // �洢��ת��ǰ׺��
//
//    // Ԥ����ǰ׺��
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
//        // ֱ�ӻ�ȡ�����ڵ�Ӱ��
//        double multiply_effect = multiply_prefix[j + 1] / multiply_prefix[i];
//        double rotate_effect = rotate_prefix[j + 1] - rotate_prefix[i];
//
//        // Ӧ�ñ任
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
//// ȫ�ֱ�������ͳ���ƶ�����
//int moveCount = 0;
//
//// ��ŵ������
//void hanoi(int n, char source, char auxiliary, char target) 
//{
//    if (n == 1) 
//    {
//        printf("�ƶ�Բ�� 1 �� %c �� %c\n", source, target);
//        moveCount++;
//    }
//    else 
//    {
//        hanoi(n - 1, source, target, auxiliary);
//        printf("�ƶ�Բ�� %d �� %c �� %c\n", n, source, target);
//        moveCount++;
//        hanoi(n - 1, auxiliary, source, target);
//    }
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    printf("��ŵ������:\n");
//    hanoi(n, 'A', 'B', 'C');
//    printf("���ƶ�����: %d\n", moveCount);
//    return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//int main() 
//{
//    int x, y, x1, y1;
//    scanf("%d %d %d %d", &x, &y, &x1, &y1);
//    if (x == x1 && y1 - y == 1)
//    {
//        printf("u");
//    }
//    else if (x == x1 && y1 - y == -1)
//    {
//        printf("d");
//    }
//    else if (x == x1-1 && y1 == y )
//    {
//        printf("r");
//    }
//    else 
//    {
//        printf("l");
//    }
//    return 0;
//}

//#include<stdio.h>
////200 - OK
////202 - Accepted
////400 - Bad Request
////403 - Forbidden
////404 - Not Found
////500 - Internal Server Error
////502 - Bad Gateway
//int main()
//{
//	int a;
//	while (scanf("%d", &a) != EOF)
//	{
//		switch (a)
//		{
//		case 200:
//			printf("OK");
//			break;
//		case 202:
//			printf("Accepted");
//			break;
//		case 400:
//			printf("Bad Request");
//			break;
//		case 403:
//			printf("Forbidden");
//			break;
//		case 404:
//			printf("Not Found");
//			break;
//		case 500:
//			printf("Internal Server Error");
//			break;
//		case 502:
//			printf("Bad Gateway");
//			break;
//		}
//	}
//	return 0;
//}

//#include<stdio.h>
//
//int main()
//{
//	double t;
//	while (scanf("%lf", &t) != EOF)
//	{
//		if (t > 0)
//			printf("1\n");
//		else if (t == 0)
//			printf("0.5\n")
//		else
//			printf("0\n");
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int year, month, day;
//	int y1, m1, d1;
//	scanf("%d %d %d %d %d %d", &year, &month, &day, &y1, &m1, &d1);
//	if (y1 > year || y1 == year && m1 > month || y1 == year && m1 == month && d1 >= day)
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
//#include<math.h>
////����һԪ���η���
//int main()
//{
//	double a, b, c;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	if (a == 0)
//	{
//		printf("Not quadratic equation");
//		return 0;
//	}
//	double delta = b * b - 4 * a * c;
//	double x1, x2;
//	if (delta == 0)
//	{
//		printf("x1=x2=%.2lf", (-b) / (2 * a)+1.0-1.0);
//	}
//	else if (delta > 0)
//	{
//		x1 = (-b - sqrt(delta)) / (2 * a);
//		x2 = (-b + sqrt(delta)) / (2 * a);
//		printf("x1=%.2lf;x2=%.2lf", x1, x2);
//	}
//	else
//	{
//		x1 = (-b) / (2 * a);
//		x2 = sqrt(-1 * delta) / (2 * a);
//		printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi", x1, x2, x1, x2);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	double n1, n2;
//	char a;
//	scanf("%lf%c%lf", &n1, &a, &n2);
//	switch (a)
//	{
//	case '+':
//		printf("%.4lf+%.4lf=%.4lf", n1, n2, n1 + n2);
//		break;
//	case '-':
//		printf("%.4lf-%.4lf=%.4lf", n1, n2, n1 - n2);
//		break;
//	case '*':
//		printf("%.4lf*%.4lf=%.4lf", n1, n2, n1 * n2);
//		break;
//	case '/':
//		if (n2 == 0)
//		{
//			printf("Wrong!Division by zero!");
//		}
//		else
//		{
//			printf("%.4lf/%.4lf=%.4lf", n1, n2, n1 / n2);
//		}
//		break;
//	default:
//		printf("Invalid operation!");
//		break;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//    double n;
//    scanf("%lf", &n);
//    double sum = 0;
//    for (int i = 1; i <=(int)n; i++)
//    {
//        if ((int)i % 2)
//        {
//            sum += 1.0 / i;
//        }
//        else
//        {
//            sum -= 1.0 / i;
//        }
//    }
//    printf("%.3lf", sum);
//    return 0;
//}

//#include <stdio.h>
//int func(int n)
//{
//	return (1 + n) * n / 2;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int sum = 0;
//	for(int i=1;i<=n;i++)
//	{
//		sum += func(i);
//	}
//	printf("%d", sum);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int count = 0;
//	while (n != 1)
//	{
//		if (n % 2 == 1)
//		{
//			n = 3 * n + 1;
//			count++;
//		}
//		else if (n % 2 == 0)
//		{
//			n /= 2;
//			count++;
//		}
//	}
//	printf("%d", count);
//}

//#include <stdio.h>
//int main()
//{
//	int count = 0;
//	for (int i = 1; i <= 2019; i++)
//	{
//		if(i%10==9||i/10%10==9||i/100%10==9||i/1000%10==9)
//		{
//			count++;
//		}
//	}
//	printf("%d", count);
//	return 0;
//}

//#include <stdio.h>
//int isLilyNumber(int n)
//{
//    int sum = 0;
//    sum += (n % 10) * (n % 10) * (n % 10) + ((n / 10) % 10) * ((n / 10) % 10) * ((n / 10) % 10) + ((n / 100) % 10) * ((n / 100) % 10) * ((n / 100) % 10);
//    if (sum == n)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main() {
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF) 
//    { 
//        int count = 0;
//        for (int i = a; i <= b; i++)
//        {
//			if(isLilyNumber(i))
//			{
//				count++;
//                printf("%d ", i);
//			}
//        }
//        if (count == 0)
//        {
//            printf("no\n");
//        }
//        else
//        {
//			printf("\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//int isLilyNumber(int n)
//{
//	int sum = 0;
//	sum = (n % 10) * (n / 10) + (n % 100) * (n / 100) + (n % 1000) * (n / 1000)+(n % 10000) * (n / 10000);
//	if (sum == n)
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
//	for (int i = 10000; i < 100000; i++)
//	{
//		if(isLilyNumber(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
////10������ת��Ϊ6������
//int main()
//{
//	int arr[30] = { 0 };
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	while (n)
//	{
//		arr[i] = n % 6;
//		n /= 6;
//		i++;
//	}
//	for (int j = i - 1; j >= 0; j--)
//	{
//		printf("%d", arr[j]);
//	}
//	return 0;
//}

//#include <stdio.h>
////��������ң���һ��1ö����2,3��2ö����4,5,6��3ö����7,8,9,10��4ö����11,12,13,14,15��5ö���Դ�����
////�ж�i�Ƿ�Ϊ1,3,6,10,15,21,...,n(n+1)/2
//int isKing(int n)
//{
//	int sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += i;
//		if (sum == n)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int sum = 0;
//	int key = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += key;
//		if (isKing(i))
//		{
//			key++;
//		}
//	}
//printf("%d", sum);
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int func(int n)//�ж��Ƿ�Ϊ������
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	while (n)
//	{
//		arr[i] = n % 10;
//		n /= 10;
//		i++;
//	}
//	for (int j = 0; j < i / 2; j++)
//	{
//		if (arr[j] != arr[i - 1 - j])
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	char arr[10] = { 0 };
//	scanf("%s", arr);
//	int len = strlen(arr);
//	int n = atoi(arr);
//	for (int i = 1; i < n; i++)
//	{
//		if(func(i))
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}

//#include <stdio.h>
//int n, o, t, num;
//int main()
//{
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		t = 0;
//		num = i;
//		while (num != 0)
//		{
//			t *= 10;
//			t += num % 10;
//			num /= 10;
//		}
//		if (i == t)
//			printf("%d\n", t);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//int main() {
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        int tmp = n;
//        int empty = n - 1;
//        while (tmp--)
//        {
//            for (int i = 0; i < empty; i++)
//            {
//				printf(" ");
//            }
//            for (int i = 0; i < n - empty; i++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//            empty--;
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//int main() 
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//        int a = n + 1;
//        for (int i = a; i >= -a; i--)
//        {
//            if (i == 0 || i == -1)
//            {
//                continue;
//            }
//            for (int j = 0; j < abs(i); j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//    int n;
//    while (scanf("%d", &n) != EOF)
//    {
//      
//    }
//    return 0;
//}

//#include <stdio.h>
//
//// ȫ�ֱ�������ͳ���ƶ�����
//int moveCount = 0;
//
//// ��ŵ������
//void hanoi(int n, char source, char auxiliary, char target)
//{
//    if (n == 1)
//    {
//        printf("�ƶ�Բ�� 1 �� %c �� %c\n", source, target);
//        moveCount++;
//    }
//    else
//    {
//        hanoi(n - 1, source, target, auxiliary);
//        printf("�ƶ�Բ�� %d �� %c �� %c\n", n, source, target);
//        moveCount++;
//        hanoi(n - 1, auxiliary, source, target);
//    }
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    printf("��ŵ������:\n");
//    hanoi(n, 'A', 'B', 'C');
//    printf("���ƶ�����: %d\n", moveCount);
//    return 0;
//}

//#include<stdio.h>
//int movecount = 0;
//void hanoi(int n, char source, char auxiliary, char target)
//{
//	if (n == 1)
//	{
//		printf("Բ�� 1 : %c -> %c\n", source, target);
//		movecount++;
//	}
//	else
//	{
//		hanoi(n - 1, source, target, auxiliary);
//		printf("Բ�� %d : %c -> %c\n", n, source, target);
//		movecount++;
//		hanoi(n - 1, auxiliary, source, target);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	hanoi(n,'A','B','C');
//	printf("���ƶ�������%d\n", movecount);
//	return 0;
//}

//#include <stdio.h>
////Ѱ�Ұ��㣬����Ԫ���������е����ֵ���������е���Сֵ
//int main()
//{
//	int arr[5][5] = { 0 };
//	int i = 0, j = 0;
//	for (i = 0; i < 5; i++)
//	{
//		for (j = 0; j < 5; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	//�����ڰ��㣬���������������Ԫ��ֵ
//	//�������ڰ��㣬���"not found"
//	//�������
//	int flag = 0;
//	for (i = 0; i < 5; i++)
//	{
//		int max = arr[i][0];
//		int max_j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			if (arr[i][j] > max)
//			{
//				max = arr[i][j];
//				max_j = j;
//			}
//		}
//		int min = arr[0][max_j];
//		for (int k = 0; k < 5; k++)
//		{
//			if (arr[k][max_j] < min)
//			{
//				min = arr[k][max_j];
//			}
//		}
//		if (min == max)
//		{
//			printf("%d %d %d\n", i + 1, max_j + 1, max);
//			flag = 1;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("not found");
//	}
//	return 0;
//}

//#include <stdio.h>
//struct stu {
//	char name[10];
//	int chinese;
//	int math;
//	int english;
//	int total_grade;
//}s[1000];
//int cmp(const void* a, const void* b)
//{
//	struct stu* aa = (struct stu*)a;
//	struct stu* bb = (struct stu*)b;
//	return bb->total_grade - aa->total_grade;
//}
//int main()
//{
//	int n = 0;//ѧ������
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s %d %d %d", s[i].name, &s[i].chinese, &s[i].math, &s[i].english);
//		s[i].total_grade = s[i].chinese + s[i].math + s[i].english;
//	}
//	qsort(s, n, sizeof(s[0]), cmp);//���ܳɼ�����
//	//����ɼ���ߵ�ѧ��ȫ����Ϣ
//	printf("%s %d %d %d\n", s[0].name, s[0].chinese, s[0].math, s[0].english);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//struct stu {
//	char name[10];
//	int chinese;
//	int math;
//	int english;
//	int total_grade;
//}s[1000];
//int main()
//{
//	int n = 0;//ѧ������
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s %d %d %d", s[i].name, &s[i].chinese, &s[i].math, &s[i].english);
//		s[i].total_grade = s[i].chinese + s[i].math + s[i].english;
//	}
//	//Ѱ�ҡ����ǿ����ѧ��
//	//��2��ѧ�������ġ���ѧ��Ӣ������<5���ܷ����<10
//	for (i = 0; i < n; i++)
//	{
//		for (j = i+1; j < n; j++)
//		{
//			if (abs(s[i].chinese - s[j].chinese) <= 5 && abs(s[i].math - s[j].math) <= 5 && abs(s[i].english - s[j].english) <= 5 && abs(s[i].total_grade - s[j].total_grade) <= 10)
//			{
//				printf("%s %s\n", s[i].name, s[j].name);
//			}
//		}
//	}
//	return 0;
//}

#include <stdio.h>
int main()
{
	int arr[31][31] = { 0 };
	int n = 0;//����ά����������������
	int judge = 0;//�жϣ�1��˳ʱ�룬2����ʱ��
	scanf("%d %d", &n, &judge);
	int i = 0, j = 0;
	if (judge == 1)
	{
		int num = 1;//���������,��1��ʼ
		int left = 0, right = n - 1, up = 0, down = n - 1;
		while (num <= n * n)
		{
			for (i = left; i <= right; i++)
			{
				arr[up][i] = num;
				num++;
			}
			up++;
			for (i = up; i <= down; i++)
			{
				arr[i][right] = num;
				num++;
			}
			right--;
			for (i = right; i >= left; i--)
			{
				arr[down][i] = num;
				num++;
			}
			down--;
			for (i = down; i >= up; i--)
			{
				arr[i][left] = num;
				num++;
			}
			left++;
		}

	}
	else if (judge == 2)
	{
		int num = 1;
		int left = 0, right = n - 1, up = 0, down = n - 1;
		while (num <= n * n)
		{
			for (i = up; i <= down; i++)
			{
				arr[i][left] = num;
				num++;
			}
			left++;
			for (i = left; i <= right; i++)
			{
				arr[down][i] = num;
				num++;
			}
			down--;
			for (i = down; i >= up; i--)
			{
				arr[i][right] = num;
				num++;
			}
			right--;
			for (i = right; i >= left; i--)
			{
				arr[up][i] = num;
				num++;
			}
			up++;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%4d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//#include <stdio.h>
//		//�����Ͻ�arr[x-1][y-1]��ʼ��ת����ת��Χ�߳�Ϊr
//		// arr_tmpΪ��������arrΪ������ľ���
//		//ʾ�����룺
//		//5 1
//		//2 2 3 1
//		//ʾ�������
//		//1 2 3 4 5
//		//6 9 14 19 10
//		//11 8 13 18 15
//		//16 7 12 17 20
//		//21 22 23 24 25
//		//�㷨ʵ�֣�
//		//����ʾ���д�arr[1][1]��ʼ��ת����ת��ΧΪ3*3����תһ��
//		//����ת���ݴ��⵽��һ����2�㣬��һ����7,8,9,14,19,18,17,12,�ڶ�����13;
//		//������������ת������up,down,left,right�ֱ�Ϊ�������ұ߽�
//		//��arr_tmp��ѡȡ���ʵ����ݷ���arr��
//		//1  2  3  4 5
//		//6  7  8  9 10
//		//11 12 13 14 15
//		//16 17 18 19 20
//		//21 22 23 24 25
//void leftmove(int arr[], int len, int r)
//{
//	int i = 0;
//	while (r--)
//	{
//		int tmp = arr[0];
//		for (i = 0; i < len - 1; i++)
//		{
//			arr[i] = arr[i + 1];
//		}
//		arr[len - 1] = tmp;
//	}
//}
//void rightmove(int arr[], int len, int r)
//{
//	int i = 0;
//	while (r--)
//	{
//		int tmp = arr[len - 1];
//		for (i = len - 1; i > 0; i--)
//		{
//			arr[i] = arr[i - 1];
//		}
//		arr[0] = tmp;
//	}
//}
//int main()
//{
//	int n = 0;//�����С
//	int m = 0;//��ת����
//	int arr[100][100] = { 0 };
//	int arr_tmp[100][100] = { 0 };
//	scanf("%d %d", &n, &m);
//	//��ʼ������
//	int i = 0, j = 0, num = 1;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			arr[i][j] = num;
//			arr_tmp[i][j] = num;
//			num++;
//		}
//	}
//	//��Ҫ����ת��z==0Ϊ˳ʱ�룬z==1Ϊ��ʱ��
//	while (m)
//	{
//		int x = 0, y = 0, r = 0, z = 0;
//		scanf("%d %d %d %d", &x, &y, &r, &z);
//		int left = y - 1, right = y + r - 2, up = x - 1, down = x + r - 2;
//		int arr_layer[100][100] = { 0 };
//		//��ȡÿ�����ݣ��ӵ���㿪ʼ
//		int layer = 0;//����
//		int layer_num = (r - layer) * (r - layer) - (r - layer - 2) * (r - layer - 2);//ÿ�����ݸ���
//		int k = 0;//������
//		while (layer < r / 2)
//		{
//			layer_num = (r - layer) * (r - layer) - (r - layer - 2) * (r - layer - 2);
//			for (k = 0; k <= layer_num; k++)
//			{
//				for (i = left; i <= right; i++)
//				{
//					arr_layer[layer][k] = arr[up][i];
//					k++;
//				}
//				for (i = up + 1; i <= down; i++)
//				{
//					arr_layer[layer][k] = arr[i][right];
//					k++;
//				}
//				for (i = right - 1; i >= left; i--)
//				{
//					arr_layer[layer][k] = arr[down][i];
//					k++;
//				}
//				for (i = down - 1; i >= up + 1; i--)
//				{
//					arr_layer[layer][k] = arr[i][left];
//					k++;
//				}
//			}
//			left++, right--, up++, down--;
//			layer++;
//		}
//		if (z == 1)
//		{
//			//arr_layer[layer]ÿ��Ԫ�������ƶ�r-layer-1λ
//			for (i = 0; i <= r / 2; i++)
//			{
//				leftmove(arr_layer[i], (r - i) * (r - i) - (r - i - 2) * (r - i - 2), r - i - 1);
//			}
//		}
//		else if (z == 0)
//		{
//			for (i = 0; i <= r / 2; i++)
//			{
//				rightmove(arr_layer[i], (r - i) * (r - i) - (r - i - 2) * (r - i - 2), r - i - 1);
//			}
//		}
//		//��move������ݷŻ�arr��
//		layer = 0;
//		k = 0;
//		while (layer < r / 2)
//		{
//			layer_num = (r - layer) * (r - layer) - (r - layer - 2) * (r - layer - 2);
//			for (k = 0; k <= layer_num; k++)
//			{
//				for (i = left; i <= right; i++)
//				{
//					arr[up][i] = arr_layer[layer][k];
//					k++;
//				}
//				for (i = up + 1; i <= down; i++)
//				{
//					arr[i][right] = arr_layer[layer][k];
//					k++;
//				}
//				for (i = right - 1; i >= left; i--)
//				{
//					arr[down][i] = arr_layer[layer][k];
//					k++;
//				}
//				for (i = down - 1; i >= up + 1; i--)
//				{
//					arr[i][left] = arr_layer[layer][k];
//					k++;
//				}
//			}
//			left++, right--, up++, down--;
//			layer++;
//		}
//		m--;
//	}
//	//�������
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

////version2
//#include <stdio.h>
//
//void leftmove(int arr[], int len, int r)
//{
//    int i = 0;
//    while (r--)
//    {
//        int tmp = arr[0];
//        for (i = 0; i < len - 1; i++)
//        {
//            arr[i] = arr[i + 1];
//        }
//        arr[len - 1] = tmp;
//    }
//}
//
//void rightmove(int arr[], int len, int r)
//{
//    int i = 0;
//    while (r--)
//    {
//        int tmp = arr[len - 1];
//        for (i = len - 1; i > 0; i--)
//        {
//            arr[i] = arr[i - 1];
//        }
//        arr[0] = tmp;
//    }
//}
//int main()
//{
//    int n = 0; //�����С
//    int m = 0; //��ת����
//    int arr[100][100] = { 0 };
//    scanf("%d %d", &n, &m);
//    //��ʼ������
//    int i = 0, j = 0, num = 1;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            arr[i][j] = num;
//            num++;
//        }
//    }
//    while (m)
//    {
//        int x = 0, y = 0, r = 0, z = 0;
//        scanf("%d %d %d %d", &x, &y, &r, &z);
//        int left = y - 1, right = y + r - 2, up = x - 1, down = x + r - 2;
//        int arr_layer[100][100] = { 0 };
//        //��ȡÿ�����ݣ��ӵ���㿪ʼ
//        int layer = 0; //����
//        int layer_num = (r - layer) * (r - layer) - (r - layer - 2) * (r - layer - 2); //ÿ�����ݸ���
//        int k = 0;  //������
//        while (layer < r / 2 && layer < (r + 1) / 2)
//        {
//            layer_num = (r - layer) * (r - layer) - (r - layer - 2) * (r - layer - 2);
//            for (k = 0; k < layer_num; k++)
//            {
//                for (i = left; i <= right; i++)
//                {
//                    arr_layer[layer][k] = arr[up][i];
//                    k++;
//                }
//                for (i = up + 1; i <= down; i++)
//                {
//                    arr_layer[layer][k] = arr[i][right];
//                    k++;
//                }
//                for (i = right - 1; i >= left; i--)
//                {
//                    arr_layer[layer][k] = arr[down][i];
//                    k++;
//                }
//                for (i = down - 1; i >= up + 1; i--)
//                {
//                    arr_layer[layer][k] = arr[i][left];
//                    k++;
//                }
//            }
//            left++, right--, up++, down--;
//            layer++;
//        }
//
//        //��Ҫ����ת��z==0Ϊ˳ʱ�룬z==1Ϊ��ʱ��
//        if (z == 1)
//        {
//            //arr_layer[layer]ÿ��Ԫ�������ƶ�r-layer-1λ
//            for (i = 0; i < r / 2; i++)
//            {
//                leftmove(arr_layer[i], (r - i) * (r - i) - (r - i - 2) * (r - i - 2), r - i - 1);
//            }
//        }
//
//        if (z == 0)
//        {
//            for (i = 0; i < r / 2; i++)
//            {
//                rightmove(arr_layer[i], (r - i) * (r - i) - (r - i - 2) * (r - i - 2), r - i - 1);
//            }
//        }
//
//        //��move������ݷŻ�arr��
//        layer = 0;
//        k = 0;
//        while (layer < r / 2)
//        {
//            layer_num = (r - layer) * (r - layer) - (r - layer - 2) * (r - layer - 2);
//            for (k = 0; k < layer_num; k++)
//            {
//                for (i = left; i <= right; i++)
//                {
//                    arr[up][i] = arr_layer[layer][k];
//                    k++;
//                }
//                for (i = up + 1; i <= down; i++)
//                {
//                    arr[i][right] = arr_layer[layer][k];
//                    k++;
//                }
//                for (i = right - 1; i >= left; i--)
//                {
//                    arr[down][i] = arr_layer[layer][k];
//                    k++;
//                }
//                for (i = down - 1; i >= up + 1; i--)
//                {
//                    arr[i][left] = arr_layer[layer][k];
//                    k++;
//                }
//            }
//            left++, right--, up++, down--;
//            layer++;
//        }
//        m--;
//    }
//    ////�������
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < n; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}

////version3
//#include <stdio.h>
//
//void rotateLayer(int arr[], int size, int rotation)
//{
//    while (rotation--)
//    {
//        int tmp = arr[0];
//        for (int i = 0; i < size - 1; i++)
//        {
//            arr[i] = arr[i + 1];
//        }
//        arr[size - 1] = tmp;
//    }
//}
//
//int main()
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//
//    int arr[100][100] = { 0 };
//
//    // ��ʼ������
//    int num = 1;
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            arr[i][j] = num++;
//        }
//    }
//
//    while (m--)
//    {
//        int x, y, r, z;
//        scanf("%d %d %d %d", &x, &y, &r, &z);
//
//        int left = y - 1, right = y + r - 2, up = x - 1, down = x + r - 2;
//
//        int layer = 0;
//        while (layer < r / 2)
//        {
//            int layerSize = (r - layer * 2) * 4 - 4;
//            int arrLayer[100] = { 0 };
//
//            int k = 0;
//            for (int i = left; i <= right; i++)
//            {
//                arrLayer[k++] = arr[up][i];
//            }
//            for (int i = up + 1; i <= down; i++)
//            {
//                arrLayer[k++] = arr[i][right];
//            }
//            for (int i = right - 1; i >= left; i--)
//            {
//                arrLayer[k++] = arr[down][i];
//            }
//            for (int i = down - 1; i >= up + 1; i--)
//            {
//                arrLayer[k++] = arr[i][left];
//            }
//
//            // ������ת�������������
//            for (int i = 0; i <= layer; i++)
//            {
//                if (z == 1)
//                {
//                    rotateLayer(arrLayer, layerSize, r - layer - 1);
//                }
//                else if (z == 0)
//                {
//                    rotateLayer(arrLayer, layerSize, layer - i);
//                }
//            }
//
//            k = 0;
//            for (int i = left; i <= right; i++)
//            {
//                arr[up][i] = arrLayer[k++];
//            }
//            for (int i = up + 1; i <= down; i++)
//            {
//                arr[i][right] = arrLayer[k++];
//            }
//            for (int i = right - 1; i >= left; i--)
//            {
//                arr[down][i] = arrLayer[k++];
//            }
//            for (int i = down - 1; i >= up + 1; i--)
//            {
//                arr[i][left] = arrLayer[k++];
//            }
//
//            // ���±߽�ֵ
//            left++, right--, up++, down--;
//            layer++;
//        }
//    }
//
//    // �������
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

////version4
/*
#include <stdio.h>

void shunshizhen(int matrix[][100], int x, int y, int r) {
    int temp[10000];
    int n = sizeof(matrix) / sizeof(matrix[0]);

    int k = 0;
    for (int i = x - 1; i < x + r - 1; i++) {
        for (int j = y - 1; j < y + r - 1; j++) {
            temp[k++] = matrix[i][j];
        }
    }

    k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            matrix[x - 1 + j][y - 1 + r - 1 - i] = temp[i * r + j];
        }
    }
}

void nishizhen(int matrix[][100], int x, int y, int r) {
    int temp[10000];
    int n = sizeof(matrix) / sizeof(matrix[0]);

    int k = 0;
    for (int i = x - 1; i < x + r - 1; i++) {
        for (int j = y - 1; j < y + r - 1; j++) {
            temp[k++] = matrix[i][j];
        }
    }

    k = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            matrix[x - 1 + r - 1 - j][y - 1 + i] = temp[i * r + j];
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[100][100];

    // ��ʼ������
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = num++;
        }
    }

    for (int i = 0; i < m; i++) {
        int x, y, r, z;
        scanf("%d %d %d %d", &x, &y, &r, &z);

        if (z == 0) {
            shunshizhen(matrix, x, y, r);
        }
        else {
            nishizhen(matrix, x, y, r);
        }
    }

    // �������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/






