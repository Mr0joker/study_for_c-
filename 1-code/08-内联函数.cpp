#include <iostream>
using namespace std;

inline int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 10, y = 20;
    int z = add(x, y);
    cout << "The sum of " << x << " and " << y << " is " << z << endl;
    return 0;
}