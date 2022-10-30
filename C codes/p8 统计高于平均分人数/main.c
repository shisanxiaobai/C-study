#include <stdio.h>
#include <stdlib.h>
#define N 40

int ReadScore(int score[]);
int Average(int score[], int n);
int GetAboveAvg(int score[], int n);

int main()
{
    int score[N], n, m;
    n = ReadScore(score);
    printf("Total students are %d\n", n);
    m = GetAboveAvg(score, n);
    if (m != -1)
    printf("Students of above average is %d\n", m);
    return 0;
}

int ReadScore(int score[])
{
    int i = -1;
    do
    {
        i++;
        printf("Please input student's score:");
        scanf("%d", &score[i]);
    }while (score[i] >= 0);
    return i;
}

int Average(int score[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += score[i];
    }
    return n > 0 ? sum / n : -1;
}

int GetAboveAvg(int score[], int n)
{
    int i, count = 0;
    if (Average(score, n) == -1) return -1;
    printf("Average score is %d\n", Average(score, n));
    for (i = 0 ; i < n; i++)
    {
        if (score[i] > Average(score, n))
        {
            count++;
        }
    }
    return count;
}
