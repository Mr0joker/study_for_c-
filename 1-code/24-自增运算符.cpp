#include <iostream>
using namespace std;

class Complex
{
public:
    friend std::ostream &operator<<(std::ostream &out, Complex c3);
    friend Complex &operator--(Complex &c);
    friend Complex operator--(Complex &c, int);
    friend Complex &operator++(Complex &c);
    friend Complex operator++(Complex &c, int);
    Complex(double r, double i) : _r(r), _i(i) {}

private:
    double _r;
    double _i;
};

std::ostream &operator<<(std::ostream &out, Complex c3)
{
    out << "Complex(" << c3._r << ", " << c3._i << "i)";
    return out;
}

Complex &operator++(Complex &c) // 前++
{
    ++c._r;
    ++c._i;
    return c;
}

Complex &operator--(Complex &c) // 前--
{
    --c._r;
    --c._i;
    return c;
}

Complex operator++(Complex &c, int) // 后++
{
    return Complex(c._r++, c._i++);
}

Complex operator--(Complex &c, int) // 后--
{
    return Complex(c._r--, c._i--);
}

int main()
{
    Complex c1(1, 1);

    Complex c2 = c1++;

    cout << c1 << endl;
    cout << c2 << endl;
    return 0;
}