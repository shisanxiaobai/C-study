#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cock, hen, chicken;
    printf("cock\t hen\t chicken\n");
    for (cock = 0; cock <= 20; cock++)
    {
        for(hen = 0; hen <= 33; hen++)
        {
            chicken = 100 - cock - hen;
            if (100 == 5 * cock + 3 * hen + chicken / 3.0)
            {
                printf("%2d\t %2d\t %4d\n", cock, hen, chicken);
            }
        }
    }
    return 0;
}
