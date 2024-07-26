#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>
using namespace std;

namespace Close_Hash //闭散列法
{
	enum State { EMPTY, EXIST, DELETE };

	template<class K, class V>
	struct Elem
	{
		pair<K, V> _val;
		State _state;
		Elem(const pair<K, V>& val = pair<K, V>(), State state = EMPTY)
			: _val(val)
			, _state(state)
		{}
	};

	template<class K, class V>
	class HashTable
	{
	public:
		HashTable(): _size(0)
		{
			_ht.resize(10);
		}
		HashTable(size_t n): _size(0)
		{
			_ht.resize(n);
		}

		// 插入
		bool Insert(const pair<K, V>& val)
		{
			if(Find(val.first))
			{
				return false;
			}
			//检查容量
			if (_size * 10 / _ht.size() >= 7)
			{
				HashTable<K, V> newHT;
				newHT._ht.resize(_ht.size() * 2);
				for (size_t i = 0; i < _ht.size(); i++)
				{
					if (_ht[i]._state == EXIST)
					{
						newHT.Insert(_ht[i]._val);
					}
				}
				Swap(newHT);
			}
			size_t hashIndex = val.first % _ht.size();
			while (_ht[hashIndex]._state == EXIST)
			{
				hashIndex++;
				hashIndex %= _ht.size();
			}
			_ht[hashIndex]._val = val;
			_ht[hashIndex]._state = EXIST;
			_size++;

			return true;
		}

		// 查找
		Elem<K, V>* Find(const K& key)
		{
			if (_ht.empty())
			{
				return nullptr;
			}

			size_t hashIndex = key % _ht.size();
			size_t startIndex = hashIndex; // 记录起始位置

			while (_ht[hashIndex]._state != EMPTY)
			{
				if (_ht[hashIndex]._state == EXIST && _ht[hashIndex]._val.first == key)
				{
					return &_ht[hashIndex];
				}
				hashIndex++;
				hashIndex %= _ht.size();

				// 如果回到起始位置，说明查找已经遍历整个表
				if (hashIndex == startIndex)
				{
					break;
				}
			}
			return nullptr;
		}


		// 删除
		bool Erase(const K& key)
		{
			Elem<K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				_size--;
				return true;
			}
			return false;
		}

		size_t Size()const
		{
			return _size;
		}

		bool Empty() const
		{
			return _size == 0;
		}

		void Swap(HashTable<K, V>& ht)
		{
			swap(_size, ht._size);
			_ht.swap(ht._ht);
		}

	private:
		vector<Elem<K,V>> _ht;//哈希表
		size_t _size;  // 哈希表中的有效元素个数
	};
	void TestInsert()
	{
		HashTable<int, string> ht;
		cout << "测试插入:" << endl;
		cout << "插入 (1, 'One'): " << (ht.Insert({ 1, "One" }) ? "成功" : "失败") << endl;
		cout << "插入 (2, 'Two'): " << (ht.Insert({ 2, "Two" }) ? "成功" : "失败") << endl;
		cout << "插入 (3, 'Three'): " << (ht.Insert({ 3, "Three" }) ? "成功" : "失败") << endl;
		cout << "再次插入 (1, 'One'): " << (ht.Insert({ 1, "One" }) ? "成功" : "失败") << endl; // 应该失败
		cout << "插入后的大小: " << ht.Size() << endl;
	}

	void TestFind()
	{
		HashTable<int, string> ht;
		ht.Insert({ 1, "One" });
		ht.Insert({ 2, "Two" });
		ht.Insert({ 3, "Three" });

		cout << "测试查找:" << endl;
		auto elem = ht.Find(1);
		cout << "查找键 1: " << (elem ? elem->_val.second : "未找到") << endl;
		elem = ht.Find(2);
		cout << "查找键 2: " << (elem ? elem->_val.second : "未找到") << endl;
		elem = ht.Find(3);
		cout << "查找键 3: " << (elem ? elem->_val.second : "未找到") << endl;
		elem = ht.Find(4);
		cout << "查找键 4: " << (elem ? elem->_val.second : "未找到") << endl; // 应该是 "未找到"
	}

	void TestErase()
	{
		HashTable<int, string> ht;
		ht.Insert({ 1, "One" });
		ht.Insert({ 2, "Two" });
		ht.Insert({ 3, "Three" });

		cout << "测试删除:" << endl;
		cout << "删除键 2: " << (ht.Erase(2) ? "成功" : "失败") << endl;
		cout << "删除键 4: " << (ht.Erase(4) ? "成功" : "失败") << endl; // 应该失败
		cout << "删除后的大小: " << ht.Size() << endl;

		auto elem = ht.Find(2);
		cout << "删除后查找键 2: " << (elem ? elem->_val.second : "未找到") << endl; // 应该是 "未找到"
	}

	void TestResize()
	{
		HashTable<int, string>ht(3);
		for (int i = 0; i < 25; ++i)
		{
			ht.Insert({ i, "Value" + to_string(i) });
		}

		cout << "测试调整大小:" << endl;
		cout << "插入后的大小: " << ht.Size() << endl;
		for (int i = 0; i < 25; ++i)
		{
			auto elem = ht.Find(i);
			cout << "查找键 " << i << ": " << (elem ? elem->_val.second : "未找到") << endl;
		}
	}
	
}

