#include <map>
#include <iostream>
using namespace std;
#include <string>

template <typename T>
void print_map(const T &m)
{
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ":" << it->second << endl;
    }
}

int main()
{
    multimap<string, string> m;

    pair<string, string> p1("廖", "3cm");
    m.insert(p1);
    m.insert(pair<string, string>("孟", "3cm"));
    m.insert(make_pair("荣", "3cm"));
    m.insert({"廖孟荣", "3cm"});
    // m["廖孟荣"] = "2000月薪";错误，multimap不支持下标操作
    cout << m.size() << endl;
    print_map(m);

    auto it2 = m.find("廖孟荣");
    if (it2 != m.end())
    {
        cout << it2->first << "->" << it2->second << endl;
    }
    else
    {
        cout << "not found!" << endl;
    }

    print_map(m);
    return 0;
}