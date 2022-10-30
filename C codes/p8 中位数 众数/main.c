#include <stdio.h>
#include <stdlib.h>
#define M 40
#define N 11

int Mean(int feedback[], int n);
int Median(int feedback[], int n);
int Mode(int feedback[], int n);
void DateSort(int feedback[], int n);

int main()
{
    int i;
    int feedback[M];
    printf("Input the feedbacks of 40 students:");
    for (i = 0; i < M; i++)
    {
        scanf("%d", &feedback[i]);
    }
    printf("Mean value = %d", Mean(feedback, M));
    printf("Median value = %d", Median(feedback, M));
    printf("Mode value = %d", Mode(feedback, M));
    return 0;
}

int Mean(int feedback[], int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += feedback[i];
    }
    return n > 0 ? sum / n : -1;
}

int Median(int feedback[], int n)
{
    DateSort(feedback, n);
    if (n % 2 == 0)
    {
        return (feedback[n / 2] + feedback[n / 2 - 1]) / 2;
    }
    else
    {
        return feedback[n / 2];
    }
}

int Mode(int feedback[], int n )
{
    int i, modevalue = 0, grade, max = 0;
    int count[N] = {0};
    for (i = 0; i < n; i++)
    {
        count[feedback[i]]++;
    }
    for (grade = 1; grade < N - 1; grade++)
    {
        if (count[grade] > max)
        {
            max = count[grade];
            modevalue = grade;
        }
    }
    return modevalue;
}

void DateSort(int feedback[], int n)
{
    int i, j, k;
    int term;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (feedback[j] > feedback[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            term = feedback[i];
            feedback[i] = feedback[k];
            feedback[k] = term;
        }
    }
}
