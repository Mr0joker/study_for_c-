#include <stdio.h>
#include "test.h"


int main()
{
    int x = 10, y = 20;
    int z = add(x, y);
    printf("The sum of %d and %d is %d\n", x, y, z);
    return 0;
}

