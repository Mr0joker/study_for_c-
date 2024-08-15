#include "circle.hpp"



Circle::Circle() : m_x(400), m_y(240), m_r(100), m_color(0xFFFFFF) {}

Circle::Circle(int x, int y, int r, int color): m_x(x), m_y(y), m_r(r), m_color(color) {}

Circle::Circle(Point point, int r, Color color): m_x(point.getX()), m_y(point.getY()), m_r(r), m_color(color.value()) {}

Circle::Circle(int r, Point point, Color color): m_x(point.getX()), m_y(point.getY()), m_r(r), m_color(color.value()) {}

Circle::Circle(Point point, int r): m_x(point.getX()), m_y(point.getY()), m_r(r), m_color(0xFFFFFF) {}

Circle::Circle(int r, Point point): m_x(point.getX()), m_y(point.getY()), m_r(r), m_color(0xFFFFFF) {}

Circle::Circle(int r): m_x(400), m_y(240), m_r(r), m_color(0xFFFFFF) {}


void Circle::set_circle(int x, int y, int r,int color)
{
    m_x = x;
    m_y = y;
    m_r = r;
    m_color = color;
}


//粗糙的画圆算法，效率低下
void Circle::draw(Screen &screen)
{
    for(int i = m_x - m_r; i <= m_x + m_r; i++)
    {
        for(int j = m_y - m_r; j <= m_y + m_r; j++)
        {
            if(i >= 0 && i < screen.get_width() && j >= 0 && j < screen.get_height() 
            && (i - m_x)*(i - m_x) + (j - m_y)*(j - m_y) <= m_r*m_r)
            {
                screen.draw_point(i, j, m_color);
            }
        }
    }
}













// //Bresenham算法画圆
// void Circle::draw_hollow(Screen &screen)
// {
//     int x = 0, y = m_r;
//     int d = 3 - 2 * m_r;
//     drawCirclePoints(screen, m_x, m_y, x, y);
//     while (y >= x)
//     {
//         x++;
//         if (d > 0)
//         {
//             y--;
//             d = d + 4 * (x - y) + 10;
//         }
//         else
//         {
//             d = d + 4 * x + 6;
//         }
//         drawCirclePoints(screen, m_x, m_y, x, y);
//     }
// }

// void Circle::drawCirclePoints(Screen &screen, int cx, int cy, int x, int y)//画圆的各个点cx,cy为圆心,x,y为画圆的半径
// {
//     if (cx + x >= 0 && cx + x < screen.get_width() && cy + y >= 0 && cy + y < screen.get_height())
//         screen.draw_point(cx + x, cy + y, m_color);
//     if (cx - x >= 0 && cx - x < screen.get_width() && cy + y >= 0 && cy + y < screen.get_height())
//         screen.draw_point(cx - x, cy + y, m_color);
//     if (cx + x >= 0 && cx + x < screen.get_width() && cy - y >= 0 && cy - y < screen.get_height())
//         screen.draw_point(cx + x, cy - y, m_color);
//     if (cx - x >= 0 && cx - x < screen.get_width() && cy - y >= 0 && cy - y < screen.get_height())
//         screen.draw_point(cx - x, cy - y, m_color);
//     if (cx + y >= 0 && cx + y < screen.get_width() && cy + x >= 0 && cy + x < screen.get_height())
//         screen.draw_point(cx + y, cy + x, m_color);
//     if (cx - y >= 0 && cx - y < screen.get_width() && cy + x >= 0 && cy + x < screen.get_height())
//         screen.draw_point(cx - y, cy + x, m_color);
//     if (cx + y >= 0 && cx + y < screen.get_width() && cy - x >= 0 && cy - x < screen.get_height())
//         screen.draw_point(cx + y, cy - x, m_color);
//     if (cx - y >= 0 && cx - y < screen.get_width() && cy - x >= 0 && cy - x < screen.get_height())
//         screen.draw_point(cx - y, cy - x, m_color);
// }





// //Bresenham算法画填充圆
// void Circle::draw_filled(Screen &screen)
// {
//     int x = 0, y = m_r;
//     int d = 3 - 2 * m_r;
//     drawFilledCirclePoints(screen, m_x, m_y, x, y);
//     while (y >= x)
//     {
//         x++;
//         if (d > 0)
//         {
//             y--;
//             d = d + 4 * (x - y) + 10;
//         }
//         else
//         {
//             d = d + 4 * x + 6;
//         }
//         drawFilledCirclePoints(screen, m_x, m_y, x, y);
//     }
// }

// void Circle::drawFilledCirclePoints(Screen &screen, int cx, int cy, int x, int y)
// {
//     // 绘制水平线填充圆内部
//     for (int i = -x; i <= x; i++)
//     {
//         if (cx + i >= 0 && cx + i < screen.get_width() && cy + y >= 0 && cy + y < screen.get_height())
//             screen.draw_point(cx + i, cy + y, m_color);
//         if (cx + i >= 0 && cx + i < screen.get_width() && cy - y >= 0 && cy - y < screen.get_height())
//             screen.draw_point(cx + i, cy - y, m_color);
//     }
//     for (int i = -y; i <= y; i++)
//     {
//         if (cx + i >= 0 && cx + i < screen.get_width() && cy + x >= 0 && cy + x < screen.get_height())
//             screen.draw_point(cx + i, cy + x, m_color);
//         if (cx + i >= 0 && cx + i < screen.get_width() && cy - x >= 0 && cy - x < screen.get_height())
//             screen.draw_point(cx + i, cy - x, m_color);
//     }
// }
