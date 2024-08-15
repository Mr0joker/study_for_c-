#include <iostream>

using namespace std;

class Boyfriend
{
private:
    string name;
    int age;
    string wchat;

public:
    Boyfriend(string name, int age, string wchat)
    {
        this->name = name;
        this->age = age;
        this->wchat = wchat;
    }
    void sayHello()
    {
        cout << "Hello, my name is " << name << " and I am " << age << " years old." << endl;
    }
    void saywchat()
    {
        cout << "my wchat is " << wchat << "." << endl;
    }
    void saylove()
    {
        cout << "I love you!" << endl;
    }
    void setname(string name)
    {
        this->name = name;
    }
    void setage(int age)
    {
        this->age = age;
    }
    void setwchat(string wchat)
    {
        this->wchat = wchat;
    }
    
    
};

int main()
{
    Boyfriend g("廖孟荣", 21, "im pig");
    g.sayHello();
    g.saylove();
    g.saywchat();
    return 0;
}