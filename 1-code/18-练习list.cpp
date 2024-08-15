#include "forwardlist.hpp"

int main()
{
    ForwardList list;
    // list.push_front("廖孟荣");
    // list.push_front("CS2411");
    // list.push_front("18"); 
    list.push_front(18);
    list.push_front(2411);
    list.push_front(2024);
    list.print();
    return 0;
}