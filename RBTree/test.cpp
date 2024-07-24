#include"RBTree.h"
#include <chrono>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;
using namespace std::chrono;

void TestInsert()
{
    RBTree<int, int, KeyOfT> tree;
    assert(tree.Insert(10).second == true);
    assert(tree.Insert(20).second == true);
    assert(tree.Insert(5).second == true);
    assert(tree.Insert(10).second == false); // duplicate insert should fail

    cout << "TestInsert passed." << endl;
}

void TestInOrder()
{
    RBTree<int, int, KeyOfT> tree;
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);
    tree.Insert(15);

    cout << "InOrder Traversal: ";
    tree.InOrder(); // Expected output: 5 10 15 20

    cout << "TestInOrder passed." << endl;
}

void TestSize()
{
    RBTree<int, int, KeyOfT> tree;
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);
    tree.Insert(15);

    assert(tree.Size() == 4);

    cout << "TestSize passed." << endl;
}

void TestHeight()
{
    RBTree<int, int, KeyOfT> tree;
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);
    tree.Insert(15);

    assert(tree.Height() == 3); // Depending on balancing, height should be 3

    cout << "TestHeight passed." << endl;
}

void TestIterator()
{
    RBTree<int, int, KeyOfT> tree;
    tree.Insert(10);
    tree.Insert(20);
    tree.Insert(5);
    tree.Insert(15);

    RBTree<int, int, KeyOfT>::Iterator it = tree.Begin();
    vector<int> values;
    while (it != tree.End())
    {
        values.push_back(*it);
        ++it;
    }

    vector<int> expectedValues = { 5, 10, 15, 20 };
    assert(values == expectedValues);

    cout << "TestIterator passed." << endl;
}
void InsertLargeData(RBTree<int, int, KeyOfT>& tree, int numElements)
{
    srand(time(nullptr)); // 使用当前时间作为随机数种子
    for (int i = 0; i < numElements; ++i)
    {
        int data = rand();
        tree.Insert(data);
    }
    cout << "Inserted " << numElements << " elements into the RBTree." << endl;
}

void TestSearchTime(RBTree<int, int, KeyOfT>& tree, int numSearches)
{
    srand(time(nullptr)); // 使用当前时间作为随机数种子
    vector<int> searchKeys;
    for (int i = 0; i < numSearches; ++i)
    {
        searchKeys.push_back(rand());
    }

    auto start = high_resolution_clock::now();
    for (int key : searchKeys)
    {
        RBTree<int, int, KeyOfT>::Iterator it = tree.Begin();
        while (it != tree.End())
        {
            if (*it == key)
                break;
            ++it;
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Time taken for " << numSearches << " searches: "
        << duration.count() << " milliseconds." << endl;
}
int main()
{
    TestInsert();
    TestInOrder();
    TestSize();
    TestHeight();
    TestIterator();

    cout << "All tests passed." << endl;
    const int numElements = 1000000; // 100万元素
    const int numSearches = 1000;    // 1000次搜索

    RBTree<int, int, KeyOfT> tree;
    InsertLargeData(tree, numElements);
    TestSearchTime(tree, numSearches);
    return 0;
}
