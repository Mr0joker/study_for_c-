#include <iostream>
#include <string.h>
using namespace std;

bool isdigit(char c)
{
    return c >= '0' && c <= '9';
}


void print_digit(char* a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        if (isdigit(a[i]))
            cout << a[i];
    }
    cout << endl;
}


int main(int argc, char const *argv[])
{
    char a[128];
    cin >> a;
    print_digit(a);
    return 0;
}