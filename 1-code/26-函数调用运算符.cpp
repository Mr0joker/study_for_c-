#include <iostream>
using namespace std;

class Demo
{
public:
    void operator()()
    {
        cout << "hello world" << endl;
    }
    void operator()(int x)
    {
        cout << "x=" << x << endl;
    }
    void operator()(int x, int y)
    {
        cout << "x=" << x << ",y= " << y << endl;
    }
};

class Pint8
{
public:
    Pint8(char c = ' ') : c(c) {}
    void operator()(int x)
    {
        cout << oct << x << c;
    }
    void setC(char c)
    {
        this->c = c;
    }
private:
    char c;
};


void print_int8(int x)
{
    cout << oct << x << " ";
}

void print_int16(int x)
{
    cout << hex << x << " ";
}

void print_int10(int x)
{
    cout << x << " ";
}

void print_array(int a[], int n, void (*f)(int))
{
    for (int i = 0; i < n; i++)
    {
        f(a[i]);
    }
    cout << endl;
}


void print_array(int a[], int n, Pint8 f)
{
    for (int i = 0; i < n; i++)
    {
        f(a[i]);
    }
    cout << endl;
}


int main()
{
    Demo d;
    d();
    d(100);
    d(200, 500);

    int a[5] = {101, 102, 103, 104, 105};
    print_array(a, 5, print_int8);
    print_array(a, 5, print_int16);
    Pint8 p8;
    p8.setC('-');
    print_array(a,5,p8);

    // print_array(a, 5, [](int &x){x++;});
    // print_array(a, 5, [](int &x){x*=2;});
    return 0;
}