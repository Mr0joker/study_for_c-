#include <iostream>
using namespace std;

class A
{
private:
    int a;
public:
    void print()
    {
        cout << "A" << endl;
    }
};

class B : virtual public A
{
};

class C : virtual public A
{
};

class D : public B, public C
{
};

int main()
{
    cout << sizeof(D) << endl; // 24 bytes on my machine
    
    return 0;
}