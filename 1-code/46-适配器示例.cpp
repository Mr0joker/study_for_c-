#include "doubly_linked_list.hpp"
#include <iostream>

using namespace std;

template <typename T>
class Queue
{
private:
    DoublyLinkedList<T> list;

public:
    void enqueue(T data)//入队
    {
        list.push_front(data);
    }
    T dequeue()//出队
    {
        if (list.empty())
        {
            throw "Queue is empty";
            return -1;
        }
        else
        {
            T data = peek_back();
            list.pop_back();
            return data;
        }
    }
    T peek_front()//查看队首元素
    {
        list.front();
    }
    T peek_back()//查看队尾元素
    {
        list.back();
    }    
    bool empty()//判断队列是否为空
    {
        return list.empty();
    }
    size_t size()//返回队列大小
    {
        return list.size();
    }
    void print()//打印队列
    {
        list.print();
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.enqueue(1);
    q.print();
    q.dequeue();
    cout << "front: " << q.peek_front() << endl;
    cout << "back: " << q.peek_back() << endl;
    cout << "size: " << q.size() << endl;
    q.print();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "front: " << q.peek_front() << endl;
    cout << "back: " << q.peek_back() << endl;
    cout << "size: " << q.size() << endl;

    q.print();
    return 0;
}