#include <stdio.h>
#include <stdlib.h>

int main()
{
    int man, woman, children;
    printf("Men\tWomen\tChildren\n");
    for (man = 0; man <= 30; man++)
    {
        for (woman = 0; woman <= 30; woman++)
        {
            for (children = 0 ; children <= 30; children++)
            {
                if (children + man + woman == 30 && 3 * man + 2 * woman + children == 50)
                {
                    printf("%2d\t%4d\t%5d\n", man, woman, children);
                }
            }
        }
    }
    return 0;
}