namespace Hash_Bucket {
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _val;
		HashNode<K, V>* _next;
		HashNode(const pair<K, V>& val = pair<K, V>())
			: _val(val)
			, _next(nullptr)
		{}
	};

	template<class K, class V>
	class HashTable
	{
	public:
		HashTable(size_t n = 10)
			: _size(0)
		{
			_ht.resize(n);
		}
		~HashTable()
		{
			for (size_t i = 0; i < _ht.size(); i++)
			{
				HashNode<K, V>* cur = _ht[i];
				while (cur)
				{
					HashNode<K, V>* del = cur;
					cur = cur->_next;
					delete del;
				}
				_ht[i] = nullptr;
			}
		}
		// 插入
		bool Insert(const pair<K, V>& val)
		{
			size_t hashIndex = val.first % _ht.size();
			//如果已经存在，返回false
			if (Find(val.first))
			{
				return false;
			}
			//如果负载因子为1，扩容
			if (_size == _ht.size())
			{
				HashTable<K, V> newHT(_ht.size() * 2);
				for (size_t i = 0; i < _ht.size(); i++)
				{
					HashNode<K, V>* cur = _ht[i];
					while (cur)
					{
						HashNode<K,V>* next = cur->_next;
						size_t hashIndex = cur->_val.first % newHT._ht.size();
						//头插
						cur->_next = newHT._ht[hashIndex];
						newHT._ht[hashIndex] = cur;
						cur = next;
					}
					_ht[i] = nullptr;
				}
				Swap(newHT);
			}
			//头插
			HashNode<K, V>* newNode = new HashNode<K, V>(val);
			newNode->_next = _ht[hashIndex];
			_ht[hashIndex] = newNode;
			_size++;
			return true;
		}

		// 查找
		HashNode<K, V>* Find(const K& key)
		{
			size_t hashIndex = key % _ht.size();
			HashNode<K, V>* cur = _ht[hashIndex];
			while (cur)
			{
				if (cur->_val.first == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return nullptr;
		}

		// 删除
		bool Erase(const K& key)
		{
			size_t hashIndex = key % _ht.size();
			HashNode<K, V>* cur = _ht[hashIndex];
			HashNode<K, V>* prev = nullptr;
			while (cur)
			{
				if (cur->_val.first == key)
				{
					if (prev)
					{
						prev->_next = cur->_next;
					}
					else
					{
						_ht[hashIndex] = cur->_next;
					}
					delete cur;
					_size--;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
	private:
		vector<HashNode<K, V>*> _ht;
		size_t _size;

		void Swap(HashTable<K, V>& ht)
		{
			swap(_size, ht._size);
			_ht.swap(ht._ht);
		}
	};

	void TestInsert()
	{
		HashTable<int, string> ht;
		cout << "测试插入:" << endl;
		cout << "插入 (1, 'One'): " << (ht.Insert({ 1, "One" }) ? "成功" : "失败") << endl;
		cout << "插入 (2, 'Two'): " << (ht.Insert({ 2, "Two" }) ? "成功" : "失败") << endl;
		cout << "插入 (3, 'Three'): " << (ht.Insert({ 3, "Three" }) ? "成功" : "失败") << endl;
		cout << "再次插入 (1, 'One'): " << (ht.Insert({ 1, "One" }) ? "成功" : "失败") << endl; // 应该失败
	}

	void TestFind()
	{
		HashTable<int, string> ht;
		ht.Insert({ 1, "One" });
		ht.Insert({ 2, "Two" });
		ht.Insert({ 3, "Three" });

		cout << "测试查找:" << endl;
		auto elem = ht.Find(1);
		cout << "查找键 1: " << (elem ? elem->_val.second : "未找到") << endl;
		elem = ht.Find(2);
		cout << "查找键 2: " << (elem ? elem->_val.second : "未找到") << endl;
		elem = ht.Find(3);
		cout << "查找键 3: " << (elem ? elem->_val.second : "未找到") << endl;
		elem = ht.Find(4);
		cout << "查找键 4: " << (elem ? elem->_val.second : "未找到") << endl; // 应该是 "未找到"
	}

	void TestErase()
	{
		HashTable<int, string> ht;
		ht.Insert({ 1, "One" });
		ht.Insert({ 2, "Two" });
		ht.Insert({ 3, "Three" });

		cout << "测试删除:" << endl;
		cout << "删除键 2: " << (ht.Erase(2) ? "成功" : "失败") << endl;
		cout << "删除键 4: " << (ht.Erase(4) ? "成功" : "失败") << endl; // 应该失败

		auto elem = ht.Find(2);
		cout << "删除后查找键 2: " << (elem ? elem->_val.second : "未找到") << endl; // 应该是 "未找到"
	}

	void TestResize()
	{
		HashTable<int, string> ht(3); // 小初始容量以强制调整大小
		for (int i = 0; i < 500; ++i)
		{
			ht.Insert({ i, "Value" + to_string(i) });
		}

		cout << "测试调整大小:" << endl;
		for (int i = 0; i < 500; ++i)
		{
			auto elem = ht.Find(i);
			cout << "查找键 " << i << ": " << (elem ? elem->_val.second : "未找到") << endl;
		}
	}
}