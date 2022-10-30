#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ATHLETE 40
#define JUDGE 20

void CountAthleteScore (int sh[], float sf[], int n, float f[], int m);
void Sort(int h[], float f[], int n);
void Print(int h[], float f[], int n);
void CountJudgeScore (int ph[], float pf[], int m, float sf[], float f[], int n);

int main()
{
    int j, m, n;
    int sh[ATHLETE];
    int ph[JUDGE];
    float sf[ATHLETE];
    float pf[JUDGE];
    float f[ATHLETE][JUDGE];

    printf("How many Athlete?");
    scanf("%d", &n);
    printf("How many Judge?");
    scanf("%d", &m);

    for (j = 1; j <= m; j++)
    {
        ph[j] = j;
    }

    printf("Score of Athlete:\n");
    CountAthleteScore(sh, sf, n, *f, m);
    CountJudgeScore(ph, pf, m, sf, *f, n);
    printf("Order of Athlete:\n");
    Sort(sh, sf, n);
    Print(sh, sf, n);
    printf("Order of Judge:\n");
    Sort(ph, pf, m);
    Print(ph, pf, m);
    printf("Over! Thank you!\n");
    return 0;
}

void CountAthleteScore (int sh[], float sf[], int n, float f[], int m)
{
    int i, j;
    float max, min;
    for (i = 1; i <= n; i++)
    {
        printf("\nAthlete %d is playing\n", i);
        printf("Please enter his number code:");
        scanf("%d", &sh[i]);
        sf[i] = 0;
        max = 0;
        min = 100;
        for (j = 1; j <= m; j++)
        {
            printf("Please %d gives score:", j);
            scanf("%f", &f[i * m + j]);
            sf[i] = sf[i] + f[i * m + j];
            if (f[i * m + j] > max)
            {
                max = f[i * m + j];
            }
            if (f[i * m + j] < min)
            {
                min = f[i * m + j];
            }
        }
        printf("Delete a maximum score: %.1f\n", max);
        printf("Delete a minimum score: %.1f\n", min);
        sf[i] = (sf[i] - max - min) / (m - 2);
        printf("The final score of Athlete %d is %.3f\n", sh[i], sf[i]);
    }
}

void Sort(int h[], float f[], int n)
{
    int i, j, k, temp1;
    float temp2;
    for (i = 1; i <= n - 1; i++)
    {
        k = i;
        for (j =i + 1; j <= n; j++)
        {
            if (f[j] > f[i])
            {
                k = j;
            }
        }
        if (k != i)
        {
            temp2 = f[i];
            f[i] = f[k];
            f[k] = temp2;
            temp1 = h[i];
            h[i] = h[k];
            h[k] = temp1;
        }
    }
}

void Print(int h[], float f[], int n)
{
    int i;
    printf("Order\t Final Score\t Number Code\n");
    for (i = 1; i <= n; i++)
    {
        printf("%5d\t %11.3f\t %6d\n", i, f[i], h[i]);
    }
}

void CountJudgeScore (int ph[], float pf[], int m, float sf[], float f[], int n)
{
    int i, j;
    for (j = 1; j <= m; j++)
    {
        pf[j] = 0;
        for (i = 1; i <= n; i++)
        {
            pf[j] = pf[j] + (f[i*m+j] - sf[i]) * (f[i*m+j] - sf[i]);
        }
        pf[j] = 10 - sqrt(pf[j] / n);
    }
}
