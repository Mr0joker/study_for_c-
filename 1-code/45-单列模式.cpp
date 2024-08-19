#include <iostream>

class Singleton
{
public:
    //静态成员函数
    static Singleton *instance()
    {
        //从c++11开始，静态局部对象保证线程安全
        static Singleton s;
        return &s;
    }

    int getValue()
    {
        return _value;
    }

    void setValue(int value)
    {
        _value = value;
    }

protected:
    //构造函数
    Singleton() : _value(0) {}
    //删除拷贝操作
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

private:
    int _value;
};


void foo()
{
    Singleton *s1 = Singleton::instance();
    std::cout << "foo: " << s1 << std::endl;
}

int main()
{
    Singleton *s1 = Singleton::instance();
    s1->setValue(100);
    int value = s1->getValue();
    std::cout << "value: " << value << std::endl;

    foo();

    Singleton *s2 = s1;

    foo();

    return 0;
}