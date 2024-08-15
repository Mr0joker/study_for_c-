#include <iostream>
using namespace std;
// function<bool(int)>
int find_if(int *a, int n, auto func)
{
    for(int i = 0; i < n; i++)
    {
        if(func(a[i]))
        {
            return i;
        }
    }
    return -1; // 表示没有找到符合条件的元素
}

int main(int argc, char const *argv[])
{
    int arr[5] = {101,102, 103, 104, 105};
    int index = find_if(arr, 5, [](int x){return x % 3 == 0;});
    cout << "index = " << index << endl;
    // int a = 1;
    // int b = 2;

    // auto c = [=]()->int{return a + b;}();
    // cout << "c = " << c << endl;

    // auto d = [=] {return a + b;}();
    // cout << "d = " << d << endl;

    // [&] {
    //     a++;
    //     b++;
    // }();

    // auto e = [=]
    // {
    //     cout << a << "," << b << endl;
    // };
    // e();
    
    
    return 0;
}
