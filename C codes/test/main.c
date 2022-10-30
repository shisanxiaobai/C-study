#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUDENT 30
#define COURSE 6
#define MAX_LEN 10

void Select(void);
int Menu(void);
void InputData(long *num, char name[][MAX_LEN], float *score, int n, int m, char * pName[]);
void CalculateEveryCourse(float *score, int n, int m);
void CalculateEveryStudent(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m);
void SortScore(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m, int (*compare)(float a, float b));
int Descending(float a, float b);
int Ascending(float a, float b);
void SwapScore(float *a, float *b);
void SwapId(long *a, long *b);
void SwapName(char a[], char b[]);
void SortName(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m);
void SortId(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m);
void SearchId(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m);
void SearchName(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m);
void Statistic(float *score, int n, int m);
void PrintData(long *num ,char * pName[], float *score, float *sum, float *avg, int n, int m);



int main()
{
    int select;
    int n, m;
    long *num = NULL;
    float *score = NULL, *sum = NULL, *avg = NULL;
    char name[STUDENT][MAX_LEN];
    char * pName[STUDENT];
    printf("Please input student number(n<%d):", STUDENT);
    scanf("%d", &n);
    printf("Please input course number(m<%d):", COURSE);
    scanf("%d", &m);
    num = (long *) calloc(n, sizeof(long));
    score = (float *) calloc(n*m, sizeof(float));
    sum = (float *) calloc(n ,sizeof(float));
    avg = (float *) calloc(n ,sizeof(float));
    if (num == NULL || score == NULL || sum == NULL || avg == NULL)
    {
        printf("No enough memory\n");
        exit(1);
    }
    Select();
    free(num);
    free(score);
    free(sum);
    free(avg);
    return 0;
}

void Select(void)
{
int select;
while (1)
    {
        select = Menu();
        switch (select)
        {
            case 1:
                InputData(num, name, score, n, m, pName);
                break;
            case 2:
                CalculateEveryCourse(score, n, m);
                break;
            case 3:
                CalculateEveryStudent(num, pName, score, sum, avg, n, m);
                break;
            case 4:
                SortScore(num, pName, score, sum, avg, n, m, Descending);
                printf("\nSort in Descending order by sum:\n");
                PrintData(num, pName, score, sum, avg, n, m);
                break;
            case 5:
                SortScore(num, pName, score, sum, avg, n, m, Ascending);
                printf("\nSort in Ascending order by sum:\n");
                PrintData(num, pName, score, sum, avg, n, m);
                break;
            case 6:
                SortId(num, pName, score, sum, avg, n, m);
                printf("\nSort in ascending order by number:\n");
                PrintData(num, pName, score, sum, avg, n, m);
                break;
            case 7:
                SortName(num, pName, score, sum, avg, n, m);
                printf("\nSort in dictionary order by name:\n");
                PrintData(num, pName, score, sum, avg, n, m);
                break;
            case 8:
                SearchId(num, pName, score, sum, avg, n, m);
                break;
            case 9:
                SearchName(num, pName, score, sum, avg, n, m);
                break;
            case 10:
                Statistic(score, n, m);
                break;
            case 11:
                PrintData(num, pName, score, sum, avg, n, m);
                break;
            case 0:
                printf("End of Program!\n");
                exit(0);
            default:
                printf("Input error!\n");
        }
    }
}
int Menu(void)
{
    int select;
    printf("\n1. Input record\n");
    printf("2. Calculate total and average score of every course\n");
    printf("3. Calculate total and average score of every student\n");
    printf("4. Sort in descending order by total score of every student\n");
    printf("5. Sort in ascending order by total score of every student\n");
    printf("6. Sort in ascending order by number\n");
    printf("7. Sort in dictionary order by name\n");
    printf("8. Search by number\n");
    printf("9. Search by name\n");
    printf("10. Statistic analysis for every course\n");
    printf("11. List record\n");
    printf("0. Exit\n");
    printf("Please enter your choice:");
    scanf("%d", &select);
    return select;
}

