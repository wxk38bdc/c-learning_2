#pragma once

template<class iterator, class ref>
struct reverseIterator {
	iterator _it;
	reverseIterator(iterator it) : _it(it) {}

	ref operator*() {
		iterator tmp = _it;
		return *--tmp;
	}

	ref operator->() {
		return &operator*();
	}

	reverseIterator& operator++() {
		--_it;
		return *this;
	}

	reverseIterator operator++(int) {
		reverseIterator tmp = *this;
		--_it;
		return tmp;
	}

	reverseIterator& operator--() {
		++_it;
		return *this;
	}

	reverseIterator operator--(int) {
		reverseIterator tmp = *this;
		++_it;
		return tmp;
	}

	bool operator==(const reverseIterator& other) const {
		return _it == other._it;
	}

	bool operator!=(const reverseIterator& other) const {
		return _it != other._it;
	}
};


template <class T>
class vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef T& reference;
	typedef const T& const_reference;
	typedef reverseIterator<iterator, reference> reverse_iterator;
	typedef reverseIterator<const_iterator, const_reference> const_reverse_iterator;
private:
	iterator _start;
	iterator _finish;
	iterator _end_of_storage;
public:
	iterator begin()
	{
		return _start;
	}
	iterator end()
	{
		return _finish;
	}
	const_iterator cbegin()const
	{
		return _start;
	}
	const_iterator cend()const
	{
		return _finish;
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(_finish);
	}
	reverse_iterator rend()
	{
		return reverse_iterator(_start);
	}
	const_reverse_iterator crbegin()const
	{
		return const_reverse_iterator(_finish);
	}
	const_reverse_iterator crend()const
	{
		return const_reverse_iterator(_start);
	}
	vector()//构造函数
	{
		_start = nullptr;
		_finish = nullptr;
		_end_of_storage = nullptr;
	}
	//vector()=default;//强制编译器生成默认构造函数
	vector(size_t n, const T& val = T())//构造函数
	{
		_start = new T[n];
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = val;
		}
		_finish = _start + n;
		_end_of_storage = _start + n;
	}
	vector(int n, const T& val = T())//构造函数
	{
		_start = new T[n];
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = val;
		}
		_finish = _start + n;
		_end_of_storage = _start + n;
	}
	vector(const vector<T>& v)//拷贝构造
	{
		_start = new T[v.capacity()];
		for (size_t i = 0; i < v.size(); i++)
		{
			_start[i] = v._start[i];
		}
		_finish = _start + v.size();
		_end_of_storage = _start + v.capacity();
	}
	//拷贝构造的现代写法
	//vector(vector<T> v)
	//{
	//	this->swap(v);
	//	return *this;
	//}
	template<class InputIterator>
	vector(InputIterator first, InputIterator last)//区间构造函数
	{
		size_t n = last - first;
		_start = new T[n];
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = *first;
			++first;
		}
		_finish = _start + n;
		_end_of_storage = _start + n;
	}
	vector(initializer_list<T> l)//初始化列表构造函数
	{
		size_t n = l.size();
		_start = new T[n];
		auto it = l.begin();
		for (size_t i = 0; i < n; i++)
		{
			_start[i] = *it;
			it++;
		}
		_finish = _start + n;
		_end_of_storage = _start + n;
	}
	vector<T>& operator=(const vector<T>& v)
	{
		if (this != &v)
		{
			T* tmp = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); i++)
			{
				tmp[i] = v._start[i];
			}
			delete[] _start;
			_start = tmp;
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}
		return *this;
	}
	~vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
	}

	size_t size()const
	{
		return _finish - _start;
	}
	size_t capacity()const
	{
		return _end_of_storage - _start;
	}
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			size_t size = this->size();
			T* tmp = new T[n];
			if (_start)
			{
				for (size_t i = 0; i < size; i++)
				{
					tmp[i] = _start[i];
				}
				delete[] _start;
			}
			_start = tmp;
			_finish = _start + size;
			_end_of_storage = _start + n;
		}
	}
	void resize(size_t n, const T& val = T())
	{
		if (n < size())
		{
			_finish = _start + n;
		}
		else if (n > size())
		{
			if (n > capacity())
			{
				reserve(n);
			}
			for (size_t i = size(); i < n; i++)
			{
				_start[i] = val;
			}
			_finish = _start + n;
		}
	}
	bool empty()const
	{
		return _start == _finish;
	}

	reference operator[](size_t pos)
	{
		assert(pos < size());
		return _start[pos];
	}
	const_reference operator[] (size_t pos) const
	{
		assert(pos < size());
		return _start[pos];
	}
	reference front()
	{
		return *_start;
	}
	const_reference front()const
	{
		return *_start;
	}
	reference back()
	{
		return *(_finish - 1);
	}
	const_reference back()const
	{
		return *(_finish - 1);
	}

	void push_back(const T& x)
	{
		if (_finish == _end_of_storage)
		{
			size_t n = capacity() == 0 ? 1 : 2 * capacity();
			reserve(n);
		}
		*_finish = x;
		++_finish;
	}
	void pop_back()
	{
		assert(_start < _finish);
		--_finish;
	}
	iterator insert(iterator pos, const T& x)
	{
		assert(pos >= _start && pos <= _finish);
		if (_finish == _end_of_storage)
		{
			size_t n = pos - _start;
			size_t newcapacity = capacity() == 0 ? 1 : 2 * capacity();
			reserve(newcapacity);
			pos = _start + n;
		}
		iterator end = _finish;
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		*pos = x;
		++_finish;
		return pos;
	}
	iterator erase(iterator pos)
	{
		assert(pos >= _start && pos < _finish);
		iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}
	iterator erase(iterator first, iterator last)
	{
		assert(first >= _start && last <= _finish && first <= last);
		iterator begin = last;
		while (begin < _finish)
		{
			*(first) = *begin;
			++first;
			++begin;
		}
		_finish = first;
		return first;
	}
	void swap(vector<T>& v)
	{
		std::swap(_start, v._start);
		std::swap(_finish, v._finish);
		std::swap(_end_of_storage, v._end_of_storage);
	}
	void clear()
	{
		_finish = _start;
	}
};

