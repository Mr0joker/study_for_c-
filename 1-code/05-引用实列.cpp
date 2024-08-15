#include <iostream>
using namespace std;

void foo(int &r2) // 引用作为函数参数
{
    r2 = 300; // 改变a的值
}

int main()
{
    int a = 100;
    int &r = a; // 引用变量b指向a

    cout << "a = " << a << endl; // 输出a的值
    cout << "r = " << r << endl; // 输出b的值

    r = 20;                      // 改变a的值，b也会跟着改变
    cout << "a = " << a << endl; // 输出a的值
    cout << "r = " << r << endl; // 输出b的值

    cout << "&a = " << &a << endl;
    cout << "&r = " << &r << endl;

    foo(a);
    cout << "a = " << a << endl; // 输出a的值
    return 0;
}