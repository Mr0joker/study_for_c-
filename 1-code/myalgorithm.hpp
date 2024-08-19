#ifndef MYALGORITHM_HPP
#define MYALGORITHM_HPP

#include <cstring>

template <typename T>
void myswap(T &a, T &b)
{
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template <class T>
T mymax(T a, T b)
{
    return a > b ? a : b;
}
template <class T>
int find_value(T a[], int n, T value)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == value)
            return i;
    }
    return -1;
}

template<typename Iterator, typename T>
Iterator find_value(Iterator first, Iterator last, T value) 
{
    for (; first != last; ++first)
    {
        if (*first == value)
            return first;
    }
    return last;
}

template<typename Iterator, typename Func>
void foreach(Iterator first, Iterator last, Func f)
{
    for (; first != last; ++first)
    {
        f(*first);
    }
}



template <typename T>
int mycompare(T a, T b)
{
    if (b < a)
        return 1;

    if (a < b)
        return -1;

    return 0;
}

template <>
int mycompare(const char *a, const char *b)
{
    if (strcmp(a, b) > 0)
        return 1;

    if (strcmp(a, b) < 0)
        return -1;

    return 0;
}

#endif