#include <stdio.h>
#include <stdlib.h>
#define N 40

int ReadScore(int score[], long num[]);
int FindMax(int score[], int n);

int main()
{
    int n, pos;
    int score[N];
    long num[N];

    n = ReadScore(score, num);
    printf("The number of students is %d\n", n);
    pos = FindMax(score, n);
    printf("Max score:%d, student ID:%ld\n", score[pos], num[pos]);
    return 0;
}


int ReadScore(int score[], long num[])
{
    int i = -1;
    do
    {
        i++;
        printf("Please input student Id and score:");
        scanf("%ld%*c%d", &num[i], &score[i]);
    }while(score[i] >= 0 && num[i] >= 0);
    return i;
}


int FindMax(int score[], int n)
{
    int i, pos = 0;
    int max = score[0];
    for (i = 0; i < n; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
            pos = i;
        }
    }
    return pos;
}
