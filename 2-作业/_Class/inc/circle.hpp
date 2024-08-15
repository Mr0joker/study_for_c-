#ifndef CIRCLE_HPP
#define RECT_HPP
#include "screen.hpp"
#include "point.hpp"
#include "color.hpp"

class Circle
{
public:
    Circle();
    Circle(int x, int y,int r, int color);
    Circle(Point point,int r, Color color);
    Circle(int r, Point point, Color color);
    Circle(Point point, int r);
    Circle(int r, Point point);
    Circle(int r);

    void set_circle(int x = 0, int y = 0, int r = 100,int color = 0x00FFFF);
    void draw(Screen &screen);
    // void draw_hollow(Screen &screen);
    // void drawCirclePoints(Screen &screen, int cx, int cy, int x, int y);
    // void draw_filled(Screen &screen);
    // void drawFilledCirclePoints(Screen &screen, int cx, int cy, int x, int y);
    ~Circle(){}

private:
    int m_x;
    int m_y;
    int m_r;
    int m_color;
};

#endif // RECT_HPP