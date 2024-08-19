#include <iostream>
#include <set>
#include <string>

using namespace std;

template<typename T>
void print_set(const multiset<T>& s)
{
    for(auto it = s.begin(); it!= s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    multiset<string>  s;
    s.insert("廖孟荣3cm");
    s.insert("拳打廖孟荣");
    s.insert("脚踢廖孟荣");
    s.insert("黑神话悟空");
    s.insert("黑神话八戒");
    s.insert("黑神话悟净");
    s.insert("黑神话唐僧");
    
    cout << s.size() << endl;
    print_set(s);
    return 0;
}
