#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        p = new int(100);
        cout << "base()" << endl;
    }

    virtual ~Base()
    {
        delete p;
        cout << "~Base()" << endl;
    }

private:
    int *p;
};


class Derived:public Base
{
public:
    Derived()
    {
        q = new int(100);
        cout << "Derived()" << endl;
    }

    ~Derived()
    {
        delete q;
        cout << "~Derived()" << endl;
    }

private:
    int *q;
};


int main()
{
    // Derived d1;

    Base *p = new Derived;
    delete p;
}