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

protected:
    Screen();
    // Screen(const string lcd_filename);
    Screen(const Screen &other)=delete;
    Screen &operator=(const Screen &other)=delete;

public:

    // static Screen *get_screen(const string lcd_filename);
    static Screen *get_screen();

    int get_width();
    int get_height();
    int get_pixel();
    void draw_point(int x, int y, int color);
    void draw_point(Point pos, Color color);
    void clear(int color);
    ~Screen();
};

#endif // SCREEN_HPP