#include <iostream>
using namespace std;

class Complex
{
public:
    Complex(double r = 0, double i = 0) : _r(new double(r)), _i(new double(i)) {}
    ~Complex()
    {
        delete _r;
        delete _i;
    }

    // // 拷贝构造函数
    // Complex(const Complex &other) : _r(new double(*other._r)), _i(new double(*other._i)) {}

    Complex &operator=(const Complex &c2) // 赋值运算符
    {
        cout << "operator=:Complex &c" << endl;
        // if (this != &c2)
        // {
        //     delete _r;
        //     delete _i;
        //     _r = new double(*c2._r);
        //     _i = new double(*c2._i);
        // }
        *this->_r = *c2._r;
        *this->_i = *c2._i;
        return *this;
    }

    friend void print(const Complex &c);

    // Complex operator+(const Complex &c2) // 加法
    // {
    //     double r = *_r + *c2._r;
    //     double i = *_i + *c2._i;
    //     return Complex(r, i);
    // }

    // Complex operator-(const Complex &c2) // 减法
    // {
    //     double r = *_r - *c2._r;
    //     double i = *_i - *c2._i;
    //     return Complex(r, i);
    // }

    // Complex operator*(const Complex &c2) // 乘法
    // {
    //     double r = *_r * *c2._r;
    //     double i = *_i * *c2._i;
    //     return Complex(r, i);
    // }

    // Complex operator/(const Complex &c2) // 除法
    // {
    //     double r = *_r / *c2._r;
    //     double i = *_i / *c2._i;
    //     return Complex(r, i);
    // }

    // bool operator<(const Complex &c2) // 小于
    // {
    //     if (*_r < *c2._r && *_i < *c2._i)
    //         return true;
    //     return false;
    // }

    // bool operator>(const Complex &c2) // 大于
    // {
    //     if (operator<(c2))
    //         return false;
    //     return true;
    // }

    // bool operator==(const Complex &c2) // 等于
    // {
    //     if (*_r == *c2._r && *_i == *c2._i)
    //         return true;
    //     return false;
    // }

    // bool operator!=(const Complex &c2) // 不等于
    // {
    //     if (operator==(c2))
    //         return false;
    //     return true;
    // }

    friend std::ostream &operator<<(std::ostream &out, const Complex &c3);
    // friend std::istream &operator>>(std::istream &in, Complex &c2);

private:
    double *_r;
    double *_i;
};

void print(const Complex &c)
{
    cout << "(r,i)=(" << *c._r << "," << *c._i << "i)" << endl;
}

std::ostream &operator<<(std::ostream &out, const Complex &c3)
{
    out << "Complex(" << *c3._r << "," << *c3._i << "i)";
    return out;
}
  
// std::istream &operator>>(std::istream &in, Complex &c2)
// {
//     cout << "cin:_r" << endl;
//     in >> *c2._r;
//     cout << "cin:_i" << endl;
//     in >> *c2._i;
//     return in;
// }

int main()
{
    Complex c1(29.0, 4.0);
    Complex c2(22.0, 8.0);
    c1 = c2;
    cout << "c1=" << c1 << endl;
    cout << "c2=" << c2 << endl;
    return 0;
}
