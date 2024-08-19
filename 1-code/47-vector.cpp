#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Demo
{
public:
    Demo(int a,int b):x(a),y(b){}
    int x;int y;
};



template <typename T>
void print_vector(const vector<T> &a)
{
//     for(auto it = a.begin();it!= a.end();++it)
//     {
//         cout << *it << " ";
//     }
    for (auto x : a) // 需要迭代器：语法糖 ; 范围for循环
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    // vector<int> a;
    // for (int i = 0; i < 10; i++)
    // {
    //     a.push_back(i);
    // }
    // print_vector(a);

    // a[0] = 10;
    // print_vector(a);

    // auto it = a.begin();
    // *it = 100;
    // print_vector(a);

    // for_each(a.begin(), a.end(), [](int x)
    //          { cout << x << ", "; });
    // cout << endl;

    // a.erase(it + 2);
    // print_vector(a);

    // a.pop_back();
    // print_vector(a);



    cout << "________________________________________" << endl;


    vector<Demo> b;
    Demo d1(1,1);
    b.push_back(d1);
    b.push_back(Demo(2,2));
    b.emplace_back(3,3);
    b.emplace_back(4,4);
    cout << b.size() << endl;
    print_vector(b);
    return 0;
}