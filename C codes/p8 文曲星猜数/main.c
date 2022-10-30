#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//ÎÄÇúÐÇ²ÂÊýÓÎÏ·
void MakeDigit(int a[]);
int InputGuess(int b[]);
int RightPosition(int a[], int b[]);
int RightDigit(int a[], int b[]);

int main()
{
    int a[10];
    int b[4];
    int count;
    int rightdigit;
    int rightposition;
    int n;
    srand(time(NULL));
    MakeDigit(a);
    printf("How many times do you want to guess:");
    scanf("%d", &n);
    count = 0;
    do
    {
        printf("No.%d of %d times\n", count + 1, n);
        printf("Please Input a number:");
        if (InputGuess(b))
        {
            count++;
            rightposition = RightPosition(a, b);
            rightdigit = RightDigit(a, b);
            rightdigit = rightdigit - rightposition;
            printf("%dA%dB\n", rightposition, rightdigit);
        }
    }while (count < n && rightposition != 4);
    if (rightposition == 4)
    {
        printf("Congratulations!, you got it at NO.%d\n", count);
    }
    else
    {
        printf("Sorry, you haven't guess the right number!\n");
    }
    printf("Correct Number :%d%d%d%d\n", a[0], a[1], a[2], a[3]);
    return 0;
}

void MakeDigit(int a[])
{
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        a[i] = i;
    }
    for (i = 0; i < 10; i++)
    {
        j = rand() % 10;
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int InputGuess(int b[])
{
    int i, ret = 1;
    for (i = 0; i < 4; i++)
    {
        ret = scanf("%1d", &b[i]);
        if (ret != 1)
        {
            printf("Input date type error!\n");
            while (getchar() != '\n');
            return 0;
        }
    }
        if (b[0] == b[1] || b[0] == b[2] || b[0] == b[3] || b[1] == b[2] || b[1] == b[3] || b[2] == b[3])
        {
            printf("The digits must be different from each other\n");
            return 0;
        }
        else
        {
            return 1;
        }
}

int RightPosition(int a[], int b[])
{
    int i, count = 0;
    for ( i = 0; i < 4; i++)
    {
        if (a[i] == b[i])
        {
            count++;
        }
    }
    return count;
}

int RightDigit(int a[], int b[])
{
    int i, j;
    int count = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            if (a[i] == b[j])
            {
                count++;
            }
        }
    }
    return count;
}
