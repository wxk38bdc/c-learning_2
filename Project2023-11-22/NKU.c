#define _CRT_SECURE_NO_WARNINGS 1
////ר��ѧУ��ϰʱдC����
//// T401377 ½���Ͻ��ķ���
//#include <stdio.h>
////˼·���Ա���תǰ������꣬�ҵ��任��ʽ
//void shunshizhen(int matrix[][100], int x, int y, int r)
//{
//    int temp[100 * 100];
//    int n = sizeof(matrix) / sizeof(matrix[0]);
//
//    int k = 0;
//    for (int i = x - 1; i < x + r - 1; i++) 
//    {
//        for (int j = y - 1; j < y + r - 1; j++) 
//        {
//            temp[k++] = matrix[i][j];
//        }
//    }
//
//    k = 0;
//    for (int i = 0; i < r; i++) 
//    {
//        for (int j = 0; j < r; j++) 
//        {
//            matrix[x - 1 + j][y - 1 + r - 1 - i] = temp[i * r + j];
//        }
//    }
//}
//
//void nishizhen(int matrix[][100], int x, int y, int r) {
//    int temp[100 * 100];
//    int n = sizeof(matrix) / sizeof(matrix[0]);
//
//    int k = 0;
//    for (int i = x - 1; i < x + r - 1; i++) {
//        for (int j = y - 1; j < y + r - 1; j++) {
//            temp[k++] = matrix[i][j];
//        }
//    }
//
//    k = 0;
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < r; j++) {
//            matrix[x - 1 + r - 1 - j][y - 1 + i] = temp[i * r + j];
//        }
//    }
//}
//
//int main() 
//{
//    int n, m;
//    scanf("%d %d", &n, &m);
//    int matrix[100][100];
//    // ��ʼ������
//    int num = 1;
//    for (int i = 0; i < n; i++) 
//    {
//        for (int j = 0; j < n; j++) 
//        {
//            matrix[i][j] = num;
//            num++;
//        }
//    }
//    // ��ת����
//    while(m--)
//    {
//        int x, y, r, z;
//        scanf("%d %d %d %d", &x, &y, &r, &z);
//        if (z == 0) 
//        {
//            shunshizhen(matrix, x, y, r);
//        }
//        else if (z == 1)
//        {
//            nishizhen(matrix, x, y, r);
//        }
//    }
//    // �������
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++) 
//        {
//            printf("%d ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}