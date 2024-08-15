#include <iostream>
#include <string.h>
using namespace std;

bool isdigit(char c)
{
    return c >= 'a' && c <= 'z';
}


void print_digit(char* a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (isdigit(a[i]))
            a[i] = a[i] - 'a' + 'A';
        cout << a[i];
    }
    cout << endl;
}


int main(int argc, char const *argv[])
{
    // int i = sizeof(bool);
    // cout << i << endl;
    char a[128];
    cin >> a;
    print_digit(a);
    return 0;
}