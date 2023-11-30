#define _CRT_SECURE_NO_WARNINGS 1
//专用学校练习时写C++代码

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
////函数模板
//template <typename T> T min(T a, T b)
//{
//	return (a < b) ? a : b;
//}
////一个函数用2个模板
//template <typename T1, typename T2> bool if_min(T1 a, T2 b)
//{
//	return (a < b) ? a : b;
//}
//int main()
//{
//	cout << min('a', 'b') << endl;//调用char min(char a, char b)
//	cout << min(12, 24) << endl;//调用int min(int a, int b)
//	cout << min(12.5, 24.5) << endl;//调用double min(double a, double b)
//	return 0;
//}

//#include <iostream>
//using namespace std;
////回溯
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
//	//输出
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
//    // 输出
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
//char a[101][101] = { 0 };//迷宫，+表示障碍，-表示可走，S表示起点，E表示终点
//int b[101][101] = { INT_MAX };//b[i][j]表示从起点到(i,j)的最短路径
//int m,n,x_E,y_E,x_S,y_S;//m,n表示迷宫的行数和列数，x_E,y_E表示终点的坐标，x_S,y_S表示起点的坐标
//void DFS(int x, int y, int step)//x,y表示当前位置的坐标，step表示当前走的步数
//{
//	if (x < 0 || x >= m || y < 0 || y >= n || a[x][y] == '+' || step >= b[x][y])//如果当前位置不合法或者当前步数大于等于b[x][y]，则返回
//	{
//		return;
//	}
//	b[x][y] = step;//更新b[x][y]
//	DFS(x + 1, y, step + 1);//向下走
//	DFS(x - 1, y, step + 1);//向上走
//	DFS(x, y + 1, step + 1);//向右走
//	DFS(x, y - 1, step + 1);//向左走
//}
//int main()
//{
//	cin >> m >> n;//输入行数和列数
//	for (int i = 0; i < m; i++)//输入迷宫
//	{
//		for (int j = 0; j < n; j++)
//		{
//			scanf(" %c", &a[i][j]);//注意%c前面的空格，否则会读入换行符
//			if (a[i][j] == 'S')//如果是起点
//			{
//				x_S = i;//记录起点的坐标
//				y_S = j;
//			}
//			if (a[i][j] == 'E')//如果是终点
//			{
//				x_E = i;//记录终点的坐标
//				y_E = j;
//			}
//		}
//	}
//	for (int i = 0; i < m; i++)//初始化b[i][j]
//	{
//		for (int j = 0; j < n; j++)
//		{
//			b[i][j] = INT_MAX;
//		}
//	}
//	DFS(x_S, y_S, 0);//从起点开始搜索
//	if (b[x_E][y_E] == INT_MAX)//如果b[x_E][y_E]没有被更新，说明起点和终点不连通
//	{
//		cout << -1 << endl;
//	}
//	else//否则输出b[x_E][y_E]
//	{
//		cout << b[x_E][y_E] << endl;
//	}
//	return 0;
//}