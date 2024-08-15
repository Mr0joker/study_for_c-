#include "point.hpp"
/*
    @brief point类构造函数
    @param x 点的横坐标
    @param y 点的纵坐标
 */


int Point::getX() const
{
    return m_x;
}

int Point::getY() const
{
    return m_y;
}



void Point::setX(int x)
{
    this->m_x = x;
}

void Point::setY(int y)
{
    this->m_y = y;
}

void Point::setColor(string color)
{
    this->m_color = color;
}

string Point::getColor() const
{
    return m_color;
}

void Point::move(int dx, int dy)
{
    this->m_x += dx;
    this->m_y += dy;
}

void Point::print() const
{
    cout << "Point(" << m_x << "," << m_y << ") color:" << m_color << endl;
}
