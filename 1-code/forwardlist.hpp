#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP
#include <string>

using namespace std;
using ElemType = int;

class ForwardList
{
private:
    struct Node
    {
        ElemType data;
        Node *next;
    };
    Node *head;

public:
    ForwardList();
    ~ForwardList();

    void push_front(ElemType x);
    void pop_front();
    ElemType front() const;
    int size() const;
    bool empty() const;
    void print() const;
};

#endif // FORWARDLIST_HPP