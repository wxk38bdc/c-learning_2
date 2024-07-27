#pragma once
#include"HashTable.h"
namespace wxk
{
	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::Iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::ConstIterator const_iterator;

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

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));

			return ret.first->second;
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
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
	};

	void test_map()
	{
		unordered_map<string, string> dict;
		dict.insert({ "sort", "排序" });
		dict.insert({ "left", "左边" });
		dict.insert({ "right", "右边" });

		dict["left"] = "左边，剩余";
		dict["insert"] = "插入";
		dict["string"];

		unordered_map<string, string>::iterator it = dict.begin();
		while (it != dict.end())
		{
			it->second += 'x';
			cout << it->first << ":" << it->second << endl;
			++it;
		}
		cout << endl;
	}
	// 测试unordered_map
	void test_map2() {
		unordered_map<int, string> dict;

		// 插入键值对
		dict.insert({ 1, "one" });
		dict.insert({ 2, "two" });
		dict.insert({ 3, "three" });
		dict.insert({ 4, "four" });
		dict.insert({ 5, "five" });

		// 使用[]操作符访问和修改元素
		dict[2] = "TWO";
		dict[6] = "six"; // 插入新的键值对

		// 查找元素
		auto it = dict.Find(3);
		if (it != dict.end()) {
			cout << "Found: " << it->first << " -> " << it->second << endl;
		}
		else {
			cout << "Not Found: 3" << endl;
		}

		// 删除元素
		bool erased = dict.Erase(4);
		cout << "Element with key 4 " << (erased ? "was erased." : "not found.") << endl;

		// 遍历unordered_map
		cout << "Contents of the unordered_map:" << endl;
		for (auto it = dict.begin(); it != dict.end(); ++it) {
			cout << it->first << " -> " << it->second << endl;
		}
		cout << endl;
	}
}