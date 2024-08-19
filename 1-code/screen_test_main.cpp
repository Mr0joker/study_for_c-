#include <iostream>
#include "screen.hpp"

int main() 
{
    Screen *s1 = Screen::get_screen();
    cout << "h=" << s1->get_height() << endl;
    cout << "w=" << s1->get_width() << endl;
    printf("%p\n", s1);

    Screen *s2 = Screen::get_screen();
    cout << "h=" << s2->get_height() << endl;
    cout << "w=" << s2->get_width() << endl;
    printf("%p\n", s2);
    return 0;
}