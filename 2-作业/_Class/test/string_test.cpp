#include <iostream>
#include "string.hpp"
using namespace std;

int main()
{
    String s1 = "Hello";
    String s2 = "World";

    if (s1 < s2)
        cout << "s1 is less than s2" << endl;
    else if (s1 > s2)
        cout << "s1 is greater than s2" << endl;
    else
        cout << "s1 is equal to s2" << endl;

    String s3 = s1 + s2;
    cout << s3 << endl;
    cout << strlen(s3) << endl;
    cout << empty(s3) << endl;

    s1 += s1;
    cout << s1 << endl;

    cout << s1[3] << endl;

    cout << s1.at(3) << endl;

    return 0;
}