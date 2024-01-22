#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

//void Swap(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//void bubbleSort(int arr[], int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				Swap(&arr[j], &arr[j + 1]);
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
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubbleSort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, numberOfGuesses;
    time_t t;

    // 初始化随机数生成器
    srand((unsigned)time(&t));

    // 生成1到100之间的随机数
    randomNumber = rand() % 100 + 1;

    numberOfGuesses = 0;

    printf("猜猜看我心里想的是哪个数字（1到100）：\n");

    do {
        scanf("%d", &guess);
        numberOfGuesses++;

        if (guess > randomNumber) {
            printf("太高了，再试试看：\n");
        }
        else if (guess < randomNumber) {
            printf("太低了，再试试看：\n");
        }
    } while (guess != randomNumber);

    printf("恭喜你，猜对了！你一共猜了%d次。\n", numberOfGuesses);

    return 0;
}
