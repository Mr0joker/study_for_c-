#include <iostream>
using namespace std;

void f1()
{
    double a = 3.14;
    int b = static_cast<int>(a);
    char c = static_cast<char>(b);

    cout << "a=" << a << endl
         << "b=" << b << endl
         << "c=" << static_cast<int>(c) << endl;
}

void f2()
{
    double d = 3.14;
    int *p = reinterpret_cast<int *>(&d);
    cout << *p << endl;
    double *q = reinterpret_cast<double *>(p);
    cout << *q << endl;
}

void f3(const int &r)
{
    cout << r << endl;
    int &r1 = const_cast<int&>(r);
    r1 = 200;
    cout << r << "," <<r1 << endl;
}

int main(int argc, char const *argv[])
{
    f1();
    f2();
    int r = 100;
    f3(r);
    return 0;
}