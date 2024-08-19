//  1.编写一个函数，实现输入一个字符串，对字符串中的各个字符
//  按照统计个数 由多到少输出各字符，如果统计的个数相同，则按ASCII码由小到大排序输出字符
//    如： "aabbb22bb2cc", 输出：b2ac
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void sort_string(string str)
{
    // 定义一个map，为字符串和字符串的数目
    map<char, int> m;

    // 遍历字符串，统计各字符的数目
    for (int i = 0; i < str.length(); i++)
    {
        if (m.find(str[i]) != m.end()) // 如果字符已经在map中，则数目加1
        {
            m[str[i]]++;
        }
        else // 如果字符不在map中，则插入字符和数目
        {
            m[str[i]] = 1;
        }
    }

    // 将map中的元素存入vector
    // vector的元素为pair<char,int>
    // vector<pair<char,int>> v(map.begin(),map.end());
    vector<pair<char, int>> v;
    for (auto it = m.begin(); it != m.end(); it++) // for循环可以用C++11中写法实现
    {
        v.push_back(*it);
    }
    // 对vector进行排序，按照数目由多到少排序，如果数目相同，则按ASCII码由小到大排序
    sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b)
         {
            if(a.second!= b.second)
                {
                    return a.second > b.second;
                }
            else
                {
                    return a.first < b.first;
            } 
        });

    // 输出排序后的字符
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first;
        if (i != v.size() - 1)
        {
            cout << ",";
        }
    }
    cout << endl;
}

int main()
{
    string str = "aabbb22bb2cc";
    sort_string(str);
    return 0;
}
