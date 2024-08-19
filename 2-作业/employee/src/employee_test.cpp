#include "Employee.hpp"
#include "forwardlist.hpp"
#include <memory>
using namespace std;

int main(int argc, char *argv[])
{
    shared_ptr<Employee> emp1(make_shared<SalaiedEmployee>("廖孟荣1", 200));
    shared_ptr<Employee> emp2(make_shared<CommissionEmployee>("廖孟荣2", 50000, 1));
    shared_ptr<Employee> emp3(make_shared<BasePlusCommissionEmployee>("廖孟荣3", 15000, 1, 100));
    // SalaiedEmployee game1("廖孟荣1", 200);
    // CommissionEmployee game2("廖孟荣2", 50000, 1);
    // BasePlusCommissionEmployee game3("廖孟荣3", 15000, 1, 100);


    // 没写尾插，倒过来push
    ForwardList<shared_ptr<Employee>> employees;
    employees.push_front(emp1);
    employees.push_front(emp2);
    employees.push_front(emp3);

    //打印输出全部信息
    cout << "---print_all---" << endl;
    // 遍历链表
    for (int i = 0; i < employees.size(); i++)
    {
        employees.get_data(i)->print();
    }
    cout << endl;

    //修改链表中的第三类，涨薪
    cout << "---change_base_salary---" << endl;
    // 修改链表
    for (auto it = employees.begin(); it != employees.end(); it++)
    {
        if(auto p = dynamic_pointer_cast<BasePlusCommissionEmployee>(*it).get())
        {
            p->set_base_salary(p->get_base_salary() * 1.1);
        }
    }

    //打印输出涨薪后的全部信息
    cout << "---print_all---" << endl;
    // 遍历链表
    for (int i = 0; i < employees.size(); i++)
    {
        employees.get_data(i)->print();
    }
    cout << endl;



    // cout << endl;
    // cout << "---delete_data(1)---" << endl
    //      << endl;
    // employees.delete_data(1); // 之前为删除第2个，现在修改为删除第1个，并增加了越位判断
    // cout << "---delete_test---" << endl
    //      << endl;
    // employees.delete_data(0);
    // employees.delete_data(5);
    // cout << endl;
    // cout << "---delete_test---" << endl
    //      << endl;
    return 0;
}