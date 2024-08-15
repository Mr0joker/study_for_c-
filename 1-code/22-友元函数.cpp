#include <iostream>
using namespace std;

// 友元函数
class Demo;
// 友元类
class Other
{
public:
    void print_demo(Demo d);
};

// 类Demo
class Demo
{
public:
    Demo(int x) : x(x) {}
    friend void print_demo(Demo d);
    // friend void Other::print_demo(Demo d);
    friend class Other; 
private:
    int x;
};

// 友元函数
void Other::print_demo(Demo d)
{
    cout << d.x << endl;
}

// 类Demo的友元函数
void print_demo(Demo d)
{
    cout << d.x << endl;
}


int main()
{
    Demo d(10);
    print_demo(d);

    Other o;
    o.print_demo(d);

    return 0;
}