void InputData(long *num, char name[][MAX_LEN], float *score, int n, int m, char * pName[])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("Please input student's id,name and score of every course:");
        scanf("%ld%*c%s", &num[i], name[i]);
        for (j = 0; j < m; j++)
        {
            scanf("%f", &score[i * m + j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        pName[i] = name[i];
    }
}

void CalculateEveryCourse(float *score, int n, int m)
{
    int i, j;
    float sum[COURSE], average[COURSE];
    for (j = 0; j < m; j++)
    {
        sum[j] = 0;
        for (i = 0; i < n; i++)
        {
         sum[j] += score[i * m + j];
        }
        average[j] = n > 0 ? sum[j] / n : -1;
        printf("Course %d. sum = %.0f average = %.2f\n", j + 1, sum[j], average[j]);
    }
}

void CalculateEveryStudent(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        sum[i] = 0;
        for(j = 0; j < m; j++)
        {
            sum[i] += score[i * m + j];
        }
        avg[i] = m > 0 ? sum[i] / m : -1;
        printf("Student %d. %ld\t%s\tsum = %.0f, average = %.2f\n", i + 1, num[i], pName[i], sum[i], avg[i]);

    }
}

void SortScore(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m, int (*compare)(float a, float b))
{
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if ((*compare)(sum[j], sum[k]))
            {
                k = j;
            }
        }
        if (k != i)
        {
            for (t = 0; t < m; t++)
            {
                SwapScore(&score[i * m + t], &score[k * m + t]);
            }
            SwapScore(&sum[i], &sum[k]);
            SwapScore(&avg[i], &avg[k]);
            SwapId(&num[i], &num[k]);
            SwapName(pName[i], pName[k]);
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

void SwapName(char a[], char b[])
{
    char temp[MAX_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}


void SortId(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m)
{
    int i, j, k, t;
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
            for (t = 0; t < m; t++)
            {
                SwapScore(&score[i * m + t], &score[k * m + t]);
            }
            SwapScore(&sum[i], &sum[k]);
            SwapScore(&avg[i], &avg[k]);
            SwapId(&num[i], &num[k]);
            SwapName(pName[i], pName[k]);
        }
    }
}

void SortName(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m)
{
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(pName[i], pName[j]) > 0)
            {
                 for (t = 0; t < m; t++)
                {
                    SwapScore(&score[i * m + t], &score[j * m + t]);
                }
                SwapName(pName[i], pName[j]);
                SwapId(&num[i], &num[j]);
                SwapScore(&avg[i], &avg[j]);
                SwapScore(&score[i], &score[j]);
            }
        }
    }
}

void SearchId(long *num, char *pName[], float *score, float *sum, float *avg, int n, int m)
{
    long number;
    int i, t;
    printf("Input the number you want to search:");
    scanf("%ld", &number);
    for (i = 0; i < n; i++)
    {
        if (num[i] == number)
        {
            printf("%ld\t%s\t", num[i], pName[i]);
            for (t = 0; t < m; t++)
            {
                printf("%.0f\t", score[i * m + t]);
            }
            printf("%.0f\t%.2f\n", sum[i], avg[i]);
            return;
        }
    }
    printf("\nNot found!\n");
}

void SearchName(long *num, char * pName[], float *score, float *sum, float *avg, int n, int m)
{
    char studentName[MAX_LEN];
    int i, t;
    printf("Input the name you want to search:");
    scanf("%s", studentName);
    for (i = 0; i < n; i++)
    {
        if (strcmp(pName[i], studentName) == 0)
        {
            printf("%ld\t%s\t",num[i], pName[i]);
            for (t = 0; t < m; t++)
            {
                printf("%.0f\t", score[i * m + t]);
            }
            printf("%.0f\t%.2f\n", sum[i], avg[i]);
            return;
        }
    }
    printf("\nNot found!\n");
}

void Statistic(float *score, int n, int m)
{
    int i, j;
    int total;
    int count[6];
    for (j = 0; j < m; j++)
    {
        printf("For course %d:\n", j + 1);
        memset(count, 0, sizeof(count));
        for (i = 0; i < n; i++)
        {
        if (score[i * m + j] >= 0 && score[i * m + j] < 60) count[0]++;
        else if (score[i * m + j] < 70) count[1]++;
        else if (score[i * m + j] < 80) count[2]++;
        else if (score[i * m + j] < 90) count[3]++;
        else if (score[i * m + j] < 100) count[4]++;
        else if (score[i * m + j] == 100) count[5]++;
        }
        for (total = 0, i = 0; i <= 5; i++)
        {
            total += count[i];
        }
        printf("total count number:%d\n", total);

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
}

void PrintData(long *num ,char * pName[], float *score, float *sum, float *avg, int n, int m)
{
    int i, t;
    for (i = 0; i < n; i++)
    {
        printf("%ld\t%s\t", num[i], pName[i]);
        for (t = 0; t < m; t++)
            {
                printf("%.0f\t", score[i * m + t]);
            }
        printf("%.0f\t%.2f\n", sum[i], avg[i]);
    }
}
