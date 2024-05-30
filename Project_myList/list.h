#pragma once
template<class T>
struct ListNode
{
    T data;
    ListNode<T>* _next;
    ListNode<T>* _prev;

	ListNode(const T& d = T())
		: data(d)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

template<class T, class Ref, class Ptr>
struct ListIterator
{
    typedef ListNode<T> Node;
    typedef ListIterator<T, Ref, Ptr> Self;

    Node* _node;

    ListIterator(Node* node)
        : _node(node)
    {}

    Ref operator*()
    {
        return _node->data;
    }

    Ptr operator->()
    {
        return &_node->data;
    }

    Self& operator++()
    {
        _node = _node->_next;
        return *this;
    }

    Self operator++(int)
    {
        Self tmp(*this);
        _node = _node->_next;
        return tmp;
    }

    Self& operator--()
    {
        _node = _node->_prev;
        return *this;
    }

    Self operator--(int)
    {
        Self tmp(*this);
        _node = _node->_prev;
        return tmp;
    }

    bool operator!=(const Self& it) const
    {
        return _node != it._node;
    }

    bool operator==(const Self& it) const
    {
        return _node == it._node;
    }
};

template<class T, class Ref, class Ptr>
struct ListReverseIterator
{
    typedef ListNode<T> Node;
    typedef ListReverseIterator<T, Ref, Ptr> Self;

    Node* _node;

    ListReverseIterator(Node* node)
        : _node(node)
    {}

    Ref operator*()
    {
        return _node->data;
    }

    Ptr operator->()
    {
        return &_node->data;
    }

    Self& operator++()
    {
        _node = _node->_prev;
        return *this;
    }

    Self operator++(int)
    {
        Self tmp(*this);
        _node = _node->_prev;
        return tmp;
    }

    Self& operator--()
    {
        _node = _node->_next;
        return *this;
    }

    Self operator--(int)
    {
        Self tmp(*this);
        _node = _node->_next;
        return tmp;
    }

    bool operator!=(const Self& it) const
    {
        return _node != it._node;
    }

    bool operator==(const Self& it) const
    {
        return _node == it._node;
    }
};


template<class T>
class list
{
public:
	ListNode<T>* _head;
    typedef ListNode<T> Node;
    typedef ListIterator<T, T&, T*> iterator;
    typedef ListIterator<T, const T&, const T*> const_iterator;
    typedef ListReverseIterator<T, T&, T*> reverse_iterator;
    typedef ListReverseIterator<T, const T&, const T*> const_reverse_iterator;
    typedef T& reference;
    typedef const T& const_reference;
    iterator begin()
	{
		return iterator(_head->_next);
	}
    iterator end()
    {
        return iterator(_head);
    }
    const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}
    const_iterator end() const
	{
		return const_iterator(_head);
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(_head->_prev);
	}
	reverse_iterator rend()
	{
		return reverse_iterator(_head);
	}
	const_reverse_iterator crbegin() const
	{
		return const_reverse_iterator(_head->_prev);
	}
	const_reverse_iterator crend() const
	{
		return const_reverse_iterator(_head);
	}

	list()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}

	~list()
	{
		clear();
		delete _head;
		_head = nullptr;
	}

	list(const list<T>& l)
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		for (const auto& e : l)
		{
			push_back(e);
		}
	}
	list(size_t n, const T& data = T())
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;

		while (n--)
		{
			push_back(data);
		}
	}
	list<T>& operator=(const list<T>& l)
	{
		if (this != &l)
		{
			list<T> tmp(l);
			swap(tmp);
		}
		return *this;
	}

    bool empty() const
    {
        return _head->_next == _head;
    }
    size_t size() const
	{
		size_t count = 0;
		Node* cur = _head->_next;
		while (cur != _head)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}
    reference front()
	{
		return _head->_next->data;
	}
    const_reference front() const
	{
		return _head->_next->data;
	}
	reference back()
	{
		return _head->_prev->data;
	}
	const_reference back() const
	{
		return _head->_prev->data;
	}
	iterator insert(iterator pos, const T& data)
	{
		Node* newNode = new Node(data);

		Node* cur = pos._node;
		Node* prev = cur->_prev;

		prev->_next = newNode;
		newNode->_prev = prev;

		newNode->_next = cur;
		cur->_prev = newNode;

		return iterator(newNode);
	}
	void push_back(const T& data)
	{
		insert(end(), data);
	}
	void push_front(const T& data)
	{
		insert(begin(), data);
	}
	iterator erase(iterator pos)
	{
		Node* cur = pos._node;
		Node* prev = cur->_prev;
		Node* next = cur->_next;

		prev->_next = next;
		next->_prev = prev;

		delete cur;
		return iterator(next);
	}
	iterator erase(iterator first, iterator last)
	{
		while (first != last)
		{
			first = erase(first);
		}
		return last;
	}
	void pop_front()
	{
		erase(begin());
	}
	void pop_back()
	{
		erase(--end());
	}

	void swap(list<T>& l)
	{
		std::swap(_head, l._head);
	}

	void clear()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_head->_next = _head;
		_head->_prev = _head;
	}

};
void testList01()
{
	//测试各种构造函数
	list<int> l1;
	list<int> l2(10, 5);
	list<int> l3(l2);
	list<int> l4;
	l4 = l3;
}
//测试迭代器
void testList02()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}
//测试插入和删除
void testList03()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	list<int>::iterator it = l.begin();
	++it;
	l.insert(it, 10);
	it=l.erase(it);
	it=l.erase(it, l.end());

	for (auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
//测试交换和清空
void testList04()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);

	list<int> l2;
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	l2.push_back(40);
	l2.push_back(50);

	l1.swap(l2);

	for (auto& e : l1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (auto& e : l2)
	{
		cout << e << " ";
	}
	cout << endl;

	l1.clear();
	l2.clear();
}