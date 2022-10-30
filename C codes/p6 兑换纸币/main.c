#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ten, five, one, count = 0;
    printf("Ten yuan\t Five yuan\t One yuan\n");
    for (ten = 0; ten <= 9; ten++)//每种纸币都要有。
    {
        for (five = 0; five <= 19; five++)
        {
            one = 50 - ten - five;
            if (100 == 10 * ten + 5 * five + one)
            {
                count++;
                printf("%4d\t\t %4d\t\t %5d\n", ten, five, one);
            }
        }
    }
    printf("count = %d", count);
    return 0;
}
