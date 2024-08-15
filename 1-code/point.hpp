#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;


/*
    @brief 点类


*/
class Point
{
public:   
    Point(int x=0, int y=0,string color = "black") : m_x(x), m_y(y), m_color(color){}
    //access function
    int getX() const;    //获取坐标
    int getY() const;    //获取坐标
    string Point::getColor() const;    //获取颜色
    void setX(int x);    //设置坐标
    void setY(int y);    //设置坐标
    void setColor(string color);    //设置颜色
    void move(int dx, int dy);     //移动点
    void print() const;    //打印点信息
private:
    int m_x;    //坐标x
    int m_y;    //坐标y
    string m_color; //颜色
};

#endif // POINT_HPP