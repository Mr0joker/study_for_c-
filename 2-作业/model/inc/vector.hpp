#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    T *_data;
    int _size;
    int _capacity;

public:
    Vector() : _size(0), _capacity(0),_data(nullptr) {}
    ~Vector()
    {
        delete[] _data;
    }
    // 插入数据时，如果超出容量，则重新分配内存*2
    void push_back(T data)
    {
        if (_data == nullptr)
        {
            _capacity = 1;
            _data = new T[_capacity];
            _data[_size++] = data;
        }
        else
        {
            if (_size == _capacity)
            {
                _capacity *= 2;
                T *new_data = new T[_capacity];
                for (int i = 0; i < _size; i++)
                {
                    new_data[i] = _data[i];
                }
                delete[] _data;
                _data = new_data;
            }
            _data[_size++] = data;
        }
    }

    // 删除最后一个元素
    void pop_back()
    {
        if (_size > 0)
        {
            _size--;
        }
    }
    // 返回最后一个元素
    T back() const
    {
        if (_size > 0)
        {
            return data[_size - 1];
        }
        return T();
    }
    // 返回元素个数
    int _size() const
    {
        return _size;
    }
    // 判断是否为空
    bool empty() const
    {
        return _size == 0;
    }
    // 返回当前容量
    int capacity() const
    {
        return _capacity;
    }
    // 返回指定位置元素
    T at(int index) const
    {
        if (index < 0 || index > _size - 1)
        {
            throw out_of_range("Error: index out of range");
        }
        return _data[index];
    }
    // 返回指定位置元素
    T operator[](int index) const
    {
        if (index < 0 || index > _size - 1)
        {
            throw out_of_range("Error: index out of range");
        }
        return _data[index];
    }

    // 拷贝构造
    void operator=(const Vector<T> &other)
    {
        if (this == &other)
        {
            return;
        }
        if (_size < other._size)
        {
            delete[] _data;
            _data = new T[other._size];
            _capacity = other._size;
        }
        _size = other._size;
        for (int i = 0; i < _size; i++)
        {
            data[i] = other.data[i];
        }
    }
    // 拷贝赋值
    void operator+=(const Vector<T> &other)
    {
        if (this == &other)
        {
            return;
        }
        if (_size + other._size > _capacity)
        {
            delete[] _data;
            _data = new T[_size + other._size];
            _capacity = _size + other._size;
        }
        for (int i = 0; i < other._size; i++)
        {
            data[_size + i] = other.data[i];
        }
        _size += other._size;
    }
    // 移动构造
    void operator=(Vector<T> &&other)
    {
        if (this == &other)
        {
            return;
        }
        delete[] _data;
        _data = other.data;
        _size = other._size;
        _capacity = other._capacity;
        other.data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }
    // 移动赋值
    void operator+=(Vector<T> &&other)
    {
        if (this == &other)
        {
            return;
        }
        if (_size + other._size > _capacity)
        {
            delete[] _data;
            _data = new T[_size + other._size];
            _capacity = _size + other._size;
        }
        for (int i = 0; i < other._size; i++)
        {
            _data[_size + i] = other.data[i];
        }
        _size += other._size;
        other._data = nullptr;
        other.__size = 0;
        other._capacity = 0;
    }

    // 友元函数
    template <typename U>
    friend ostream &operator<<(ostream &out, const Vector<U> &vec);
};

template <typename U>
ostream &operator<<(ostream &out, const Vector<U> &vec)
{
    typename Vector<U>::const_iterator it = vec.begin();
    for (; it!= vec.end(); it++)
    {
        out << *it << " ";
    }
    return out;
}

#endif // VECTOR_HPP