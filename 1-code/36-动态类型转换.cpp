#include <iostream>
using namespace std;

class Base{
    public:
    virtual ~Base() {};
};
class Derived1:public Base{};
class Derived2:public Base{};

int main()
{
    Base *p = new Derived1;
    Derived1 * p1 = dynamic_cast<Derived1*>(p);
    if(p1 != nullptr)
    {
        cout << "dynamic_cast->Derived1 seccess" << endl;
    }else
    {
        cout << "dynamic_cast->Derived1 failed" << endl;
    }

    Derived2 * p2 = dynamic_cast<Derived2*>(p);
    if(p2 != nullptr)
    {
        cout << "dynamic_cast->Derived2 seccess" << endl;
    }
    else
    {
        cout << "dynamic_cast->Derived2 failed" << endl;
    }
    

    delete p;
    return 0;
}
