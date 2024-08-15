#include <iostream>

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

int main() {
    A a;
    return 0;
}