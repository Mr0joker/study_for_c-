#include <iostream>
using namespace std;

class A{
    public:
        virtual void print() {
            cout << "A::print()" << endl;
        }
};

class B: public A{
    public:
        virtual void print() {
            cout << "B::print()" << endl;
        }
};

class C: public A{
    public:
        virtual void print() {
            cout << "C::print()" << endl;
        }
};

void bar(A* a) {
    a->print();
}

int  main()
{
    bar(new A);
    bar(new B);
    bar(new C);
    return 0;
}

