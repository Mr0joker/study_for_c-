#include <iostream>
#include "time.hpp"
using namespace std;


int main()
{
    Time t;
    cout << t.get_local_Time() << endl;
    // cout << t.get_uct_Time() << endl;
    
    return 0;
}