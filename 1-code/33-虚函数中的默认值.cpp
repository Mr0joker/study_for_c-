#include <iostream>
using namespace std;

class A {
public:
    virtual void f(int x = 0) {
        cout << "A::f(" << x << ")" << endl;
    }
};

class B : public A {

public:
    virtual void f(int x = 1) {
        cout << "B::f(" << x << ")" << endl;
    }
};

int main() {
    A* a = new A;
    a->f();
    a->f(1);
    delete a;

    B* b = new B;
    b->f();
    b->f(2);
    delete b;

    return 0;
}