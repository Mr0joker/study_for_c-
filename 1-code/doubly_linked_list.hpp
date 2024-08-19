#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP

#include <iostream>

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;
    } *head, *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}// 构造函数
    ~DoublyLinkedList()// 析构函数
    {
        Node *temp = head;
        while (temp!= nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    DoublyLinkedList(const DoublyLinkedList &other) : head(nullptr), tail(nullptr)// 拷贝构造
    {
        Node *temp = other.head;
        while (temp!= nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    DoublyLinkedList &operator=(const DoublyLinkedList &other)//拷贝赋值
    {
        if (this == &other)
            return *this;
        Node *temp = head;
        while (temp!= nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
        Node *temp2 = other.head;
        while (temp2!= nullptr)
        {
            push_back(temp2->data);
            temp2 = temp2->next;
        }
        return *this;
    }
    DoublyLinkedList(DoublyLinkedList &&other) : head(nullptr), tail(nullptr)// 移动构造
    {
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
    }

    DoublyLinkedList &operator=(DoublyLinkedList &&other)//移动赋值
    {
        if (this == &other)
            return *this;
        Node *temp = head;
        while (temp!= nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = other.head;
        tail = other.tail;
        other.head = nullptr;
        other.tail = nullptr;
        return *this;
    }
    
    void push_front(const T &data)//头插法
    {
        // 创建一个新节点
        Node *new_node = new Node;
        new_node->data = data;
        // 如果链表为空，则将新节点作为头节点和尾节点
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else // 否则，将新节点插入到头节点之前
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }
    void push_back(const T &data)//尾插法
    {
        // 创建一个新节点
        Node *new_node = new Node;
        new_node->data = data;
        // 如果链表为空，则将新节点作为头节点和尾节点
        if (tail == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else // 否则，将新节点插入到尾节点之后
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }
    void pop_front()//头删法
    {
        // 如果链表为空，则什么都不做
        if (head == nullptr)
            return;
        // 如果链表只有一个节点，则将头节点和尾节点都设置为nullptr
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else // 否则，删除头节点，并将头节点的下一个节点设置为头节点
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
    void pop_back()//尾删法
    {
        // 如果链表为空，则什么都不做
        if (tail == nullptr)
            return;
        // 如果链表只有一个节点，则将头节点和尾节点都设置为nullptr
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else // 否则，删除尾节点，并将尾节点的上一个节点设置为尾节点
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }
    void insert(const T &data, size_t index)//指定位置插入
    {
        // 如果索引越界，则什么都不做
        if (index > size())
            return;
        // 如果索引为0，则调用push_front
        if (index == 0)
        {
            push_front(data);
            return;
        }
        // 如果索引为size()-1，则调用push_back
        if (index == size() - 1)
        {
            push_back(data);
            return;
        }
        // 创建一个新节点
        Node *new_node = new Node;
        new_node->data = data;
        // 找到插入位置的前一个节点
        Node *prev_node = head;
        for (size_t i = 0; i < index - 1; i++)
            prev_node = prev_node->next;
        // 将新节点插入到前一个节点和后一个节点之间
        new_node->prev = prev_node;
        new_node->next = prev_node->next;
        prev_node->next->prev = new_node;
        prev_node->next = new_node;
    }
    void erase(size_t index)//指定位置删除
    {
        // 如果索引越界，则什么都不做
        if (index >= size())
            return;
        // 如果索引为0，则调用pop_front
        if (index == 0)
        {
            pop_front();
            return;
        }
        // 如果索引为size()-1，则调用pop_back
        if (index == size() - 1)
        {
            pop_back();
            return;
        }
        // 找到删除位置的前一个节点和后一个节点
        Node *prev_node = head;
        for (size_t i = 0; i < index - 1; i++)
            prev_node = prev_node->next;
        Node *del_node = prev_node->next;
        // 删除节点
        prev_node->next = del_node->next;
        del_node->next->prev = prev_node;
        delete del_node;
    }

    T &operator[](size_t index)//下标访问
    {
        // 如果索引越界，则抛出异常
        if (index >= size())
            throw std::out_of_range("Index out of range");
        // 找到访问位置的节点
        Node *temp = head;
        for (size_t i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }
    const T &operator[](size_t index) const//常量下标访问
    {
        // 如果索引越界，则抛出异常
        if (index >= size())
            throw std::out_of_range("Index out of range");
        // 找到访问位置的节点
        Node *temp = head;
        for (size_t i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }


    size_t size() const//获取链表长度
    {
        size_t count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    bool empty() const//判断链表是否为空
    {
        return head == nullptr;
    }

    void print() const//打印链表
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    T at(int index)const//返回指定位置元素
    {
        if (index >= size())
            throw std::out_of_range("Index out of range");
        Node *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->data;
    }
    T front() const//返回头元素
    {
        if (empty())
            throw std::out_of_range("List is empty");
            // std::cout << "List is empty" << std::endl;
            // return T();
        return head->data;
    }
    T back() const//返回尾元素
    {
        if (empty())
            throw std::out_of_range("List is empty");
            // std::cout << "List is empty" << std::endl;
            // return T();
        return tail->data;
    }
    void reverse()//反转链表
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            current->prev = next;
            prev = current;
            current = next;
        }
        head = prev;
        tail = head;
    }
    void clear()//清空链表    
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
        tail = nullptr;
    }

    //迭代器
    class Iterator
    {
    private:
        char *_ptr;

    public:
        Iterator(char *ptr) : _ptr(ptr) {}
        char &operator*() const { return *_ptr; }
        Iterator &operator++() { ++_ptr; return *this; }
    };
    
    Iterator begin() const { return Iterator(reinterpret_cast<char *>(head)); }
    Iterator end() const { return Iterator(reinterpret_cast<char *>(nullptr)); }
};

#endif // DOUBLY_LINKED_LIST_HPP
