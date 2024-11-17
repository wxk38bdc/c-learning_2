#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m, v;
	cin >> n >> m >> v;
	vector<int>b(n), c(n), a(m), t(m);
	for (int i = 0; i < n; i++)
	{
		cin >> b[i] >> c[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> t[i];
	}

	return 0;
}