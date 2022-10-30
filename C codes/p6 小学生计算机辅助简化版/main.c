#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, answer, count = 0, flag = 0;
    srand((unsigned)time(NULL));
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    do
    {
     printf("%d * %d = ?\n", a, b);
     printf("Please enter the answer:");
     scanf("%d", &answer);
     if (a * b == answer)
     {
       printf("Right! continue to the next problem\n");
       flag = 1;
     }
     else
     {
       count++;
       if(count < 3)
       {
        printf("Wrong! Please try again\n");
       }
       else
       {
        printf("Wrong! You have tried three times! Test over!\n");
       }
     }
    }while( flag != 1 && count <3);
    return 0;
}
