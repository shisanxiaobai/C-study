#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 1, find = 0;
    while (!find)
    {
        if(x % 2 == 1 && x % 3 == 2 && x % 5 == 4 && x % 6 == 5 && x % 7 == 0)
        {
           printf("x = %d\n", x);
           find = 1;
        }
        x++;
    }

    return 0;
}
