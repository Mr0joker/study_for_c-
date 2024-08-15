#include "forwardlist.hpp"
#include <iostream>
#include "../inc/forwardlist.hpp"
using namespace std;

std::ostream &operator<<(std::ostream &out, const ForwardList &list)
{
    // TODO: 在此处插入 return 语句
    for(int i=0;i<list.size();i++)
    {
        out<<list.get_data(i)<<"->";
    }
    out<<"nullptr"<<endl;
    return out;
}


ForwardList::ForwardList()
{
    head = nullptr;
}

ForwardList::ForwardList(const ForwardList &other)
{
    head = nullptr;
    Node *p = other.head;
    while (p != nullptr)
    {
        push_front(p->data);
        p = p->next;
    }
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
        // cerr << "Error: empty list" << endl;
        // return;
        throw "Error: empty list";
    }
    Node *p = head;
    head = p->next;
    delete p;
}

ElemType ForwardList::get_data(int i) const // 返回第i个元素
{
    Node *p=head;
    for(int j=0;j<i;j++)
    {
        if(p==nullptr)
        {
            // cerr<<"Error: index out of range"<<endl;
            // return ;
            throw "Error: index out of range";
        }
        p=p->next;
    }
    return p->data;
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