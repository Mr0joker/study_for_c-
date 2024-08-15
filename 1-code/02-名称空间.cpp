#include <iostream>
using namespace std;
using uint32 = unsigned int;

namespace china
{
    int a;//全局变量在没有初始化时赋值为0
    void print()
    {
        std::cout << "china::a = " << a << std::endl;
    }
};

namespace hunan
{
    int a;
};

int a;

int main(int argc,char const *argv[])
{
    //china::a = 100;
    using namespace china;
    china::a = 10;
    using namespace hunan;
    //a = 20;
    print();
    ::a = 20;
    uint32 b = 88;
    cout << "a=" << ::a << endl;
    return 0;    
}