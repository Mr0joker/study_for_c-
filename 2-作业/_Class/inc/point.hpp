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
    Point();
    Point(int x, int y);

    // access function
    int getX() const;          // 获取坐标
    int getY() const;          // 获取坐标
    void setX(int x);          // 设置坐标
    void setY(int y);          // 设置坐标
    void move(int dx, int dy); // 移动点
    void print() const;        // 打印点信息

    ~Point(){}
private:
    int m_x; // 坐标x
    int m_y; // 坐标y
};

#endif // POINT_HPP