#include "mystack.hpp"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    SeqStack<int> stack1(10);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    while (!stack1.empty())
    {
        cout << stack1.top() << endl;
        stack1.pop();
    }
    // SeqStack<std::string> stack2(5);
    return 0;
}
