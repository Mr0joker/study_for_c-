#include <iostream>
#include <string>

using namespace std;    

int main()
{
    string str1 = "Hello str1!";  
    cout << str1.size() << "," << str1.empty() << endl;
  
    string str2 = "Hello str2!";
    cout << str2.size() << "," << str2.empty() << endl;
    
    string str3 = str1 + " " + str2;
    cout << str3.c_str() << endl;
    
    bool flag = (str1.c_str() == "Hello str1!");
    cout << flag << endl;
    

    return 0;
}
    