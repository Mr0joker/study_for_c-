#include <iostream>
using namespace std;

class Base
{
public:
    virtual void foo()
    {
        cout << "Base::foo()" << endl;
    }
    virtual void bar()
    {
        cout << "Base::bar()" << endl;
    }
};

class Derived : public Base
{
public:
    void bar() override
    {
        cout << "Derived::bar()" << endl;
    }
    virtual void show() {}
};

int main(int argc, char **argv)
{
    cout << sizeof(Base) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    Base b;
    long long*p = reinterpret_cast<long long*>(&b);
    long long*vptr = reinterpret_cast<long long*>(*p);

    void (*test)();
    test = reinterpret_cast<void (*)()>(vptr[0]);
    test();
    test = reinterpret_cast<void (*)()>(vptr[1]);
    test();
    // test = reinterpret_cast<void (*)()>(vptr[2]);
    // test();

    Derived d;
    p = reinterpret_cast<long long*>(&d);
    vptr = reinterpret_cast<long long*>(*p);

    test = reinterpret_cast<void (*)()>(vptr[0]);
    test();
    test = reinterpret_cast<void (*)()>(vptr[1]);
    test();
    // test = reinterpret_cast<void (*)()>(vptr[2]);
    // test();

    return 0;
}