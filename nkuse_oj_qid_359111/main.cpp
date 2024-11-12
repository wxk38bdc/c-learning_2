/*
题目描述
合并两个水晶碎块需要的能量是两个水晶碎块的能量和。假设只可以两两合并，请求出一堆水晶碎块合并成一整块水晶需要的最小能量。

题目输入：

第一行输入水晶碎块的个数n(1<=n<100)，随后输入n个整数

题目输出：

合并最小能量（取值在long范围内）

提示：注意题目标题。（哈夫曼树A）

附件

样例输入输出
样例1
输入:
6
8282
165
5
7431
9137
3
输出:
48694
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 优先队列（最小堆），用于存储水晶碎块的能量
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // 读取输入并将每个碎块的能量值放入最小堆中
    for (int i = 0; i < n; i++) {
        long long energy;
        cin >> energy;
        pq.push(energy);
    }

    long long total_energy = 0;

    // 不断合并能量最小的两个碎块，直到只剩下一个碎块
    while (pq.size() > 1) {
        // 取出最小的两个碎块
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        // 合并这两个碎块的能量
        long long merge_energy = first + second;
        total_energy += merge_energy;

        // 将合并后的能量放回最小堆中
        pq.push(merge_energy);
    }

    // 输出合并成整块水晶所需的最小能量
    cout << total_energy << endl;

    return 0;
}
