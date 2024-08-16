#include "employee.hpp"
#include <iostream>
#include <string>
using namespace std;

int Employee::employee_id = 0; // 定义一个静态成员变量，对加入的员工进行编号

// 员工类
Employee::Employee(string new_name) : name(new_name), id(++employee_id) {}
Employee::~Employee() = default;

// 打印员工信息
void Employee::print()
{
    cout << "ID: " << get_id() << " " << "name: " << get_name() << endl;
}

// 设置和获取员工的姓名
void Employee::set_name(string new_name) { name = new_name; }
string Employee::get_name() const { return name; }
// 设置和获取员工的ID
void Employee::set_id(int new_id) { id = new_id; }
int Employee::get_id() const { return id; }

// 定薪员工类
SalaiedEmployee::SalaiedEmployee(string new_name, double new_fixed_salary) : Employee(new_name), fixed_salary(new_fixed_salary) {}
SalaiedEmployee::~SalaiedEmployee() {}

// 计算工资和打印员工信息和工资
double SalaiedEmployee::calculate_wages() const { return fixed_salary; }
void SalaiedEmployee::print()
{
    cout << "ID: " << get_id() << " " << "name: " << get_name() << " " << "wages: " << calculate_wages() << endl;
}

// 设置和获取固定工资
void SalaiedEmployee::set_fixed_salary(double new_fixed_salary) { fixed_salary = new_fixed_salary; }
double SalaiedEmployee::get_fixed_salary() const { return fixed_salary; }

// 提成员工类
CommissionEmployee::CommissionEmployee(std::string new_name, double new_sales_volume, double new_commission_ratio) : Employee(new_name), sales_volume(new_sales_volume), commission_ratio(new_commission_ratio * 0.01) {}
CommissionEmployee::~CommissionEmployee() {}

// 计算工资和打印员工信息和工资
double CommissionEmployee::calculate_wages() const { return sales_volume * commission_ratio; }
void CommissionEmployee::print()
{
    cout << "ID: " << get_id() << " " << "name: " << get_name() << " " << "wages: " << calculate_wages() << endl;
}

// 设置和获取销售额
void CommissionEmployee::set_sales_volume(double new_sales_volume) { sales_volume = new_sales_volume; }
double CommissionEmployee::get_sales_volume() const { return sales_volume; }

// 设置和获取提成比例
void CommissionEmployee::set_commission_ratio(double new_commission_ratio) { commission_ratio = new_commission_ratio * 0.01; }
double CommissionEmployee::get_commission_ratio() const { return commission_ratio; }

// 底薪加提成员工
BasePlusCommissionEmployee::BasePlusCommissionEmployee(std::string new_name, double new_sales_volume, double new_commission_ratio, double base_salary) : CommissionEmployee(new_name, new_sales_volume, new_commission_ratio), base_salary(base_salary) {}
BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {}

// 计算工资和打印员工信息和工资
double BasePlusCommissionEmployee::calculate_wages() const { return base_salary + CommissionEmployee::calculate_wages(); }
void BasePlusCommissionEmployee::print()
{
    cout << "ID: " << get_id() << " " << "name: " << get_name() << " " << "wages: " << calculate_wages() << endl;
}

// 设置和获取底薪
void BasePlusCommissionEmployee::set_base_salary(double new_base_salary) { base_salary = new_base_salary; }
double BasePlusCommissionEmployee::get_base_salary() const { return base_salary; }
