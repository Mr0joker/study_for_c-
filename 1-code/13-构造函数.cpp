#include <iostream>
using namespace std;

class Demo
{
public:
    Demo()
    {
        this->x = 0;
        cout << "Constructor called" << endl;
    }
    Demo(int x)
    {
        this->x = x;
        cout << "Constructor with " << x << " parameter called" << endl;
    }

    void print() const
    {
        cout << "x=" << this->x << endl;
    }

private:
    int x;
};

int main()
{
    Demo d1;
    d1.print();

    Demo d2(10);
    d2.print();

    return 0;
}