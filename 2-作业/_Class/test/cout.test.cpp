#include "forwardlist.hpp"
#include <iostream>
using namespace std;

int main()
{
    ForwardList list;
    list.push_front("A");
    list.push_front("B");
    list.push_front("C");
    list.push_front("D");
    list.push_front("E");
    cout << list << endl;
}