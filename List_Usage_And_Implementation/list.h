#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

namespace myList {

    template<class T>
    struct __list_node {
        __list_node<T>* _prev;
        __list_node<T>* _next;
        T data;

        __list_node(const T& value = T())
            : _prev(nullptr), _next(nullptr), data(value) {}
    };

    template<class T, class Ref, class Ptr>
    struct __list_iterator {
        typedef __list_node<T> node;
        typedef __list_iterator<T, Ref, Ptr> self;
        node* _node;

        // Constructor
        __list_iterator(node* node = nullptr) : _node(node) {}

        // Dereference operator returns a reference to the data
        Ref operator*() const { return _node->data; }

        // Arrow operator returns a pointer to the data
        Ptr operator->() const { return &_node->data; }

        // Prefix increment
        self& operator++() {
            _node = _node->_next;
            return *this;
        }

        // Postfix increment
        self operator++(int) {
            self tmp = *this;
            _node = _node->_next;
            return tmp;
        }

        // Prefix decrement
        self& operator--() {
            _node = _node->_prev;
            return *this;
        }

        // Postfix decrement
        self operator--(int) {
            self tmp = *this;
            _node = _node->_prev;
            return tmp;
        }

        // Equality comparison
        bool operator ==(const self& other) const {
            return _node == other._node;
        }

        // Inequality comparison
        bool operator !=(const self& other) const {
            return _node != other._node;
        }
    };

    template<class T>
    class list {
    public:
        typedef __list_node<T> node;
        typedef __list_iterator<T, T&, T*> iterator; // Normal iterator
        typedef __list_iterator<T, const T&, const T*> const_iterator; // Const iterator

        list() {
            _head = new node;
            _head->_prev = _head->_next = _head;
        }

        ~list() {
            clear();
            delete _head;
        }

        void push_back(const T& data) {
            node* newNode = new node(data);
            newNode->_next = _head;
            newNode->_prev = _head->_prev;
            _head->_prev->_next = newNode;
            _head->_prev = newNode;
        }

        void pop_back() {
            if (_head->_next == _head) return;
            node* del = _head->_prev;
            del->_prev->_next = _head;
            _head->_prev = del->_prev;
            delete del;
        }

        void clear() {
            node* cur = _head->_next;
            while (cur != _head) {
                node* del = cur;
                cur = cur->_next;
                delete del;
            }
            _head->_next = _head->_prev = _head;
        }

        iterator begin() {
            return iterator(_head->_next);
        }

        iterator end() {
            return iterator(_head);
        }

        const_iterator cbegin() const {
            return const_iterator(_head->_next);
        }

        const_iterator cend() const {
            return const_iterator(_head);
        }

    private:
        node* _head; // Sentinel node
    };

    class Date {
    public:
        int _year;
        int _month;
        int _day;

        Date(int year = 1900, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day) {}
    };

    void test_mylist03() {
        list<Date> l;

        l.push_back(Date(2000, 12, 31));
        l.push_back(Date(2024, 2, 29));

        // Use the iterator to traverse and print the list
        for (auto it = l.begin(); it != l.end(); ++it) {
            cout << it->_year << "-" << it->_month << "-" << it->_day << endl;
        }
    }
} // namespace myList
