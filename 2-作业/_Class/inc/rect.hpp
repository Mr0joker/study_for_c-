#ifndef RECT_HPP
#define RECT_HPP
#include "screen.hpp"
#include "point.hpp"
#include "color.hpp"

class Rect
{
public:
    Rect();
    Rect(int x, int y, int w, int h, int color);
    Rect(Point point, int w, int h, Color color);
    Rect(int w, int h, Point point, Color color);
    Rect(Point point, int w, int h);
    Rect(int w, int h, Point point);
    Rect(int w, int h);

    void set_rect(int x = 0, int y = 0, int w = 800, int h = 640, int color = 0x00FFFF);
    void draw(Screen &screen);

    ~Rect(){}
private:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    int m_color;
};

#endif // RECT_HPP