/*
题目：村庄是否联通
题目描述
村庄中存在一些路，根据输入的相邻村庄的路，判断某两个村庄是否能够联通。n个村庄使用0到n-1的不同整数标识。路使用取值范围【0，n-1】的整数对表示。例如 3 5，代表村庄3和5之间有一条路。

Input Format
村庄个数 n， 0<n<=20
路的条数 m，0<m<=50
m条路，即为2m个范围在【0，n-1】的整数
需要判断是否相连的村庄对数 p 0<p<=10
需要判断是否相连的p对村庄，即为2p个范围在【0，n-1】的整数。

Output Format
能够连通输出true,不可连通输出false

Example
Input
5
4
0 4
2 4
0 2
1 3
2
3 4
2 4

Output
false
true
*/
#include <iostream>
#include <vector>
using namespace std;

// 并查集结构
class UnionFind {
private:
	vector<int> parent;
	vector<int> rank;

public:
	UnionFind(int n) {
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	// 查找根节点
	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]); // 路径压缩
		}
		return parent[x];
	}

	// 合并两个集合
	void unite(int x, int y) {
		int rootX = find(x);
		int rootY = find(y);
		if (rootX != rootY) {
			if (rank[rootX] > rank[rootY]) {
				parent[rootY] = rootX;
			}
			else if (rank[rootX] < rank[rootY]) {
				parent[rootX] = rootY;
			}
			else {
				parent[rootY] = rootX;
				rank[rootX]++;
			}
		}
	}

	// 判断是否连通
	bool connected(int x, int y) {
		return find(x) == find(y);
	}
};

int main() {
	int n, m, p;
	cin >> n >> m;

	UnionFind uf(n);

	// 读取路的信息
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		uf.unite(a, b);
	}

	cin >> p;

	// 判断是否连通
	for (int i = 0; i < p; ++i) {
		int x, y;
		cin >> x >> y;
		if (uf.connected(x, y)) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}

	return 0;
}
