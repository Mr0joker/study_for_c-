#include <iostream>
using namespace std;
template <typename T>
void myswap(T &a,T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

void foo(){}


int main()
{
    int a = 12;
    int b = 22;
    cout << a << "," << b << endl;
    myswap(a,b);
    cout << a << "," << b << endl;

    double x = 1.1;
    double y = 2.2;
    cout << x << "," << y << endl;
    myswap(x,y);
    cout << x << "," << y << endl;
    return 0;
}