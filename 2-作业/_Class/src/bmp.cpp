#include "bmp.hpp"
#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>




using namespace std;
unsigned char data[4];
Bmp::Bmp(const Bmp &bmp) : pathname(bmp.get_pathname()), picture_id(bmp.get_picture_id()), offset(bmp.get_offset()), width(bmp.get_width()), height(bmp.get_height()), depth(bmp.get_depth()), fills(bmp.get_fills()), real_bytes(bmp.get_real_bytes()),color_array(bmp.get_color_array()),color_point(bmp.get_color_point()) {}// 拷贝构造函数

Bmp::Bmp(const char *pathname) : pathname(pathname), picture_id(-1), offset(0), width(0), height(0), depth(0), fills(0), real_bytes(0)
{
    // 判断打开文件是否成功
    picture_id = open(pathname, O_RDONLY);
    if (picture_id == -1)
    {
        //cerr << "open file error" << endl;
        // exit(1);
        throw std::runtime_error("open file error");
    }
    // 判断类型是否为bmp
    read(picture_id, data, 2);
    if (data[0] != 'B' || data[1] != 'M')
    {
        close(picture_id);
        throw std::runtime_error("not a bmp file");
        // cerr << "not a bmp file" << endl;
        // exit(1);
    }

    // 读取文件头信息
    // 读取像素数组偏移量
    lseek(picture_id, 0x0a, SEEK_SET); // 偏移到像素数组偏移量数据的起始位置
    read(picture_id, data, 4);
    offset = *(int *)data; // 读取像素数组偏移量数据
     
    // 读取图像宽度
    lseek(picture_id, 0x12, SEEK_SET); // 偏移到图像宽度数据的起始位置
    read(picture_id, data, 4);
    width = *(int *)data; // 读取图像宽度数据

    // 读取图像高度
    lseek(picture_id, 0x16, SEEK_SET); // 偏移到图像高度数据的起始位置
    read(picture_id, data, 4);
    height = *(int *)data; // 读取图像高度数据

    // 读取图像颜色数
    lseek(picture_id, 0x1c, SEEK_SET); // 偏移到图像颜色数数据的起始位置
    read(picture_id, data, 2);
    depth = *(short *)data; // 读取图像颜色数数据
    
    // 计算图像字节数
    if (width * (depth / 8) % 4)
    {
        fills = 4 - (width * (depth / 8) % 4);
    }

    real_bytes = width * (depth / 8) + fills; // 计算图像实际字节数
    // 搞一个动态数据用来保存像素数组的数据
    color_array = new unsigned char[real_bytes * abs(height)];
    color_point = color_array;

    lseek(picture_id, offset, SEEK_SET);
    read(picture_id, color_array, real_bytes * abs(height));

    
}


void Bmp::draw(Screen &screen, int posx = 0, int posy = 0)
{
    
    // 循环变量图片的像素点
    for (int h = 0; h < abs(height); h++)
    {
        for (int w = 0; w < width; w++)
        {
            unsigned char a, r, g, b;
            b = *color_point++;
            g = *color_point++;
            r = *color_point++;
            a = (depth == 24) ? 0 : *color_point++;

            int color = a << 24 | r << 16 | g << 8 | b;
            // 将颜色画到屏幕上
            // int new_w = (int)(w*4) + posx;
            // int new_h = (int)(((height > 0) ? height - 1 - h : abs(height))*4) + posy;

            screen.draw_point(w + posx, ((height > 0) ? height - 1 - h : abs(height)) + posy, color);
        }
        // 跳过填充字节
        color_point += fills;
    }
    
}

void Bmp::draw(Screen &screen)
{
    // 循环变量图片的像素点
    for (int h = 0; h < abs(height); h++)
    {
        for (int w = 0; w < width; w++)
        {
            unsigned char a, r, g, b;
            b = *color_point++;
            g = *color_point++;
            r = *color_point++;
            a = (depth == 24) ? 0 : *color_point++;

            int color = a << 24 | r << 16 | g << 8 | b;
            // 将颜色画到屏幕上
            // int new_w = (int)(w*4) + posx;
            // int new_h = (int)(((height > 0) ? height - 1 - h : abs(height))*4) + posy;

            screen.draw_point(w,((height > 0) ? height - 1 - h : abs(height)), color);
        }
        // 跳过填充字节
        color_point += fills;
    }
   
}



Bmp::~Bmp()
{
    delete[] color_array;
    close(picture_id);
}

const char *Bmp::get_pathname() const
{
    return pathname;
}

int Bmp::get_picture_id() const
{
    return picture_id;
}

int Bmp::get_offset() const
{
    return offset;
}

int Bmp::get_width() const
{
    return width;
}

int Bmp::get_height() const
{
    return height;
}

short Bmp::get_depth() const
{
    return depth;
}

int Bmp::get_fills() const
{
    return fills;
}

int Bmp::get_real_bytes() const
{
    return real_bytes;
}


unsigned char * Bmp::get_color_point() const
{
    return color_point;
}

unsigned char *Bmp::get_color_array() const
{
    return color_array;
}
