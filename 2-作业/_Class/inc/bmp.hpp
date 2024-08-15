#ifndef BMP_HPP
#define BMP_HPP

#include "screen.hpp"

class Bmp
{
private:
    const char *pathname;
    int picture_id;
    int offset;
    int width;
    int height;
    short depth;
    int fills;
    int real_bytes;
    unsigned char *color_array;
    unsigned char *color_point;

public:
    Bmp(const Bmp &bmp);
    Bmp(const char *pathname);

    const char *get_pathname() const;
    int get_picture_id() const;
    int get_offset() const;
    int get_width() const;
    int get_height() const;
    short get_depth() const;
    int get_fills() const;
    int get_real_bytes() const;
    unsigned char *get_color_point() const;
    unsigned char *get_color_array() const;

    void draw(Screen &screen, int x, int y);
    void draw(Screen &screen);
    ~Bmp();
};

#endif //BMP_HPP