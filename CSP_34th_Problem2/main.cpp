/*
矩阵重塑（其二）
输入格式
从标准输入读入数据。

输入共n+t+1 行。

输入的第一行包含三个正整数n,m,t

接下来依次输入初始矩阵M 的第0 到第n−1 行，每行包含m 个整数，按列下标从0 到m−1 的顺序依次给出。

接下来输入t 行，每行包含形如 op a b 的三个整数，依次给出每个查询或操作。具体输入格式如下：

重塑操作：1 p q

转置操作：2 0 0

元素查询：3 i j

输出格式
输出到标准输出。

每个查询操作输出一行，仅包含一个整数表示查询结果。

样例1输入
3 2 3
1 2
3 4
5 6
3 0 1
1 2 3
3 1 2
样例1输出
2
6
样例2输入
3 2 5
1 2
3 4
5 6
3 1 0
2 0 0
3 1 0
1 3 2
3 1 0
样例2输出
3
2
5
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> transpose(vector<int>& v, int n, int m)//矩阵转置
{
	vector<int>res(m * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			res[j * n + i] = v[i * m + j];
		}
	}
	return res;
}
int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	vector<int>v(n * m);
	for (int i = 0; i < n * m; i++)
	{
		cin >> v[i];
	}
	while (t--)
	{
		int op;
		cin >> op;
		switch (op) {
		case 1:
		{
			int p, q;
			cin >> p >> q;
			n = p, m = q;
			break;
		}
		case 2:
		{
			int a, b;
			cin >> a >> b;
			v = transpose(v, n, m);
			swap(n, m);
			break;
		}
		case 3:
		{
			int i, j;
			cin >> i >> j;
			cout << v[i * m + j] << endl;
			break;
		}
		}

	}
	return 0;
}
