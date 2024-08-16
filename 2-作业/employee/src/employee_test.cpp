#include "Employee.hpp"
#include "forwardlist.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    SalaiedEmployee game1("廖孟荣1", 200);
    CommissionEmployee game2("廖孟荣2", 50000, 1);
    BasePlusCommissionEmployee game3("廖孟荣3", 15000, 1, 100);
    

    // 没写尾插，倒过来push
    ForwardList<Employee*> employees;
    employees.push_front(&game3);
    employees.push_front(&game2);
    employees.push_front(&game1);

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
    for (int i = 0; i < employees.size(); i++)
    {
        // 判断BasePlusCommissionEmployee类型
        if (dynamic_cast<BasePlusCommissionEmployee *>(employees.get_data(i)))
        {
            BasePlusCommissionEmployee *temp = dynamic_cast<BasePlusCommissionEmployee *>(employees.get_data(i));
            cout << temp->get_name() << "`s ";
            cout << "base salary has increased by" << temp->get_base_salary() * 0.1 << endl;
            temp->set_base_salary(temp->get_base_salary() * 1.1);  
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