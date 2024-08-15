#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "color.hpp"
#include "point.hpp"

class Screen
{
private:
    int lcd_fd;
    int *lcd_ptr = NULL;
    int lcd_width;
    int lcd_height;
    int lcd_pixel;
    string m_filename;

public:
    Screen();
    Screen(const string lcd_filename);
    Screen(const Screen &other);
    int get_width();
    int get_height();
    int get_pixel();
    void draw_point(int x, int y, int color);
    void draw_point(Point pos, Color color);
    void clear(int color);
    ~Screen();
};

#endif // SCREEN_HPP