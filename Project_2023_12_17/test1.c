#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//long long func(int n)
//{
//	long long ret = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (n % i == 0)
//		{
//			ret++;
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	long long sum = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		sum += func(i);
//	}
//	printf("%lld\n", sum);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//
//    // ʹ�� malloc ��̬�����ڴ�
//    long long* factorCounts = (long long*)malloc((n + 1) * sizeof(long long));
//    if (factorCounts == NULL) {
//        // ����ڴ����ʧ�ܣ����˳�
//        printf("Memory allocation failed\n");
//        return 1;
//    }
//
//    // ��ʼ��������������
//    for (int i = 0; i <= n; i++) {
//        factorCounts[i] = 0;
//    }
//
//    // ����ÿ��������������
//    for (int i = 1; i <= n; i++) {
//        for (int j = i; j <= n; j += i) {
//            factorCounts[j]++;
//        }
//    }
//
//    // �����ܵ���������
//    long long sum = 0;
//    for (int i = 1; i <= n; i++) {
//        sum += factorCounts[i];
//    }
//
//    printf("%lld\n", sum);
//
//    // �ͷŶ�̬������ڴ�
//    free(factorCounts);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//void reverse(char*left)
//{
//	int len=strlen(left);
//	char* right = left + len - 1;
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
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
//int main()
//{
//	char s[30] = { 0 };
//	scanf("%s", s);
//	int flag = 0;
//	int len = strlen(s);
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		if(s[i]=='.')
//		{
//			flag = 1;
//			break;
//		}
//		if (s[i] == '/')
//		{
//			flag = 2;
//			break;
//		}
//		if(s[i]=='%')
//		{
//			flag = 3;
//			break;
//		}
//	}
//	if (flag == 0)
//	{
//		reverse(s);
//		processstrings(s);
//		printf(s);
//	}
//	else if (flag == 1)
//	{
//		char* s1 = strtok(s, ".");
//		char* s2 = strtok(NULL, ".");
//		reverse(s1);
//		processstrings(s1);
//		reverse(s2);
//		for(i=strlen(s2)-1;i>=0;i--)
//		{
//			if (s2[i] != '0')
//			{
//				break;
//			}
//			else if(i>=1)
//			{
//				s2[i] = '\0';
//			}
//		}
//		printf("%s.", s1);
//		printf("%s", s2);
//	}
//else if (flag == 2)
//	{
//		char* s1 = strtok(s, "/");
//		char* s2 = strtok(NULL, "/");
//		reverse(s1);
//		processstrings(s1);
//		reverse(s2);
//		processstrings(s2);
//		printf("%s/", s1);
//		printf("%s", s2);
//	}
//	else if (flag == 3)
//	{
//		char* s1 = strtok(s, "%");
//		reverse(s1);
//		processstrings(s1);
//		printf("%s%%", s1);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#include<ctype.h>
//int main()
//{
//	char tofind[11] = { 0 };
//	char str[1000001] = { 0 };
//	fgets(tofind, 11, stdin);
//	fgets(str, 1000001, stdin);
//	int lent=strlen(tofind);
//	int lens = strlen(str);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < lent; i++)
//	{
//		tofind[i]=tolower(tofind[i]);
//	}
//	for (i = 0; i < lens; i++)
//	{
//		str[i] = tolower(str[i]);
//	}
//	tofind[lent - 1] = '\0';
//	lent--;
//	str[lens - 1] = '\0';
//	lens--;
//	//   ii ii  iiii  oiii    i 3 1 2 2 4
//	int space[100000] = { 0 };//�洢ÿ������ǰ�Ŀո���
//    int inWord = 0; // ����Ƿ��ڵ����ڲ�
//    for (i = 0; i < lens; i++) {
//        if (str[i] == ' ') {
//            if (inWord) {
//                // ���֮ǰ�ڵ����У����������ո񣬱�ʾ���ʽ���
//                inWord = 0;
//                j++; // �ƶ�����һ������
//            }
//            else {
//                // ������ڵ����У��ۼӿո�����
//                space[j]++;
//            }
//        }
//        else {
//            // ������ǿո񣬱�����ڴ�����
//            inWord = 1;
//        }
//    }
//    // ȷ�����ʽ���ʱ������ȷ
//    if (inWord) {
//        j++;
//    }
//    for (i = 0; i < j; i++)
//    {
//        if (i != 0)
//        {
//            space[i]++;
//        }
//    }
//	char words[20000][70] = { 0 };
//	int wordsnum = 0;
//	
//	char* p = strtok(str, " ");
//	while (p != NULL)
//	{
//		strcpy(words[wordsnum++], p);
//		p = strtok(NULL, " ");
//	}
//	//ͳ�Ƶ��ʳ��ֵĴ���
//	int flag = 0;
//	int first_index= 0;
//	int count = 0;
//	for (i = 0; i < wordsnum; i++)
//	{
//		if (strcmp(words[i], tofind) == 0)
//		{
//			count++;
//		}
//		if (count == 1&&flag==0)
//		{
//			flag = 1;
//			first_index = i;
//		}
//	}
//	if(count==0)
//	{
//		printf("-1\n");
//		return 0;
//	}
//	printf("%d ", count);
//	//printf("��һ��������%d\n", first_index);
//	int sum = 0;
//	for (i = 0; i <= first_index; i++)
//	{
//		sum=sum+space[i] + strlen(words[i]);
//		//if (i != first_index)
//		//{
//		//	sum=sum+strlen(words[i-1]);
//		//}
//	}
//	sum=sum-strlen(words[first_index]);
//	//printf("first index=%d\n", first_index);
//	printf("%d\n", sum);
//	//printf("********************\n");
//	//for (i = 0; i < wordsnum; i++)
//	//{
//	//	printf("%d\n", space[i]);
//	//	printf("%s\n", words[i]);
//	//	printf("%d\n", strlen(words[i]));
//	//}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//int main()
//{
//char tofind[11] = { 0 };
//char str[100001] = { 0 };
//fgets(tofind, 11, stdin);
//fgets(str, 100001, stdin);
//int lent=strlen(tofind);
//int lens = strlen(str);
//int i = 0;
//    int space[10000] = { 0 }; // �洢ÿ������ǰ�Ŀո���
//    int j = 0; // ��������
//    int inWord = 0; // ����Ƿ��ڵ����ڲ�
//
//    for (i = 0; i < lens; i++) {
//        if (str[i] == ' ') {
//            if (inWord) {
//                // ���֮ǰ�ڵ����У����������ո񣬱�ʾ���ʽ���
//                inWord = 0;
//                j++; // �ƶ�����һ������
//            }
//            else {
//                // ������ڵ����У��ۼӿո�����
//                space[j]++;
//            }
//        }
//        else {
//            // ������ǿո񣬱�����ڴ�����
//            inWord = 1;
//        }
//    }
//    // ȷ�����ʽ���ʱ������ȷ
//    if (inWord) {
//        j++;
//    }
//    for (i = 0; i < j; i++)
//    {
//        if (i != 0)
//        {
//            space[i]++;
//        }
//    }
//    //���ÿ������ǰ�Ŀո���
//for (i = 0; i < j; i++) {
//    printf("%d ", space[i]);
//}
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//int main() {
//    char tofind[11] = { 0 };
//    char str[100001] = { 0 };
//    fgets(tofind, 11, stdin);
//    fgets(str, 100001, stdin);
//
//    // �Ƴ����з�
//    if (str[strlen(tofind) - 1] == '\n') tofind[strlen(tofind) - 1] = '\0';
//    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
//
//    // ת��ΪСд
//    for (int i = 0; i<strlen(tofind); i++) {
//        tofind[i] = tolower(tofind[i]);
//    }
//    for (int i = 0; i<strlen(str); i++) {
//        str[i] = tolower(str[i]);
//    }
//
//    char words[10000][50] = { 0 };
//    int spaces[10000] = { 0 }; // �洢ÿ������ǰ�Ŀո���
//    int worsnum = 0, spaceCount = 0, index = 0;
//
//    while (str[index]) {
//        if (str[index] == ' ') {
//            spaceCount++;
//            index++;
//            continue;
//        }
//
//        int wordStart = index;
//        while (str[index] && str[index] != ' ') {
//            index++;
//        }
//
//        strncpy(words[worsnum], str + wordStart, index - wordStart);
//        words[worsnum][index - wordStart] = '\0';
//        spaces[worsnum] = spaceCount;
//        spaceCount = 1; // Ϊ��һ���������ÿո����
//        worsnum++;
//    }
//
//    // ͳ�Ƶ��ʳ��ֵĴ���
//    int first_index = -1, count = 0;
//    for (int i = 0; i < worsnum; i++) {
//        if (strcmp(words[i], tofind) == 0) {
//            count++;
//            if (first_index == -1) first_index = i;
//        }
//    }
//
//    if (count == 0) {
//        printf("-1\n");
//    }
//    else {
//        printf("%d ", count);
//        int sum = 0;
//        for (int i = 0; i <= first_index; i++) {
//            sum += strlen(words[i]) + spaces[i];
//        }
//        printf("%d\n", sum); // ��������һ�γ��ֵ���ǰ�Ŀո�
//    }
//
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int compareint(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int main()
//{
//
//	int m = 0;
//	scanf("%d",  &m);
//	int k = 0;
//	scanf("%d", &k);
//	int* arr = (int*)malloc(sizeof(int) * m);
//	int i = 0;
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, m, sizeof(int), compareint);
//	printf("%d ", arr[k]);
//	free(arr);
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int compareint(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int main()
//{
//	int m = 0, n = 0;
//	scanf("%d %d", &m, &n);
//	int* arr = (int*)malloc(sizeof(int) * (m + n));
//	int i = 0;
//	for (i = 0; i < m+n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, m + n, sizeof(int), compareint);
//	for (i = 0; i < m + n; i++)
//	{
//		if(i==0||arr[i]!=arr[i-1])
//			printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include<stdio.h>
////������������ͻ�ת���
//int main()
//{
//	int arr[11][11] = { 0 };
//	int row = 0, col = 0, i = 0, j = 0;
//	scanf("%d%d", &row, &col);
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	//�������
//	for (i = 0; i < row; i++)
//	{
//		if (i % 2 == 0)
//		{
//			for (j = 0; j < col; j++)
//			{
//				printf("%d ", arr[i][j]);
//			}
//		}
//		else
//		{
//			for (j = col - 1; j >= 0; j--)
//			{
//				printf("%d ", arr[i][j]);
//			}
//		}
//	}
//	printf("\n");
//	//�������:���������㣬������ڲ㣬ֱ����������ĵ�һ��Ԫ��
//	int left = 0, right = col - 1, up = 0, down = row - 1;
//	while (left <= right && up <= down)
//	{
//		for (i = left; i <= right; i++)
//		{
//			printf("%d ", arr[up][i]);
//		}
//		for (i = up + 1; i <= down; i++)
//		{
//			printf("%d ", arr[i][right]);
//		}
//		if (up != down)
//		{
//			for (i = right - 1; i >= left; i--)
//			{
//				printf("%d ", arr[down][i]);
//			}
//		}
//		if (left != right)
//		{
//			for (i = down - 1; i > up; i--)
//			{
//				printf("%d ", arr[i][left]);
//			}
//		}
//		left++;
//		right--;
//		up++;
//		down--;
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int compareint(const void* a, const void* b)
//{
//	return *(int*)a - *(int*)b;
//}
//int main()
//{
//	int n;
//	int m = 0;
//	scanf("%d",&m);
//
//	int* arr = (int*)malloc(sizeof(int) * m);
//	int i = 0;
//	for (i = 0; i < m; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, m, sizeof(int), compareint);
//	int num = 0;
//	for (i = 0; i < m; i++)
//	{
//		if (i == 0 || arr[i] != arr[i - 1])
//		{
//			num++;
//		}
//	}	
//	printf("%d\n", num);
//	for (i = 0; i < m; i++)
//	{
//		if (i == 0 || arr[i] != arr[i - 1])
//		{
//			printf("%d ", arr[i]);
//		}
//	}
//	free(arr);
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//typedef struct stu {
//	int id;
//	int cn;
//	int ma;
//	int en;
//	int sum;
//}stu;
//int compare(const void* e1, const void* e2)
//{
//	stu* s1 = (stu*)e1;
//	stu* s2 = (stu*)e2;
//	if (s1->sum != s2->sum)
//	{
//		return s2->sum - s1->sum;
//	}
//	else if (s1->cn != s2->cn)
//	{
//		return s2->cn - s1->cn;
//	}
//	else if (s1->id != s2->id)
//	{
//		return s1->id - s2->id;
//	}
//	else {
//		return 0;
//	}
//}
//int main()
//{
//	int n = 0;
//	int i = 0;
//	scanf("%d", &n);
//	stu* arr = (stu*)malloc(sizeof(stu) * n);
//	for(i=0;i<n;i++)
//	{
//		arr[i].id = i + 1;
//		scanf("%d %d %d",&arr[i].cn, &arr[i].ma, &arr[i].en);
//		arr[i].sum = arr[i].cn + arr[i].ma + arr[i].en;
//	}
//	qsort(arr, n, sizeof(stu), compare);
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d %d\n", arr[i].id, arr[i].sum);
//	}
//	return 0;
//}

//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int compare(const void* e1, const void* e2)
//{
//	char*s1 = (char*)e1;
//	char*s2 = (char*)e2;
//	if(strlen(s1)!=strlen(s2))
//	{
//		return strlen(s1) - strlen(s2);
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
//	char arr[20][150] = { 0 };
//	char arr_copy[20][150] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%s", arr[i]);
//		strcpy(arr_copy[i], arr[i]);
//	}
//	qsort(arr,n,150,compare);
//	
//	for(i=0; i < n; i++)
//	{
//		if (strcmp(arr_copy[i], arr[n - 1]) == 0)
//		{
//			printf("%d\n", i+1);
//		}
//	}
//	printf("%s\n", arr[n - 1]);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//#define MAX_DIGITS 200  // �������λ��
//
//// ��������ת�ַ���
//void reverseString(char* str) {
//    int length = strlen(str);
//    for (int i = 0; i < length / 2; i++) {
//        char temp = str[i];
//        str[i] = str[length - 1 - i];
//        str[length - 1 - i] = temp;
//    }
//}
//
//// �������߾��ȼӷ�
//void addLargeNumbers(char* num1, char* num2, char* result) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//    int carry = 0;
//    int i = 0;
//
//    // ��ת�ַ����Ա�����λ��ʼ���
//    reverseString(num1);
//    reverseString(num2);
//    
//
//    // ִ�мӷ�����
//    for (; i < length1 || i < length2 || carry; i++) {
//        int digit1 = i < length1 ? num1[i] - '0' : 0;
//        int digit2 = i < length2 ? num2[i] - '0' : 0;
//        int sum = digit1 + digit2 + carry;
//        result[i] = (sum % 10) + '0';  // �洢��ǰλ�Ľ��
//        carry = sum / 10;              // �����λ
//    }
//    result[i] = '\0';  // ����ַ���������
//
//    // �ٴη�ת�õ����ս��
//    reverseString(result);
//}
//
//int main() {
//    char num1[MAX_DIGITS];
//    char num2[MAX_DIGITS];
//    char result[MAX_DIGITS + 1];  // �洢�����������Ҫ�����һλ���ڽ�λ
//
//    printf("Enter first number: ");
//    scanf("%s", num1);
//    printf("Enter second number: ");
//    scanf("%s", num2);
//
//    addLargeNumbers(num1, num2, result);
//    printf("Sum: %s\n", result);
//
//    return 0;
//}


//�߾��ȼӼ���
//#include <stdio.h>
//#include <string.h>
//
//#define MAX_DIGITS 200  // �������λ��
//
//// ��������ת�ַ���
//void reverseString(char* str) {
//    int length = strlen(str);
//    for (int i = 0; i < length / 2; i++) {
//        char temp = str[i];
//        str[i] = str[length - 1 - i];
//        str[length - 1 - i] = temp;
//    }
//}
//
//// �������Ƚ��������Ĵ�С
//int compareNumbers(char* num1, char* num2) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//
//    if (length1 != length2) {
//        return length1 > length2 ? 1 : -1;
//    }
//
//    for (int i = 0; i < length1; i++) {
//        if (num1[i] != num2[i]) {
//            return num1[i] > num2[i] ? 1 : -1;
//        }
//    }
//
//    return 0;  // �������
//}
//
//// �������߾��ȼӷ�
//void addLargeNumbers(char* num1, char* num2, char* result) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//    int carry = 0;
//    int i = 0;
//
//    reverseString(num1);
//    reverseString(num2);
//
//    for (; i < length1 || i < length2 || carry; i++) {
//        int digit1 = i < length1 ? num1[i] - '0' : 0;
//        int digit2 = i < length2 ? num2[i] - '0' : 0;
//        int sum = digit1 + digit2 + carry;
//        result[i] = (sum % 10) + '0';
//        carry = sum / 10;
//    }
//    result[i] = '\0';
//
//    reverseString(result);
//}
//
//// �������߾��ȼ���
//void subtractLargeNumbers(char* num1, char* num2, char* result) {
//    int length1 = strlen(num1);
//    int length2 = strlen(num2);
//    int borrow = 0;
//    int i = 0;
//    // ��� num1 < num2���򽻻�������
//    if (compareNumbers(num1, num2) < 0) {
//        char* temp = num1;
//        num1 = num2;
//        num2 = temp;
//
//        int tempLength = length1;
//        length1 = length2;
//        length2 = tempLength;
//    }
//
//    reverseString(num1);
//    reverseString(num2);
//
//    for (; i < length1; i++) {
//        int digit1 = i < length1 ? num1[i] - '0' : 0;
//        int digit2 = i < length2 ? num2[i] - '0' : 0;
//        int diff = digit1 - digit2 - borrow;
//
//        if (diff < 0) {
//            diff += 10;
//            borrow = 1;
//        }
//        else {
//            borrow = 0;
//        }
//
//        result[i] = diff + '0';
//    }
//
//    while (i > 1 && result[i - 1] == '0') {
//        i--;
//    }
//    result[i] = '\0';
//
//    reverseString(result);
//}
//
//int main() {
//    char num1[MAX_DIGITS];
//    char num2[MAX_DIGITS];
//    char result[MAX_DIGITS + 1];
//    int operation;
//
//    printf("Enter first number: ");
//    scanf("%s", num1);
//    printf("Enter second number: ");
//    scanf("%s", num2);
//    printf("Choose operation (1 for addition, 2 for subtraction): ");
//    scanf("%d", &operation);
//
//    if (operation == 1) {
//        addLargeNumbers(num1, num2, result);
//        printf("Sum: %s\n", result);
//    }
//    else if (operation == 2) {
//        subtractLargeNumbers(num1, num2, result);
//        printf("Difference: %s\n", result);
//    }
//    else {
//        printf("Invalid operation.\n");
//    }
//
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int bubblesort(int* arr, int n)
//{
//	int i = 0;
//	int j = 0;
//	int flag = 0;
//	int sortnum = 0;
//	for (i = 0; i < n - 1; i++)
//	{
//		flag = 0;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 1;
//				sortnum++;
//			}
//		}
//		if (flag == 0)
//		{
//			break;
//		}
//	}
//	return sortnum;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int* arr = (int*)malloc(sizeof(int) * n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int sortnum = bubblesort(arr, n);
//	printf("%d\n", sortnum);
//	free(arr);
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//    int n;
//    scanf("%d", &n);
//
//    int* arr = (int*)malloc(n * sizeof(int));
//    int* diffs = (int*)calloc(n, sizeof(int));  // ��ʼ��Ϊ0
//
//    // ��ȡ����
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    // �����ľ���ֵ�����
//    for (int i = 0; i < n - 1; i++) {
//        int diff = abs(arr[i] - arr[i + 1]);
//        if (diff < n) {
//            diffs[diff] = 1;  // ��ǲ�ֵ
//        }
//    }
//
//    // ����Ƿ����в�ֵ�������
//    int jolly = 1;  // ������Jolly
//    for (int i = 1; i < n; i++) {
//        if (diffs[i] == 0) {
//            jolly = 0;  // ����δ��ǵĲ�ֵ
//            break;
//        }
//    }
//
//    if (jolly) {
//        printf("Jolly\n");
//    }
//    else {
//        printf("Not jolly\n");
//    }
//
//    // �ͷ��ڴ�
//    free(arr);
//    free(diffs);
//
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//
//struct ListNode* insertionSortList(struct ListNode* head) {
//    if (head == NULL || head->next == NULL) {
//        return head;
//    }
//
//    struct ListNode* sorted = NULL; // �µ����������ͷ�ڵ�
//    struct ListNode* current = head; // ��ǰҪ����Ľڵ�
//
//    while (current != NULL) {
//        struct ListNode* next = current->next; // ������һ���ڵ�
//
//        // Ѱ�Ҳ���λ��
//        if (sorted == NULL || sorted->val >= current->val) {
//            // ���뵽ͷ��
//            current->next = sorted;
//            sorted = current;
//        }
//        else {
//            // ����������������ҵ������
//            struct ListNode* tmp = sorted;
//            while (tmp->next != NULL && tmp->next->val < current->val) {
//                tmp = tmp->next;
//            }
//            // ���뵽tmp�ڵ�֮��
//            current->next = tmp->next;
//            tmp->next = current;
//        }
//
//        current = next; // �ƶ�����һ��Ҫ����Ľڵ�
//    }
//
//    return sorted;
//}
//
//// ������������ӡ����
//void printList(struct ListNode* head) {
//    struct ListNode* temp = head;
//    while (temp != NULL) {
//        printf("%d ", temp->val);
//        temp = temp->next;
//    }
//    printf("\n");
//}
//
//// ����������ʾ����
//int main() {
//    // �����������һЩ�ڵ�
//    // ʾ����1 -> 4 -> 3 -> 2 -> NULL
//    struct ListNode* head = malloc(sizeof(struct ListNode));
//    head->val = 1;
//    head->next = malloc(sizeof(struct ListNode));
//    head->next->val = 4;
//    head->next->next = malloc(sizeof(struct ListNode));
//    head->next->next->val = 3;
//    head->next->next->next = malloc(sizeof(struct ListNode));
//    head->next->next->next->val = 2;
//    head->next->next->next->next = NULL;
//
//    printf("Original List: ");
//    printList(head);
//
//    struct ListNode* sorted = insertionSortList(head);
//
//    printf("Sorted List: ");
//    printList(sorted);
//
//    // �ͷ��ڴ�
//    // ��ʵ��Ӧ���У�ȷ���ʵ��ͷ������ѷ�����ڴ�
//    // ...
//
//    return 0;
//}


//#include<stdio.h>
////ȥ�أ�Ԥ���޸�Ϊ2,4,6,9�������ظ�Ԫ��ȫ���Ƶ�����ĩβ
//int quchong(int arr[], int n)
//{
//	int i = 0, j = 0;
//	int ret = 0;
//	
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,1,2,3,3,4,5,5,6,7,7,7,8,8,9,0,0 };
//	int ret=quchong(arr,17);//����ȥ�غ������Ԫ�ظ���
//	printf("ret=%d\n", ret);
//	for (int i = 0; i < ret; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}