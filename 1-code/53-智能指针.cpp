#include <iostream> 
#include <memory>

using namespace std;

class MyClass
{

public:
    MyClass(int d) : data(d)
    {
        cout << "MyClass()" << endl;
    }

    ~MyClass()
    {
        cout << "~MyClass()" << endl;
    }
    int get_data() const
    {
        return data;
    }

private:
    int data;
};

int main()
{
    shared_ptr<MyClass> p1(new MyClass(200));
    shared_ptr<MyClass> p2(p1);
    cout << "p1->get_data() = " << p1->get_data() << endl;
    cout << "p2->get_data() = " << p2->get_data() << endl;
    p1.reset();
    cout << "p1.reset()" << endl;
    cout << "p2->get_data() = " << p2->get_data() << endl;  

    return 0;
}