#include <stdio.h>
#include <stdlib.h>
#define STUDENT 30

int Menu(void);
void InputData(long num[], float score[], int n);
void Calculate(float score[], int n);
void SortScore(long num[], float score[], int n, int (*compare)(float a, float b));
int Descending(float a, float b);
int Ascending(float a, float b);
void SwapScore(float *a, float *b);
void SwapId(long *a, long *b);
void SortId(long num[], float score[], int n);
void SearchId(long num[], float score[], int n);
void Statistic(float score[], int n);
void PrintData(long num[], float score[], int n);



int main()
{
    int select;
    int n;
    long num[STUDENT];
    float score[STUDENT];
    printf("Please input student number(n<%d):", STUDENT);
    scanf("%d", &n);
    while (1)
    {
        select = Menu();
        switch (select)
        {
            case 1:
                InputData(num, score, n);
                break;
            case 2:
                Calculate(score, n);
                break;
            case 3:
                SortScore(num, score, n, Descending);
                printf("\nSort in Descending order by score:\n");
                PrintData(num, score, n);
                break;
            case 4:
                SortScore(num, score, n, Ascending);
                printf("\nSort in Ascending order by score:\n");
                PrintData(num, score, n);
                break;
            case 5:
                SortId(num, score, n);
                printf("\nSort in ascending order by number:\n");
                PrintData(num, score, n);
                break;
            case 6:
                SearchId(num, score, n);
                break;
            case 7:
                Statistic(score, n);
                break;
            case 8:
                PrintData(num, score, n);
                break;
            case 0:
                printf("End of Program!\n");
                exit(0);
            default:
                printf("Input error!\n");
        }
    }
    return 0;
}

int Menu(void)
{
    int select;
    printf("\n1. Input record\n");
    printf("2. Calculate total and average score of course\n");
    printf("3. Sore in descending order by score\n");
    printf("4. Sort in ascending order by score\n");
    printf("5. Sort in ascending order by number\n");
    printf("6. Search by number\n");
    printf("7. Statistic analysis\n");
    printf("8. List record\n");
    printf("0. Exit\n");
    printf("Please enter your choice:");
    scanf("%d", &select);
    return select;
}

void InputData(long num[], float score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Please input student's id and score:");
        scanf("%ld%*c%f", &num[i], &score[i]);
    }
}

void Calculate(float score[], int n)
{
    int i;
    float sum = 0, average;
    for (i = 0; i < n; i++)
    {
        sum += score[i];
    }
    average = n > 0 ? sum / n : 0;
    printf("sum = %.0f average = %.2f\n", sum, average);
}

void SortScore(long num[], float score[], int n, int (*compare)(float a, float b))
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(score[j], score[k]))
            {
                k = j;
            }
        }
        if (k != i)
        {
            SwapScore(&score[i], &score[k]);
            SwapId(&num[i], &num[k]);
        }
    }
}

int Descending(float a, float b)
{
    return a > b;
}

int Ascending(float a, float b)
{
    return a < b;
}

void SwapScore(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SwapId(long *a, long *b)
{
    long temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void SortId(long num[], float score[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (num[j] < num[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            SwapScore(&score[i], &score[k]);
            SwapId(&num[i], &num[k]);
        }
    }
}

void SearchId(long num[], float score[], int n)
{
    long number;
    int i;
    printf("Input the number you want to search:");
    scanf("%ld", &number);
    for (i = 0; i < n; i++)
    {
        if (num[i] == number)
        {
            printf("%ld\t%.0f\n", num[i], score[i]);
            return;
        }
    }
    printf("Not found!\n");
}

void Statistic(float score[], int n)
{
    int i;
    int count[6] = {0};
    for (i = 0; i < n; i++)
    {
        if (score[i] >= 0 && score[i] < 60) count[0]++;
        else if (score[i] < 70) count[1]++;
        else if (score[i] < 80) count[2]++;
        else if (score[i] < 90) count[3]++;
        else if (score[i] < 100) count[4]++;
        else if (score[i] == 100) count[5]++;
    }
    for (i = 0; i <= 5; i++)
    {
        if (i == 0)
        {
            printf("<60\t%d %.2f%%\n", count[i], (float)count[i] / n * 100);
        }
        else if (i == 5)
        {
            printf("%d\t%d %.2f%%\n", (i+5) * 10, count[i], (float)count[i] / n * 100);
        }
        else
        {
            printf("%d%C%d\t%d %.2f%%\n", (i+5)*10, '~', (i+5)*10+9, count[i], (float)count[i]/n*100);
        }
    }
}

void PrintData(long num[],float score[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%ld\t %.0f\n", num[i], score[i]);
    }
}
