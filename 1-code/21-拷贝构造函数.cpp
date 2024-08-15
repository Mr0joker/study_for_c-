#include <iostream>

using namespace std;

class Demo {
public:
    Demo() {  
        new int(*m_x);
        *m_x = 0;
        cout << "Demo()" << endl;
    }
    Demo(int x) {  
        new int(*m_x);
        *m_x = x;
        cout << "Demo(int x)" << endl;
    }

    Demo(const Demo& a) {  
        new int(*m_x);
        *m_x = *a.m_x;
        cout << "Demo(const Demo& a)" << endl;
    }
    ~Demo() {  
        delete m_x;
        cout << "~Demo()" << endl;
    }
private:
        int *m_x;
        
};


void foo(Demo a)
{
    cout << "foo(Demo a)" << endl;
}

Demo foo()
{
    static Demo a;
    return a;
}

int main()
{
    Demo a1(10);
    Demo a2 = a1;
    foo(a2);
    foo();
    Demo a3 = foo();
    return 0;
}