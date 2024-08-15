#include <iostream>
using namespace std;

class Demo
{
    public:
    Demo()
    {
        cout << "Demo():" << this << endl;
    }
    void print() const
    {
        cout << "hello new and delete" << endl;
    }
    ~Demo()
    {
        cout << "~Demo():" << this << endl;
    }
};



int main()
{
    int *o = new int;
    cout << "o = " << *o << endl;
    Demo *p = new Demo();
    Demo *q = new Demo[10];
    p->print();
    for(int i=0;i<10;i++)
    {
        q[i].print();
    }
    delete o;
    delete p;
    delete []q;
    return 0;
}