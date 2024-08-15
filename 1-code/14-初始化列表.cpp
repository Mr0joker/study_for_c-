#include <iostream>
using namespace std;

class Other
{
private:
    int m_a;
public:
    Other() : m_a(0) {}
    Other(int a) : m_a(a) {}

    int get_a() const
    {
        return m_a;
    }
};

class Demo
{
private:
    int m_x;
    int m_y;
    int const m_z;
    int &m_r;
    Other m_o;
public:
    Demo():m_x(0),m_y(0),m_z(77),m_r(m_x),m_o(0) {}
    Demo(int x, int y, int z, Other o):m_x(x),m_y(y),m_z(z),m_r(x),m_o(o) {}
    void print() const
    {
        cout << "m_x = " << m_x << endl;
        cout << "m_y = " << m_y << endl;
        cout << "m_z = " << m_z << endl;
        cout << "m_r = " << m_r << endl;
        cout << "m_o.get_a() = " << m_o.get_a() << endl;
    }
};

int main()
{
    Demo d1;
    d1.print();
    cout << "----------------------" << endl;
    Demo d2(1, 2, 3, Other(4));   // 调用构造函数
    d2.print();
    return 0;
}