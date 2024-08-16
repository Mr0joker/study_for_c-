#ifndef MYSTACK_HPP
#define MYSTACK_HPP

template <typename T>
class SeqStack
{
public:
    SeqStack(int n): _top(-1), _max(n)
    {
        _data = new T[_max];
    }
    ~SeqStack();
    void push(T data)
    {
        if (_top == _max - 1)
        {
            // stack overflow
            return;
        }
        _data[++_top] = data;
    }
    void pop();
    T top() const
    {
        if(_top == -1)
        {
            // stack underflow
            return T();
        }
        return _data[_top];
    }
    bool empty() const
    {
        return _top == -1;
    }

private:
    T *_data;
    int _top;
    int _max;
};

template<typename T>
SeqStack<T>::~SeqStack()
{
    delete [] _data;
}

template<typename T>
void SeqStack<T>::pop() 
{
    if(_top == -1)
    {
        // stack underflow
        return;
    }
    _top--;
}


#endif