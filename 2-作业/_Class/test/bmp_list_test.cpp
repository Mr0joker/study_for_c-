#include "bmp.hpp"
#include "dir.hpp"
#include <string>
#include <iostream>
#include <unistd.h>

using namespace std;
int main()
{
    Screen s;
    Dir dir("./BMP");
    ForwardList bmp_list = dir.get_bmp_list();

    cout << bmp_list.size() << endl;
    for (int i = 0; i < bmp_list.size(); i++)
    {
        sleep(3);
        string bmp_pathname = bmp_list.get_data(i);
        Bmp bmp(reinterpret_cast<const char *>(bmp_pathname.c_str()));
        bmp.draw(s);
    }
    return 0;
}