#include <stdio.h>
#include <stdlib.h>
#define M 40
#define N 11

int main()
{
    int feedback[M], count[N] = {0};
    int grade, i;
    printf("Input the feedbacks of 40 students:");
    for (i = 0; i < M; i++)
    {
        scanf("%d", &feedback[i]);
    }
    for (i = 0; i < M; i++)
    {
        count[feedback[i]]++;
    }
    printf("Grade\t count\t Histogram\n");
    for (grade = 1; grade < N - 1; grade++)
    {
        printf("%5d\t %5d\t", grade, count[grade]);
        for (i = 0; i < count[grade]; i++)
        {
            printf(" %c",'*');
        }
        printf("\n");
    }
    return 0;
}
