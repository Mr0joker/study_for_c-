#include <iostream>
using namespace std;

void foo(const char *name = "廖慕容", int age = 20);

int pow(int base, int mi = 2);

int main(int argc, char const *argv[])
{
    foo();
    foo("关羽");
    foo("刘备", 30);

    cout << "pow(3) = " << pow(3) << endl;
    cout << "pow(2,3) = " << pow(2, 3) << endl;
    return 0;
}

void foo(const char *name, int age)
{
    cout << name << ":" << age << endl;
}

int pow(int base, int mi)
{
    // int ret = 1;
    // for (int i = 0; i < mi; i++)
    // {
    //     ret *= base;
    // }
    // return ret;
    if (0 == mi)
        return 1;
    return base * pow(base, mi - 1);
}