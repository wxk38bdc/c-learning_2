#pragma once
#include"HashTable.h"

namespace wxk
{
	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, const K, SetKeyOfT, Hash>::ConstIterator const_iterator;

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		const_iterator begin() const
		{
			return _ht.Begin();
		}

		const_iterator end() const
		{
			return _ht.End();
		}

		pair<iterator, bool> insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator Find(const K& key)
		{
			return _ht.Find(key);
		}

		bool Erase(const K& key)
		{
			return _ht.Erase(key);
		}

	private:
		hash_bucket::HashTable<K, const K, SetKeyOfT, Hash> _ht;
	};

	void test_set()
	{
		unordered_set<int> s;
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3,3,15 };
		for (auto e : a)
		{
			s.insert(e);
		}

		for (auto e : s)
		{
			cout << e << " ";
		}
		cout << endl;

		unordered_set<int>::iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test_set2() {
		unordered_set<int> s;

		// 插入元素
		int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 3, 3, 15 };
		for (auto e : a) {
			s.insert(e);
		}

		// 查找元素
		auto it = s.Find(6);
		if (it != s.end()) {
			cout << "Found: " << *it << endl;
		}
		else {
			cout << "Not Found: 6" << endl;
		}

		// 删除元素
		bool erased = s.Erase(7);
		cout << "Element 7 " << (erased ? "was erased." : "not found.") << endl;

		// 遍历unordered_set
		cout << "Contents of the unordered_set:" << endl;
		for (auto it = s.begin(); it != s.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		// 插入更多元素并检查唯一性
		s.insert(10);
		s.insert(2); // 重复插入2，测试唯一性
		s.insert(8);

		// 遍历unordered_set
		cout << "Contents of the unordered_set after more insertions:" << endl;
		for (auto it = s.begin(); it != s.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}

}
