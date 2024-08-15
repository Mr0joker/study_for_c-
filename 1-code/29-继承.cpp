#include <iostream>
using namespace std;

class Base
{
private:
    int a;
    int b;
    int c;

public:
    Base(int x, int y, int z) : a(x), b(y), c(z)
    {
        cout << "base(int,int,int)" << endl;
    }
    Base() : a(0), b(0), c(0)
    {
        cout << "base()" << endl;
    }
    int getA()const
    {
        return a;
    }
    int getB()const
    {
        return b;
    }
    int getC()const
    {
        return c;
    }
    void pring() const
    {
        cout << "a=" << a << " b=" << b << " c=" << c << endl;
    }
    ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base
{
private:
    int d;
    int e;
    int f;

public:
    Derived() : Base(), d(0), e(0), f(0)
    {
        cout << "Derived()" << endl;
    }
    Derived(int x, int y, int z, int w, int v, int u) : Base(x, y, z), d(w), e(v), f(u)
    {
        cout << "Derived(int,int,int,int,int,int)" << endl;
    }
    void print() const
    {
        cout << "a=" << getA() << " b=" << getB() << " c=" << getC() << " d=" << d << " e=" << e << " f=" << f << endl;
    }
    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

int main()
{
    // Derived d1;
    // d1.print();
    // cout << "---------------------"<<endl;
    // d1.Base::pring();
    // cout << "---------------------"<<endl;
    // Derived d(1, 2, 3,4,5,6);
    // d.print();
    Derived d1(1, 2, 3,4,5,6);
    Base b1 = d1;

    b1 = d1;

    Base* p = &d1;

    Base& r = d1;
    cout << "---------------------"<<endl;
    p->pring();
    cout << "---------------------"<<endl;
    return 0;
}
