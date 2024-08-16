#include <iostream>

class A{ 
public: 
    void *p1; 
    virtual void foo1(){};
    virtual void foo2(){};
    virtual void foo3(){};
private: 
    void *p2; 
protected: 
    void *p3; 
}; 

class B: public A {
    void foo1() override{}
    void foo2() override{}
    void foo3() override{}
};




int main() {
    std::cout << sizeof(B) << std::endl;
    return 0;
}