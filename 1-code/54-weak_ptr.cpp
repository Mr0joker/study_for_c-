#include <iostream>
#include <memory>

using namespace std;
weak_ptr<int> gw;

void observe()
{
    cout << "gw.use_count: " << gw.use_count() << "; ";

    if(!gw.expired())//检查gw指向的对象是否过期
    {
        shared_ptr<int> spt = gw.lock();
        cout << "*spt == " << *spt << endl;
    }
    else 
    {
        cout << "gw已过期\n" ;
    }
}

int main()
{
    {
        auto sp = make_shared<int>(100);
        gw = sp;
        observe();
    }
    observe();
    return 0;
}