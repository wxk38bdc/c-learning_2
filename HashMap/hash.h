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
		HashTable(size_t capacity = 3): _ht(capacity), _size(0)
		{
			_ht.resize(capacity);
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
				HashTable<K, V> newHT(_ht.size() * 2);
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
			size_t hashIndex = key % _ht.size();
			while (_ht[hashIndex]._state != EMPTY)
			{
				if (_ht[hashIndex]._state == EXIST && _ht[hashIndex]._val.first == key)
				{
					return &_ht[hashIndex];
				}
				hashIndex++;
				hashIndex %= _ht.size();
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
}