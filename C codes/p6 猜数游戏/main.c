#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int magic, guess, counter = 0, ret;
    char reply;
    srand(time(NULL));

    do
    {
        counter = 0;
        magic = rand() % 100 + 1;
        do
        {
            printf("please guess a magic number: ");
            ret = scanf("%d", &guess);
            while(ret != 1)
            {
                while(getchar() != '\n');
                printf("please guess a magic number: ");
                ret = scanf("%d", &guess);
            }
            counter ++;
            if (guess > magic)
            {
                printf("wrong! too big!\n");
            }
            else if (guess < magic)
            {
                printf("wrong! too small!\n");
            }
            else
            {
                printf("Right\n");
            }
        }while(guess != magic && counter < 10);

        printf("counter = %d\n", counter);
        printf("Do you want to continue (Y/N or y/n)?: ");
        scanf(" %c", &reply);
    }while(reply =='y' || reply == 'y');

    return 0;
}
