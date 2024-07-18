#pragma once
#include <iostream>
using namespace std;

template <class T>
struct AVLTreeNode
{
	T _data;
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	int _bf;//balance factor

	AVLTreeNode(const T& x=T())
		:_data(x)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
		, _bf(0)
	{}
};