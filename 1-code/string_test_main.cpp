#include <iostream>
#include "string.hpp"
using namespace std;
int main()
{
    String s1("hello world");
    String s2("goodbye world");
    s1.begin();
    s2.begin();
    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}