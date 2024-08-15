#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP
#include <string>
using ElemType = std::string;

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
    ForwardList(const ForwardList &other);
    ~ForwardList();

    friend std::ostream& operator<<(std::ostream& out,const ForwardList& list);
    void push_front(ElemType x);
    void pop_front();
    ElemType get_data(int i=0) const;
    int size() const;
    bool empty() const;
    void print() const;
};
  
#endif // FORWARDLIST_HPP