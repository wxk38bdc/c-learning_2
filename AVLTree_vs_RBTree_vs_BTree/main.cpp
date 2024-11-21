#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
#include "RBTree.h"
#include "AVLTree.h"
#include "BSTree.h"
#include "BTree.h"
using namespace std::chrono;

// 测试函数
template <typename TreeType>
void testTree(TreeType& tree, const vector<int>& data, const vector<int>& searchNumbers, const string& treeName) {
    duration<double> insertDuration, searchDuration, deleteDuration, totalDuration;

    // 1. 插入操作
    auto start = high_resolution_clock::now();
    for (const auto& val : data) {
        tree.Insert(val);
    }
    auto end = high_resolution_clock::now();
    insertDuration = end - start;

    // 2. 查找操作
    start = high_resolution_clock::now();
    for (const auto& val : searchNumbers) {
        tree.Find(val);
    }
    end = high_resolution_clock::now();
    searchDuration = end - start;

    // 3. 删除操作
    start = high_resolution_clock::now();
    for (const auto& val : data) {
        tree.Remove(val);
    }
    end = high_resolution_clock::now();
    deleteDuration = end - start;

    // 4. 总时间
    totalDuration = insertDuration + searchDuration + deleteDuration;

    // 打印时间
    cout << treeName << " Results:" << endl;
    cout << "Insert Time: " << insertDuration.count() << " seconds" << endl;
    cout << "Search Time: " << searchDuration.count() << " seconds" << endl;
    cout << "Delete Time: " << deleteDuration.count() << " seconds" << endl;
    cout << "Total Time (Insert + Search + Delete): " << totalDuration.count() << " seconds" << endl;
    cout << "--------------------------------------------------" << endl;
}

// 使用固定种子生成随机数
vector<int> generateRandomNumbers(int count, int maxRange, int seed) {
    mt19937 gen(seed);  // 使用指定种子初始化生成器
    uniform_int_distribution<> dis(1, maxRange);  // 均匀分布 [1, maxRange]

    vector<int> numbers(count);
    for (int i = 0; i < count; ++i) {
        numbers[i] = dis(gen);
    }
    return numbers;
}


template <typename TreeType>
void testTreeReverseDelete(TreeType& tree, const vector<int>& data, const vector<int>& searchNumbers, const string& treeName) {
    duration<double> insertDuration, searchDuration, deleteDuration, totalDuration;

    // 1. 插入操作
    auto start = high_resolution_clock::now();
    for (const auto& val : data) {
        tree.Insert(val);
    }
    auto end = high_resolution_clock::now();
    insertDuration = end - start;

    // 2. 查找操作
    start = high_resolution_clock::now();
    for (const auto& val : searchNumbers) {
        tree.Find(val);
    }
    end = high_resolution_clock::now();
    searchDuration = end - start;

    // 3. 删除操作（按相反顺序删除）
    start = high_resolution_clock::now();
    for (auto it = data.rbegin(); it != data.rend(); ++it) {
        tree.Remove(*it);
    }
    end = high_resolution_clock::now();
    deleteDuration = end - start;

    // 4. 总时间
    totalDuration = insertDuration + searchDuration + deleteDuration;

    // 打印时间
    cout << treeName << " Results (Reverse Delete):" << endl;
    cout << "Insert Time: " << insertDuration.count() << " seconds" << endl;
    cout << "Search Time: " << searchDuration.count() << " seconds" << endl;
    cout << "Delete Time (Reverse): " << deleteDuration.count() << " seconds" << endl;
    cout << "Total Time (Insert + Search + Reverse Delete): " << totalDuration.count() << " seconds" << endl;
    cout << "--------------------------------------------------" << endl;
}

template <typename TreeType>
void testTreeRandom(TreeType& tree, vector<int> data, const vector<int>& searchNumbers, const string& treeName, int seed) {
    duration<double> insertDuration, searchDuration, deleteDuration, totalDuration;

    // 随机打乱数据（插入和删除顺序相同）
    mt19937 gen(seed);  // 使用指定种子初始化随机数生成器
    shuffle(data.begin(), data.end(), gen);

    // 1. 插入操作（按随机顺序）
    auto start = high_resolution_clock::now();
    for (const auto& val : data) {
        tree.Insert(val);
    }
    auto end = high_resolution_clock::now();
    insertDuration = end - start;

    // 2. 查找操作
    start = high_resolution_clock::now();
    for (const auto& val : searchNumbers) {
        tree.Find(val);
    }
    end = high_resolution_clock::now();
    searchDuration = end - start;

    // 3. 删除操作（按随机顺序）
    start = high_resolution_clock::now();
    for (const auto& val : data) {
        tree.Remove(val);
    }
    end = high_resolution_clock::now();
    deleteDuration = end - start;

    // 4. 总时间
    totalDuration = insertDuration + searchDuration + deleteDuration;

    // 打印时间
    cout << treeName << " Results (Random Order):" << endl;
    cout << "Insert Time: " << insertDuration.count() << " seconds" << endl;
    cout << "Search Time: " << searchDuration.count() << " seconds" << endl;
    cout << "Delete Time (Random Order): " << deleteDuration.count() << " seconds" << endl;
    cout << "Total Time (Insert + Search + Random Delete): " << totalDuration.count() << " seconds" << endl;
    cout << "--------------------------------------------------" << endl;
}

void runTests(int N, int minDegree) {
    // 初始化数据
    vector<int> data(N);
    for (int i = 0; i < N; ++i) {
        data[i] = i + 1;  // 递增顺序数据
    }

    // 生成随机查找的1000个数（传入 N 作为种子）
    vector<int> searchNumbers = generateRandomNumbers(1000, N, N);

    // AVL Tree 测试
    AVLTree<int> avlTree;
    testTree(avlTree, data, searchNumbers, "AVL Tree");
    testTreeReverseDelete(avlTree, data, searchNumbers, "AVL Tree");
    testTreeRandom(avlTree, data, searchNumbers, "AVL Tree", N);  // 传入 N 作为种子

    // BSTree 测试
    BSTree<int> bstTree;
    testTree(bstTree, data, searchNumbers, "BSTree");
    testTreeReverseDelete(bstTree, data, searchNumbers, "BSTree");
    testTreeRandom(bstTree, data, searchNumbers, "BSTree", N);  // 传入 N 作为种子

    // BTree 测试
    BTree bTree(minDegree);
    testTree(bTree, data, searchNumbers, "BTree");
    testTreeReverseDelete(bTree, data, searchNumbers, "BTree");
    testTreeRandom(bTree, data, searchNumbers, "BTree", N);  // 传入 N 作为种子

    // RBTree 测试
    RBTree<int> rbTree;
    testTree(rbTree, data, searchNumbers, "RBTree");
    testTreeReverseDelete(rbTree, data, searchNumbers, "RBTree");
    testTreeRandom(rbTree, data, searchNumbers, "RBTree", N);  // 传入 N 作为种子
}

int main() {
    //int minDegree = 256;  // B树的最小度（确保为512阶）

    //// 循环测试不同规模的数据
    //for (int N = 10000; N <= 400000; N += 20000) {
    //    cout << "Testing with N = " << N << " elements..." << endl;
    //    runTests(N, minDegree);
    //}
    testBTree();
    return 0;
}
