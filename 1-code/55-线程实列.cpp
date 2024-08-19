#include <iostream>
#include <thread>
using namespace std;

void task1()
{
    cout << "thread id:" << this_thread::get_id() << endl;
    this_thread::sleep_for(1s);
}

void task2(int n)
{
    for(int i=0;i<n;i++)
    {
        cout << "thread id:" << this_thread::get_id() << endl;
        this_thread::sleep_for(1s);
    }
}


void task3(int&n)
{
    while(n--)
    {
        cout << "thread id:" << this_thread::get_id() << endl;
        this_thread::sleep_for(1s);
    }
}

int main()
{
    thread t1(task1);
    thread t2(task2, 5);
    int n= 5;
    thread t3(task3,ref(n));

    t1.join();
    t2.join();
    t3.join();
    return 0;

}