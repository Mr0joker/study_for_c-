#include <iostream>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << "max(" << a << ", " << b << ") = " << max(a, b) << endl;
    cout << "min(" << a << ", " << b << ") = " << min(a, b) << endl;
    cout << "max(" << a << ", " << b << ", " << c << ") = " << max(max(a, b), c) << endl;
    cout << "min(" << a << ", " << b << ", " << c << ") = " << min(min(a, b), c) << endl;
    return 0;
}

//! 2.引用与指针有什么区别？

/*
引用（reference）和指针（pointer）是C++中两个重要的概念。它们的主要区别如下：
1. 引用（reference）：引用是另一种数据类型，它是另一个变量的别名，也就是说，它是已存在变量的另一个名字。引用的声明语法为：类型别名& 变量名 = 已存在变量名;
2. 指针（pointer）：指针是一个变量，它指向另一个变量的内存地址。指针的声明语法为：类型别名* 变量名 = &已存在变量名;
引用和指针的主要区别在于：
1. 引用的生命周期：当引用的生命周期结束时，它所指向的对象也就被销毁了。
2. 指针的生命周期：当指针的生命周期结束时，它所指向的内存地址也就被释放了，但是它指向的对象并没有被销毁。
3. 引用的类型：引用的类型必须与它所指向的对象类型一致。
4. 指针的类型：指针的类型可以是任意的，但是必须与它所指向的对象类型一致。
5. 引用的初始化：引用的初始化可以是变量名、表达式、函数调用的结果等。
6. 指针的初始化：指针的初始化只能是变量名、表达式、函数调用的结果等。
7. 引用的作用：引用的作用是简化代码，提高程序的可读性。
8. 指针的作用：指针的作用是直接访问内存地址，可以对内存进行读写操作。
*/

//! 3.int/float/bool/指针 如何与零值比较？

/*
int/float/bool/指针
int == 0
float f >= -0.000001 && f <=0.000001
bool == false
p == NULL;
*/

//! 4.如何使用cout输出整数的二进制、八进制、十六进制表示？

/*
    1. 二进制：cout << bitset<32>(num) << endl;
    2. 八进制：cout << oct << num << endl;
    3. 十六进制：cout << hex << num << endl;
*/

//! 5.如何使用cin输入整数的二进制、八进制、十六进制表示？

/*
    1. 二进制：int num; cin >> bitset<32>(num);
    2. 八进制：int num; cin >> oct >> num;
    3. 十六进制：int num; cin >> hex >> num;
*/

//! 6.文件操作中显示屏与位图显示
/*
    1.打开显示器
    open("/dev/event0", O_RDONLY)


    2.打开位图显示
    open("/dev/fb0", O_RDWR)
*/
