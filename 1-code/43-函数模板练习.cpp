#include <iostream>
#include "forwardlist.hpp"
#include <string>
using namespace std;

template <class T_swap>
void _swap(T_swap *a, T_swap *b)
{
    T_swap *temp = a;
    a = b;
    b = temp;
}

template <typename T_compare>
int compare(T_compare &a, T_compare &b)
{
    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    return 0;
}

template <typename T_arr,typename T_find>
int find(T_arr arr,T_find num)
{
    int i = 0;
    while(&arr[i]!= nullptr)
    {
        if(arr[i] == num)
            return i;
        i++;
    }
    return -1;
}
  
template <typename T_arr>
int _max(T_arr *arr, int size)
{
    if(arr == nullptr || size <= 0)
        return -1;
    
    T_arr max = arr[0];
    int ret = 0;
    
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            ret = i;
        }
    }
    
    return ret;
}


template <typename T_arr>
int _min(T_arr *arr, int size)
{
    if(arr == nullptr || size <= 0)
        return -1;
    
    T_arr min = arr[0];
    int ret = 0;
    
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] < min)
        {
            min = arr[i];
            ret = i;
        }
    }
    
    return ret;
}


int main()
{
    // 整型
    // int a = 10, b = 20;
    // _swap(a, b);
    // cout << "a = " << a << ", b = " << b << endl;

    // int c = 15, d = 25;
    // int result = compare(c, d);
    // if (result == -1)
    //     cout << c << " is less than " << d << endl;
    // else if (result == 1)
    //     cout << c << " is greater than " << d << endl;
    // else
    //     cout << c << " is equal to " << d << endl;

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int num = 5;
    // int index = find(arr, num);
    // if (index == -1)
    //     cout << "The number " << num << " is not found in the array." << endl;
    // else
    //     cout << "The number " << num << " is found at index " << index << "." << endl;

    // int arr2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // int max_index = _max(arr2, 10);
    // int min_index = _min(arr2, 10);
    // if (max_index == -1)
    //     cout << "The array is empty." << endl;
    // else
    //     cout << "The maximum value is " << arr2[max_index] << " at index " << max_index << "." << endl;
    // if (min_index == -1)
    //     cout << "The array is empty." << endl;
    // else
    //     cout << "The minimum value is " << arr2[min_index] << " at index " << min_index << "." << endl;



    //字符串
    // string str1 = "hello";
    // string str2 = "world";
    // _swap(str1, str2);
    // cout << "str1 = " << str1 << ", str2 = " << str2 << endl;

    // string str3 = "abc";
    // string str4 = "def";
    // int result2 = compare(str3, str4);
    // if (result2 == -1)
    //     cout << str3 << " is less than " << str4 << endl;
    // else if (result2 == 1)
    //     cout << str3 << " is greater than " << str4 << endl;
    // else
    //     cout << str3 << " is equal to " << str4 << endl;

    // string arr3[] = {"apple", "banana", "orange", "grape", "pear"};
    // string num2 = "banana";
    // int index2 = find(arr3, num2);
    // if (index2 == -1)
    //     cout << "The fruit " << num2 << " is not found in the array." << endl;
    // else
    //     cout << "The fruit " << num2 << " is found at index " << index2 << "." << endl;


    // string arr4[] = {"hello", "world", "c++", "java", "python"};
    // int max_index2 = _max(arr4, 5);
    // int min_index2 = _min(arr4, 5);
    // if (max_index2 == -1)
    //     cout << "The array is empty." << endl;
    // else
    //     cout << "The longest string is " << arr4[max_index2] << " at index " << max_index2 << "." << endl;
    // if (min_index2 == -1)
    //     cout << "The array is empty." << endl;
    // else
    //     cout << "The shortest string is " << arr4[min_index2] << " at index " << min_index2 << "." << endl;


    //list
    ForwardList lite1;
    lite1.push_front(1);
    lite1.push_front(2);
    lite1.push_front(3);
    lite1.push_front(4);    
    ForwardList lite2;
    lite2.push_front(5);
    lite2.push_front(6);
    lite2.push_front(7);
    lite2.push_front(8);
    _swap(&lite1, &lite2);
    cout << "lite1 = ";
    lite1.print();
    cout << "lite2 = ";
    lite2.print();


    return 0;
}