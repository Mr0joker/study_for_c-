#include <iostream>
using namespace std;

class Demo
{
public:
    Demo()
    {
        p= new int[10]{1,2,3,4,5};
    }
    const int& operator[](int index)const
    {
        return p[index];
    }
    int& operator[](int index)
    {
        return p[index];
    }
private:
    int* p;
};

void print_demo(const Demo& d)
{
    for(int i = 0 ;i< 10;i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}
int main()
{
    Demo d1;
    int x = d1[0];
    cout << "x= " << x <<endl;

    d1[0] = 100;
    cout << "d1[0]= " << d1[0] << endl;
    print_demo(d1);
    return 0;
}