void testvector1()
{
	vector<int> v1(10, 5);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}
void testvector2()
{
	vector<int> v1(10, 5);
	vector<int> v2(v1);
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
}
void testvector3()
{
	vector<int> v1(10, 6);
	vector<int> v2;
	v2 = v1;
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
}
void testvector4()
{
	vector<int> v1(10, 6);
	vector<int> v2(v1.begin(), v1.end());
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
}
void testvector5()
{
	vector<int> v1(10, 6);
	cout<<v1.size()<<endl;
	cout<<v1.capacity()<<endl;
	v1.reserve(200);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.resize(1);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	cout << endl;
}
void testvector6()
{
	vector<int> v1(10, 6);
	cout << v1.empty() << endl;
	v1.resize(0);
	cout << v1.empty() << endl;
	cout << endl;
}
void testvector7()
{
	vector<int> v1(10, 6);
	cout << v1[0] << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;
	v1.push_back(1);
	cout << v1[10] << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;
	v1.pop_back();
	cout << v1[9] << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;
	cout << endl;
}
void testvector8()
{
	vector<int> v1(10, 6);
	v1.insert(v1.begin()+5, 1);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	v1.insert(v1.end(), 1);
	for (size_t e : v1)
	{
		cout << e << " ";
	}
}
void testvector9()
{
	vector<int> v1(10, 6);
	v1.erase(v1.begin() + 5);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	v1.erase(v1.begin()+2, v1.end()-1);
	for (size_t e : v1)
	{
		cout << e << " ";
	}
}
void testvector10()
{
	vector<string> vs;
	vs.push_back("hello");
	vs.push_back("world");
	vs.push_back("bit");
	for (size_t i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}
}
void testvector11()
{
	vector<int> v1(10, 6);
	vector<int> v2(10, 7);
	v1.swap(v2);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	auto a = { 1,2,3 };
	initializer_list<int> b = { 1,2,3 };
}
void testvector12()
{
	vector<int>v1 = { 1,2,3 };
	for (auto e : v1)
	{
		cout << e << endl;
	}
}
//测试反向迭代器
void testvector13()
{
	vector<int> v1 = { 1,2,3,4,5 };
	for (auto it = v1.rbegin(); it != v1.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}