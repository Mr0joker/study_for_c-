#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 200> a = {20,19,18,17,16,15,14,13,12,11,10};
    cout << a.front() << endl;
    cout << a.size() << endl;
    a.fill(2024);
    cout << a.front() << endl;

    array<int, 200> b = {20,19,18,17,16,15,14,13,12,11,10};
    a.swap(b);
    for (auto x : a) // 需要迭代器：语法糖 ; 范围for循环
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : b) // 需要迭代器：语法糖 ; 范围for循环
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}