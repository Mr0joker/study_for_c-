#include "color.hpp"

Color::Color(): m_red(0), m_green(0), m_blue(0), m_alpha(0)
{
    m_red = 0;
    m_green = 0;
    m_blue = 0;
    m_alpha = 0;
}

Color::Color(int r, int g, int b): m_red(r), m_green(g), m_blue(b), m_alpha(0)
{
    m_red = r;
    m_green = g;
    m_blue = b;
    m_alpha = 255;
}

Color::Color(int r, int g, int b, int a): m_red(r), m_green(g), m_blue(b), m_alpha(a)
{
    m_red = r;
    m_green = g;
    m_blue = b;
    m_alpha = a;
}

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