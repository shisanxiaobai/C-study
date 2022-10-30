#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//报数
int Rnd();
int ControlComputer(int s);
int Input(int t);

int main()
{
    int tol = 1;
    if (Rnd() == 1)
    {
        tol = Input(tol);
    }
    while(tol < 30)
    {
        tol = ControlComputer(tol);
        if (tol == 30)
        {
           printf("Player lose\n");
        }
        else
        {
            tol = Input(tol);
            if (tol >= 30)
            {
                printf("Player win\n");
            }
        }
    }

    printf("Game Over\n");
    return 0;
}

int Rnd()
{
    srand(time(NULL));
    return rand() % 2;
}

int Input(int t)
{
    int a;
    do
    {
        printf("Please input :");
        scanf("%d", &a);
        if (a > 2 || a < 1)
        {
            printf("Input error\n");
        }
        else
        {
            printf("you count:%d\n", t + a);
        }
    }while(a > 2 || a < 1);
    return t + a;
}

int ControlComputer(int s)
{
    int c;
    printf("Computer count:");
    if (s % 3 == 1)
    {
        s++;
        printf("%d\n", s);
    }
    else if (s % 3 == 2)
    {
        s += 2;
        printf("%d\n", s);
    }
    else
    {
        c = Rnd() + 1;
        s = s + c;
        printf("%d\n", s);
    }
    return s;
}
