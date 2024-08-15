#include "point.hpp"
/*
    @brief point类构造函数
    @param x 点的横坐标
    @param y 点的纵坐标
 */

Point::Point():m_x(0), m_y(0) {}

Point::Point(int x, int y) : m_x(x), m_y(y) {}


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
    m_x = x;
}

void Point::setY(int y)
{
    m_y = y;
}

void Point::move(int dx, int dy)
{
    m_x += dx;
    m_y += dy;
}

void Point::print() const
{
    cout << "Point(" << m_x << "," << m_y << ") " << endl;
}
