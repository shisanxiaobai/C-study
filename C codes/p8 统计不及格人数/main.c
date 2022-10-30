#include <stdio.h>
#include <stdlib.h>

#define N 40

void ReadScore(int score[], int n);
int FailNum(int score[], int n);

int main()
{
    int n, fail;
    int score[N];
    printf("Please input the number of the students(n <= 40):");
    scanf("%d", &n);
    ReadScore(score, n);
    fail = FailNum(score, n);
    printf("Fail students : %d\n", fail);
    return 0;
}


void ReadScore(int score[], int n)
{
    int i;
    printf("Input student's score:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &score[i]);
    }
}


int FailNum(int score[], int n)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (score[j] < 60)
        {
            count ++;
        }
    }
    return count;
}
