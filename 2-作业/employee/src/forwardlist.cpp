#include "forwardlist.hpp"
#include <iostream>
#include <string>
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
            throw "Error: index out of range";
        }
        p=p->next;
    }
    return p->data;
}

//删除第i+1个节点
// int ForwardList::delete_data(int i)
// {
//     if (head == nullptr)
//     {
//         throw "Error: empty list";
//     }
//     Node *p = head;
//     if (i == 0)
//     {
//         head = p->next;
//         delete p;
//         return 0;
//     }
//     for (int j = 0; j < i - 1; j++)
//     {
//         if (p->next == nullptr)
//         {
//             throw "Error: index out of range";
//         }
//         p = p->next;
//     }
//     Node *q = p->next;
//     p->next = q->next;
//     delete q;
//     return 0;
// }

//删除第i个节点
int ForwardList::delete_data(int i)
{
    if(--i<0||--i >= this->size())
    {
        cout << "index <= 0 or index > list_size" << endl;
        return -1;
    }
    
    
    if (head == nullptr)
    {
        throw "Error: empty list";
    }

    Node *p = head;

    if (i == 0)
    {
        head = p->next;
        delete p;
        return 0;
    }

    for (int j = 0; j < i - 1; j++)
    {
        if (p->next == nullptr)
        {
            throw "Error: index out of range";
        }
        p = p->next;
    }

    Node *q = p->next;
    if (q == nullptr)
    {
        throw "Error: index out of range";
    }

    p->next = q->next;
    delete q;
    return 0;
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