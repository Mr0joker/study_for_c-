#include "point.hpp"


int main(int argc, char const *argv[])
{
    Point p;
    p.print();
    p.move(100,200);
    p.print();

    return 0;
}