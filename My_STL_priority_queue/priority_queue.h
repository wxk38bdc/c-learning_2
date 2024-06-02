#pragma once
#include <vector>
#include <functional>
#include <stdexcept> 

namespace wxk
{
    using namespace std;

    template<class T, class Container = vector<T>, class Compare = less<T>>
    class priority_queue
    {
    private:
        Container con;
        Compare comp;
    public:
        priority_queue() = default;
        priority_queue(const Compare& c) :comp(c) {}
        template<class InputIterator>
        priority_queue(InputIterator first, InputIterator last, const Compare& c = Compare()) : con(first, last), comp(c)
        {
            make_heap();
        }
        bool empty()const
        {
            return con.empty();
        }
        size_t size()const
        {
            return con.size();
        }
        const T& top()const
        {
            if (con.empty()) {
                throw std::invalid_argument("Priority queue is empty");
            }
            return con.front();
        }
        void push(const T& val)
        {
            con.push_back(val);
            push_heap();
        }
        void pop()
        {
            if (con.empty()) {
                throw std::invalid_argument("Priority queue is empty");
            }
            pop_heap();
            con.pop_back();
        }
    private:
        void adjust_up(size_t child)
        {
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                if (comp(con[child], con[parent]))
                {
                    swap(con[child], con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                    break;
            }
        }
        void adjust_down(size_t parent)
        {
            size_t child = parent * 2 + 1;
            while (child < con.size())
            {
                if (child + 1 < con.size() && comp(con[child + 1], con[child]))
                    ++child;
                if (comp(con[child], con[parent]))
                {
                    swap(con[child], con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                    break;
            }
        }
        void make_heap()
        {
            for (size_t i = (con.size() - 2) / 2 + 1; i > 0; --i)
                adjust_down(i - 1);
        }
        void push_heap()
        {
            adjust_up(con.size() - 1);
        }
        void pop_heap()
        {
            swap(con[0], con[con.size() - 1]);
            adjust_down(0);
        }
    };

    void test_priority_queue01()
    {
        priority_queue<int> pq;
        pq.push(3);
        pq.push(1);
        pq.push(4);
        pq.push(1);
        pq.push(5);
        pq.push(9);
        pq.push(2);
        pq.push(6);
        pq.push(5);
        pq.push(3);
        pq.push(5);
        pq.push(8);
        pq.push(9);
        pq.push(7);
        pq.push(9);
        pq.push(3);
        pq.push(2);
        pq.push(3);
        pq.push(5);
        pq.push(8);
        pq.push(9);
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
    void test_priority_queue02()
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(3);
        pq.push(1);
        pq.push(4);
        pq.push(1);
        pq.push(5);
        pq.push(9);
        pq.push(2);
        pq.push(6);
        pq.push(5);
        pq.push(3);
        pq.push(5);
        pq.push(8);
        pq.push(9);
        pq.push(7);
        pq.push(9);
        pq.push(3);
        pq.push(2);
        pq.push(3);
        pq.push(5);
        pq.push(8);
        pq.push(9);
        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}
