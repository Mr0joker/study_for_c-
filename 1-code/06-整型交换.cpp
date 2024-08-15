#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    // Using arithmetic operations to swap values
    int temp = a;
    a = b;
    b = temp;   
    
    // Using bitwise operations to swap values
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    // Using addition and subtraction operations to swap values
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;   
}

/*
    函数重载，可以实现不同类型的参数的交换
    个数不同
    类型不同
    顺序不同
*/

int main()
{
    int a = 10, b = 20;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    int c = 10, d = 20;
    cout << "Before swap: c = " << c << ", d = " << d << endl;
    swap(&c, &d);
    cout << "After swap: c = " << c << ", d = " << d << endl;

    return 0;
}   

// Output:
// Before swap: a = 10, b = 20
// After swap: a = 20, b = 10
// Before swap: c = 10, d = 20
// After swap: c = 20, d = 10   

// Note: 
// 1. In the first swap function, we are using arithmetic operations to swap values.
// 2. In the second swap function, we are using bitwise operations to swap values.
// 3. In the third swap function, we are using addition and subtraction operations to swap values. 
// 4. In the main function, we are calling the swap function twice, once with integers and once with pointers.