#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        foo();
    }
    virtual void foo() 
    {
        cout << "hello" << endl;
    }
};
class Derived : public Base
{
public:
    Derived()
    {
        foo();
    }
    void foo() override
    {
        cout << "override" << endl;
    }
};

void foo(Base b)
{
    b.foo();
}

int main()
{
    // Base *p = new Base;
    Base* p = new Derived;
    return 0;
}