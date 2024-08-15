#include <iostream>
#include <cstring>
using namespace std;

class Demo
{
public:
    Demo()
    {
        p = new char[100];
        strcpy(p, "hello world");
    }
    Demo(const Demo &other)
    {
        p = new char[100];
        for (int i = 0; i < 100; i++)
        {
            p[i] = other.p[i];
        }
    }
    Demo(Demo &&other)
    {
        p = other.p;
        other.p = nullptr;
    }
    Demo &operator=(Demo &&other)
    {
        if (this != &other)
        {
            delete[] p;
            p = other.p;
            other.p = nullptr;
        }
        return *this;
    }
    ~Demo()
    {
        delete[] p;
    }
    void print_addr() const
    {
        printf("p = %p\n", p);
    }

private:
    char *p;
};

int main()
{
    Demo d1;
    Demo d2 = d1;
    d1.print_addr();
    d2.print_addr();
    cout << "------------------------" << endl;
    Demo d3 = std::move(d1);
    d1.print_addr();
    d3.print_addr();
    return 0;
}