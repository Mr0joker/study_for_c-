#include "screen.hpp"
#include <iostream>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

Screen *Screen::get_screen()
{
    static Screen screen;
    return &screen;
}

// Screen *Screen::get_screen(const string lcd_filename)
// {
//     static Screen *screen = new Screen(lcd_filename);
//     return screen;
// }


// 对屏幕初始化
Screen::Screen(): lcd_fd(-1), lcd_width(0), lcd_height(0), lcd_pixel(0), lcd_ptr(NULL)
{
    m_filename = "/dev/fb0";
    lcd_fd = open("/dev/fb0", O_RDWR);
    struct fb_var_screeninfo info;
    ioctl(lcd_fd, FBIOGET_VSCREENINFO, &info);
    lcd_width = info.xres;
    lcd_height = info.yres;
    lcd_pixel = info.bits_per_pixel / 8;

    lcd_ptr = (int *)mmap(0, lcd_width * lcd_height * lcd_pixel, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (NULL == lcd_ptr)
    {
        close(lcd_fd);
        throw "mmap failed";
    }
    clear(0x00FF00);
}

// Screen::Screen(const string lcd_filename)
// {
//     m_filename =  lcd_filename;
//     lcd_fd = open(lcd_filename.c_str(), O_RDWR);
//     struct fb_var_screeninfo info;
//     ioctl(lcd_fd, FBIOGET_VSCREENINFO, &info);
//     lcd_width = info.xres;
//     lcd_height = info.yres;
//     lcd_pixel = info.bits_per_pixel / 8;

//     lcd_ptr = (int *)mmap(0, lcd_width * lcd_height * lcd_pixel, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
//     if (NULL == lcd_ptr)
//     {
//         close(lcd_fd);
//         throw "mmap failed";
//         // perror("mmap failed");
//         // return;
//     }

//     clear(0x00FF00);
// }

// 关闭屏幕
Screen::~Screen()
{
    if (NULL != lcd_ptr)
    {
        munmap(lcd_ptr, lcd_width * lcd_height * lcd_pixel);
        lcd_ptr = NULL;
    }
    if (lcd_fd >= 0)
    {
        close(lcd_fd);
        lcd_fd = -1;
    }
}

// Screen::Screen(const Screen &other): lcd_fd(-1), lcd_width(0), lcd_height(0), lcd_pixel(0), lcd_ptr(NULL)
// {
//     lcd_fd = open(other.m_filename.c_str(), O_RDWR);
//     struct fb_var_screeninfo info;
//     ioctl(lcd_fd, FBIOGET_VSCREENINFO, &info);
//     lcd_width = info.xres;
//     lcd_height = info.yres;
//     lcd_pixel = info.bits_per_pixel / 8;

//     lcd_ptr = (int *)mmap(0, lcd_width * lcd_height * lcd_pixel, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);
//     if (NULL == lcd_ptr)
//     {
//         close(lcd_fd);
//         throw "mmap failed";
//         // perror("mmap failed");
//         // return;
//     }

//     clear(0x00FF00);
// }

int Screen::get_width()
{
    return lcd_width;
}
int Screen::get_height()
{
    return lcd_height;
}
int Screen::get_pixel()
{
    return lcd_pixel;
}

// 画点
void Screen::draw_point(int x, int y, int color)
{
    if (x >= 0 && x < lcd_width && y >= 0 && y < lcd_height)
        *(lcd_ptr + lcd_width * y + x) = color;
}

// 画点重载
void Screen::draw_point(Point pos, Color color)
{
    if (pos.getX() >= 0 && pos.getX() < lcd_width && pos.getY() >= 0 && pos.getY() < lcd_height)
        *(lcd_ptr + lcd_width * pos.getY() + pos.getX()) = color.value();
}

// 清屏幕
void Screen::clear(int color)
{
    for (int i = 0; i < 640; i++)
    {
        for (int j = 0; j < 800; j++)
        {
            Screen::draw_point(j, i, color);
        }
    }
}

