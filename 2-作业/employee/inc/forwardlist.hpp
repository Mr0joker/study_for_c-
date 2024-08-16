#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP

#include <iostream>
using namespace std;
template <typename ElemType>
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
    ForwardList()
    {
        head = nullptr;
    }
    ForwardList(const ForwardList &other)
    {
        head = nullptr;
        Node *p = other.head;
        while (p != nullptr)
        {
            push_front(p->data);
            p = p->next;
        }
    }
    ~ForwardList()
    {
        Node *p = head;
        while (p != nullptr)
        {
            Node *q = p->next;
            delete p;
            p = q;
        }
    }

        void push_front(ElemType x)
    {
        Node *p = new Node;
        p->data = x;
        p->next = head;
        head = p;
    }
    void pop_front()
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
    ElemType get_data(int i = 0) const
    {
        Node *p = head;
        for (int j = 0; j < i; j++)
        {
            if (p == nullptr)
            {
                throw "Error: index out of range";
            }
            p = p->next;
        }
        return p->data;
    }
    int delete_data(int i)
    {
        if (--i < 0 || --i >= this->size())
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
    int size() const
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
    bool empty() const
    {
        return head == nullptr;
    }

    void print() const
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << "->";
            p = p->next;
        }
        cout << "nullptr" << endl;
    }

    template <typename T>
    friend ostream &operator<<(ostream &out, const ForwardList<T> &list);
};

template <typename T>
ostream &operator<<(ostream &out, const ForwardList<T> &list)
{
    // TODO: 在此处插入 return 语句
    typename ForwardList<T>::Node *p = list.head;
    while (p != nullptr)
    {
        out << p->data << "->";
        p = p->next;
    }
    out << "nullptr" << endl;
    return out;
}

#endif // FORWARDLIST_HPP