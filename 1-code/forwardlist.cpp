#include "forwardlist.hpp"
#include <iostream>


ForwardList::ForwardList()
{
    head = nullptr;
}

ForwardList::~ForwardList()
{
    Node *p = head;
    while (p != nullptr)
    {
        Node *q = p->next;
        delete p;
        p = q;
    }
}

void ForwardList::push_front(ElemType x) // 头插
{
    Node *p = new Node;
    p->data = x;
    p->next = head;
    head = p;
}

void ForwardList::pop_front() // 删除首元素
{
    if (head == nullptr)
    {
        cout << "Error: empty list" << endl;
        return;
    }
    Node *p = head;
    head = p->next;
    delete p;
}

ElemType ForwardList::front() const // 返回首元素
{
    if (head == nullptr)
    {
        cout << "Error: empty list" << endl;
        return 0;
    }
    return head->data;
}

int ForwardList::size() const // 返回元素个数
{
    int count = 0;
    Node *p = head;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}

bool ForwardList::empty() const // 判断是否为空
{
    return head == nullptr;
}

void ForwardList::print() const // 输出所有元素
{
    Node *p = head;
    while (p != nullptr)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "nullptr" << endl;
}


