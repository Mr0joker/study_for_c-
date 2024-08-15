#include "rect.hpp"

Rect::Rect() : m_x(0), m_y(0), m_w(100), m_h(100), m_color(0xFFFFFF) {}

Rect::Rect(int x, int y, int w, int h, int color) : m_x(x), m_y(y), m_w(w), m_h(h), m_color(color) {}

Rect::Rect(Point point, int w, int h, Color color) : m_x(point.getX()), m_y(point.getY()), m_w(w), m_h(h), m_color(color.value()) {}

Rect::Rect(int w, int h, Point point, Color color) : m_x(point.getX()), m_y(point.getY()), m_w(w), m_h(h), m_color(color.value()) {}

Rect::Rect(Point point, int w, int h) : m_x(point.getX()), m_y(point.getY()), m_w(w), m_h(h), m_color(0xFFFFFF) {}

Rect::Rect(int w, int h, Point point) : m_x(point.getX()), m_y(point.getY()), m_w(w), m_h(h), m_color(0xFFFFFF) {}

Rect::Rect(int w, int h) : m_x(0), m_y(0), m_w(w), m_h(h), m_color(0xFFFFFF) {}

void Rect::set_rect(int x, int y, int w, int h, int color)
{
    m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    m_color = color;
}

void Rect::draw(Screen &screen)
{
    for (int i = m_y; i < m_y + m_h; i++)
    {
        for (int j = m_x; j < m_x + m_w; j++)
        {
            screen.draw_point(j, i, m_color);
        }
    }
}