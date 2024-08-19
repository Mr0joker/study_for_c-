#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{   
    deque<string> a;
    a.push_front("廖");
    a.push_back("孟");
    a.push_back("荣");

    deque<string> b = a;

    auto it = a.begin();
    a.erase(it);
    for(auto x: a)
    {
        cout << x << endl;
    }

    a.emplace_front("廖");
    a.push_front("廖");
    for(auto x: a)
    {
        cout << x << endl;
    }
    return 0;
}