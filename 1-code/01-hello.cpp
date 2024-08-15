#include <iostream>
using namespace std;
 
// main() 是程序开始执行的地方
 
int main(int argc,char const *argv[])
{
   cout << "Hello World" << endl; // 输出 Hello World
   int a;
   int b;
   cout << "stdin a" << endl;
   cin >> a;
   cout << "stdin b" << endl;
   cin >> b;
   cout << a << "+" << b << "=" << a + b << endl; // 输出 a+b=a+b
   return 0;
}