#include <stdio.h>
#include <stdlib.h>

int main()
{
    int chicken, rabbit;
    printf("chicken\trabbit\n");
    for (chicken = 1; chicken <= 98; chicken++)
    {
        rabbit = 98 - chicken;
        if (386 == 2 * chicken + 4 * rabbit)
        {
            printf("%4d\t%4d\n", chicken,rabbit);
        }
    }
    printf("Hello world!\n");
    return 0;
}
