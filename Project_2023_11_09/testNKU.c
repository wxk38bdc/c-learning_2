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

