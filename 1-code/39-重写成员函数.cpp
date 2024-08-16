#include <iostream>
using namespace std;
class A
{
public:
    void f() { cout << "A::f()"; }
};
class B : public A
{
public:
    void f() { cout << "B::f()"; }
};

int main()
{
    B b;
    b.f();
    return 0;
}