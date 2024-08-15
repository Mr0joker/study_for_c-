#include "color.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    {
        Color color;
        color.setColor(255, 0, 0);
        cout << "color:0x" << hex << color.value() << endl;
    }
}