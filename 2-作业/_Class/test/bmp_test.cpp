#include <iostream>
#include "screen.hpp"
#include "bmp.hpp"
using namespace std;


int main(int argc, char* argv[]) {
    if(argc!= 2) {
        cout << "Usage: " << argv[0] << " filename" << endl;
        return 1;
    }
    Screen screen;

    Bmp bmp(argv[1]);
    Bmp bmp2(bmp);
    
    bmp2.draw(screen);

}

    