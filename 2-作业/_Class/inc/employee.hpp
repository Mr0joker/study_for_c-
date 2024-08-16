#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
// 员工基类
class Employee
{
protected:
    std::string name;       // 姓名 字符串
    int id;                 // 卡号 字符串/整型
    static int employee_id; // 定义一个静态成员变量，对加入的员工进行编号
public:
    Employee(std::string new_name);
    virtual ~Employee();

    virtual double calculate_wages() const = 0; // 计算工资 纯虚函数
    virtual void print();                 // 打印 id+name   虚函数

    void set_name(std::string new_name); // 设置姓名
    std::string get_name() const;        // 读取姓名
    void set_id(int new_id);             // 设置卡号
    int get_id() const;                  // 读取卡号
};

// 定薪员工
class SalaiedEmployee : public Employee
{
private:
    double fixed_salary; // 固定工资  浮点数
public:
    //参数：姓名，固定工资
    SalaiedEmployee(std::string new_name, double new_fixed_salary);
    ~SalaiedEmployee();

    double calculate_wages()const override; // 计算工资 必须覆盖
    void print() override;             // 打印     覆盖

    void set_fixed_salary(double new_fixed_salary); // 设置固定工资
    double get_fixed_salary() const;                // 读取固定工资
};

// 提成员工
class CommissionEmployee : public Employee
{
private:
    double sales_volume;     // 销售额度,卖了多少产品*产品售价
    double commission_ratio; // 提成比例
public:
    //参数：姓名，销售额度，提成比例%已除100
    CommissionEmployee(std::string new_name, double new_sales_volume, double new_commission_ratio);
    ~CommissionEmployee();

    double calculate_wages()const override; // 计算工资
    void print() override;             // 打印

    void set_sales_volume(double new_sales_volume);         // 修改销售额度
    double get_sales_volume() const;                        // 读取销售额度
    void set_commission_ratio(double new_commission_ratio); // 修改提成比例%
    double get_commission_ratio() const;                    // 读取提成比例
};

// 底薪加提成员工
class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double base_salary; // 底薪
public:
    //参数：姓名，销售额度，提成比例，底薪
    BasePlusCommissionEmployee(std::string new_name, double new_sales_volume, double new_commission_ratio, double base_salary);
    ~BasePlusCommissionEmployee();

    double calculate_wages()const override; // 计算工资
    void print() override;             // 打印

    void set_base_salary(double new_base_salary); // 修改底薪
    double get_base_salary() const;               // 读取销售额度
};

#endif /*employee.hpp*/