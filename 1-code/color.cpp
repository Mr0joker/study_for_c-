#include "color.hpp"

int Color::value() const
{
    return (m_alpha << 24 | m_red << 16 | m_green << 8 | m_blue);
}

void Color::setColor(int r, int g, int b, int a)
{
    m_red = r;
    m_green = g;
    m_blue = b;
    m_alpha = a;
}