#include <iostream>
using namespace std;

void foo(int x)
{
    if(x < 0)
        throw "x should be non-negative";
    cout << "x is " << x << endl;   
}

int main()
{
    try
    {   
        foo(3);
        foo(-2);
    }
    catch(const char* msg)
    {
        cout << "Error: " << msg << endl;
    }
    catch(int e)
    {
        cout << "int except:" << e << endl;
    }
    return 0;
}

