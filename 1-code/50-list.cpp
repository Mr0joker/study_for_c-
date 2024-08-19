#include <iostream>
#include <list>

#include <string>
using namespace std;

int main()
{
    list<string> lmr;
    lmr.push_back("廖");
    lmr.push_back("孟");
    lmr.push_back("荣");
    lmr.push_back("和");
    lmr.push_back("潘");
    lmr.push_back("周");
    lmr.push_back("单");

    for(auto x : lmr)
    {
        cout<< x ;
    }

    cout << endl;

    lmr.reverse();

    for(auto x : lmr)
    {
        cout<< x ;
    }

    cout << endl;
    return 0;
}