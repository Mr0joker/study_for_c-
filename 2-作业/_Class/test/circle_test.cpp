#include <iostream>
#include "circle.hpp"
#include "screen.hpp"
using namespace std;


int main()
{
    Screen s;

    Circle c(100);
    c.draw(s);
    return 0;
}