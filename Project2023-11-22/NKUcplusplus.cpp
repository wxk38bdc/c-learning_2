#define _CRT_SECURE_NO_WARNINGS 1
//ר��ѧУ��ϰʱдC++����

//#include<iostream>
//#include<cstdio>
//using namespace std;
//struct stu {
//	char name[10];
//	int age;
//	int height;
//};
//stu operator+(stu a,int b)
//{
//	a.age += b;
//	return a;
//}
//int main()
//{
//	stu s1 = { "zhangsan",20,180 };
//	stu s2 = s1 + 2;
//	cout << s2.name<<' '<<s2.age<<' '<<s2.height << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int fun(int a, int b) {
//	static int n = 2;
//	int m = 0;
//	n = n + m + a;
//	m = m + n + b;
//	return m;
//}
//int main() {
//	int x = 4, y = 1, r1, r2;
//	r1 = fun(x, y);
//	r2 = fun(x, y);
//	cout << r1 << ','<<r2<<endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//char min(char a, char b)
//{
//	return (a < b) ? : a : b;
//}
////����ģ��
//template <typename T> T min(T a, T b)
//{
//	return (a < b) ? a : b;
//}
////һ��������2��ģ��
//template <typename T1, typename T2> bool if_min(T1 a, T2 b)
//{
//	return (a < b) ? a : b;
//}
//int main()
//{
//	cout << min('a', 'b') << endl;//����char min(char a, char b)
//	cout << min(12, 24) << endl;//����int min(int a, int b)
//	cout << min(12.5, 24.5) << endl;//����double min(double a, double b)
//	return 0;
//}

//#include <iostream>
//using namespace std;
////����
//int x[4] = { 0 };
//void search(int k)
//{
//	if (k > 3)
//	{
//		cout << x[0] << x[1] << x[2] <<x[3]<< endl;
//	}
//	else
//	{
//		for (int i = 1; i <= 4; i++)
//		{
//			x[k] = i;
//			search(k + 1);
//		}
//	}
//}
//int main()
//{
//	search(0);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include<cstdio>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0, j = 0;
//	int arr[41][41] = { 0 };
//	arr[0][n / 2] = 1;
//	int num = 0;
//	int row = 0, col = n / 2;
//
//	for (num = 2; num <= n*n; num++)
//	{
//		if (row == 0 && col != n - 1)
//		{
//			row = n - 1;
//			col++;
//			arr[row][col] = num;
//		}
//		else if (col == n - 1 && row != 0)
//		{
//			col = 0;
//			row--;
//			arr[row][col] = num;
//		}
//		else if (row == 0 && col == n-1)
//		{
//			row++;
//			arr[row][col] = num;
//		}
//		else if (row != 0 && col != n - 1)
//		{
//			if (arr[row - 1][col + 1] == 0)
//			{
//				row--;
//				col++;
//				arr[row][col] = num;
//			}
//			else
//			{
//				row++;
//				arr[row][col] = num;
//			}
//		}
//	}
//	//���
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

//#include <iostream>
//using namespace std;
//#include<cstdio>
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0, j = 0;
//    int arr[41][41] = { 0 };
//    arr[0][n / 2] = 1;
//    int num = 2;
//    int row = 0, col = n / 2;
//
//    while (num <= (n * n)) {
//        int nextRow = (row - 1 + n) % n;
//        int nextCol = (col + 1) % n;
//
//        if (arr[nextRow][nextCol] == 0) {
//            row = nextRow;
//            col = nextCol;
//        }
//        else {
//            row = (row + 1) % n;
//        }
//
//        arr[row][col] = num;
//        num++;
//    }
//
//    // ���
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            printf("%d ", arr[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//#include<cstdio>
//#include<climits>
//char a[101][101] = { 0 };//�Թ���+��ʾ�ϰ���-��ʾ���ߣ�S��ʾ��㣬E��ʾ�յ�
//int b[101][101] = { INT_MAX };//b[i][j]��ʾ����㵽(i,j)�����·��
//int m,n,x_E,y_E,x_S,y_S;//m,n��ʾ�Թ���������������x_E,y_E��ʾ�յ�����꣬x_S,y_S��ʾ��������
//void DFS(int x, int y, int step)//x,y��ʾ��ǰλ�õ����꣬step��ʾ��ǰ�ߵĲ���
//{
//	if (x < 0 || x >= m || y < 0 || y >= n || a[x][y] == '+' || step >= b[x][y])//�����ǰλ�ò��Ϸ����ߵ�ǰ�������ڵ���b[x][y]���򷵻�
//	{
//		return;
//	}
//	b[x][y] = step;//����b[x][y]
//	DFS(x + 1, y, step + 1);//������
//	DFS(x - 1, y, step + 1);//������
//	DFS(x, y + 1, step + 1);//������
//	DFS(x, y - 1, step + 1);//������
//}
//int main()
//{
//	cin >> m >> n;//��������������
//	for (int i = 0; i < m; i++)//�����Թ�
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf(" %c", &a[i][j]);//ע��%cǰ��Ŀո񣬷������뻻�з�
//			if (a[i][j] == 'S')//��������
//			{
//				x_S = i;//��¼��������
//				y_S = j;
//			}
//			if (a[i][j] == 'E')//������յ�
//			{
//				x_E = i;//��¼�յ������
//				y_E = j;
//			}
//		}
//	}
//	for (int i = 0; i < m; i++)//��ʼ��b[i][j]
//	{
//		for (int j = 0; j < n; j++)
//		{
//			b[i][j] = INT_MAX;
//		}
//	}
//	DFS(x_S, y_S, 0);//����㿪ʼ����
//	if (b[x_E][y_E] == INT_MAX)//���b[x_E][y_E]û�б����£�˵�������յ㲻��ͨ
//	{
//		cout << -1 << endl;
//	}
//	else//�������b[x_E][y_E]
//	{
//		cout << b[x_E][y_E] << endl;
//	}
//	return 0;
//}