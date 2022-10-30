#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int face, roll;
    int frequency[7] = {0};
    srand(time(NULL));
    for (roll = 1; roll <= 6000; roll++)
    {
        face = rand() % 6 + 1;
        frequency[face]++;
    }
    printf("%4s%27s\n", "face", "frequency");
    for (face = 1; face <= 6; face++)
    {
        printf("%4d%17d\n", face, frequency[face]);
    }
    return 0;
}
