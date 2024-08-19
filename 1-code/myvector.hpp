#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <stdexcept>

template <typename T>
class Vector
{
public:
    Vector() : _size(0), _capacity(0), _data(nullptr) {}

    ~Vector()
    {
    }
    void push_back(T data) // 插入数据时，如果容量不足，则扩容
    {
        if (_data == nullptr)
        {
            _capacity = 1;
            _data = new T[_capacity];
        }
        else
        {
            if (_size >= _capacity)
            {
                _capacity *= 2;
                T *tmp = new T[_capacity];
                for (int i = 0; i < _size; i++)
                {
                    tmp[i] = _data[i];
                }
                delete[] _data;
                _data = tmp;
            }
        }
        _data[_size++] = data;
    }
    void pop_back();
    T back() const;
    int size() const
    {
        return _size;
    }
    bool empty() const
    {
        return _size == 0;
    }
    int capacity() const
    {
        return _capacity;
    }
    T at(int index) const
    {
        if (index < 0 or index >= _size)
            throw std::out_of_range("index out of range!");
        return _data[index];
    }
    // operator[]
    // operator<<

    // 拷贝构造
    //     拷贝赋值
    //         移动构造
    //             移动赋值

    // 嵌套的迭代器类型
    class Iterator
    {
    public:
        Iterator(T *p) : p(p) {}
        bool operator!=(const Iterator &other) const
        {
            return this->p != other.p;
        }
        Iterator &operator++()
        {
            p++;
            return *this;
        }
        T &operator*()
        {
            return *p;
        }

    private:
        T *p;
    };

    // 两个专门的接口
    Iterator begin()
    {
        return Iterator(_data);
    }
    Iterator end()
    {
        return Iterator(_data + _size);
    }

private:
    T *_data;
    int _size;     // 当前元素的个数
    int _capacity; // 最多能存放多少个元素
};

#endif
