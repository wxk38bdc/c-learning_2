#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int q;
	scanf("%d", &q);
	char s[101] = "0";
	scanf("%s", s);
	char str1[101] = "0";
	char str2[101] = "0";
	char str3[101] = "0";
	char str4[101] = "0";
	for (int j = 1; j <= q; j++)
	{
		int i;
		scanf("%d", &i);
		if (i == 1)
		{
			scanf("%s", str1);
			strcat(s, str1);
			printf("%s\n", s);
		}
		else if (i == 2)
		{
			int len = strlen(s);
			int a, b;
			int m = 0;
			scanf("%d%d", &a, &b);
			for (int k = 0; k < len; k++)
			{
				if (k >= a && k < a + b)
				{
					str2[m] = s[k];
					m++;
				}
			}
			strcpy(s, str2);
			printf("%s\n", s);
		}

		else if (i == 3)
		{
			//printf("\n%s\n", s);
			int a;
			scanf("%d %s", &a, str3);
			int len1 = strlen(str3);
			int len2 = strlen(s);
			for (int j = a; j <= len2 - 1; j++)
			{
				s[j + len1] = s[j];
			}
			//for (int n = a; n < len1 + a; n++)
			//{
			//	s[n] = 'v';
			//}
			printf("%d\n", (int)s[3]);
			printf("%s\n", s);
						printf("sµÄÇ°19Î»:\n");
						for(int i=0;i<20;i++)printf("s[%d]=%c\n",i,s[i]);
						printf("\n");
			for (int k = 0; k < len1; k++, a++)
			{
				s[a] = str3[k];
			}
			printf("%s\n", s);
		}
		else
		{
			scanf("%s", str4);
			getchar();
			int len1 = strlen(str4);
			int len2 = strlen(s);
			int count = 0;
			int result;
			for (int j = 0; j <= len2 - len1; j++)
			{
				for (int k = 0; k < len1; k++)
				{
					if (s[j + k] == str4[k])
					{
						count++;
					}
				}
				if (count == len1)
				{
					result = j;
					printf("%d\n", result);
					goto end;
				}
				else
				{
					count = 0;
				}
			}
			printf("-1\n");
		end:;
		}
	}
	return 0;
}