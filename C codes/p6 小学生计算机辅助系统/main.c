#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    int i, a, b, userAnswer, systemAnswer, op, count = 0;
    int rightType, wrongType;
    float rate;
    char opchar;
    srand((unsigned)time(NULL));
    do
    {
        for (i = 1 ; i <= 10; ++i)
        {
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;
            op = rand() % 4 + 1;
            rightType = rand() % 4 + 1;
            wrongType = rand() % 4 + 1;
            switch (op)
            {
            case 1:
                opchar = '+';
                systemAnswer = a + b;
                break;
            case 2:
                opchar = '-';
                systemAnswer = a - b;
                break;
            case 3:
                opchar = '*';
                systemAnswer = a * b;
                break;
            case 4:
                opchar = '/';
                systemAnswer = a / b;
                break;
            default :
                printf("op not exist\n");
            }
            printf("%d%c%d = ?\n", a,opchar, b);
            printf("Please enter the userAnswer:");
            scanf("%d", &userAnswer);
            if (systemAnswer == userAnswer)
            {
                printf("Right!\n");
                switch (rightType)
                {
                case 1:
                    printf("Very good!\n");
                    break;
                case 2:
                    printf("EXcellent!\n");
                    break;
                case 3:
                    printf("Nice work!\n");
                    break;
                case 4:
                    printf("Keep up the good work!\n");
                    break;
                default:
                    printf("wrong type\n");
                }
                count++;
            }
            else
            {
                printf("Wrong!\n");
                switch (wrongType)
                {
                case 1:
                    printf("No. Please try again\n");
                    break;
                case 2:
                    printf("Wrong. Try once more\n");
                    break;
                case 3:
                    printf("Don't give up\n");
                    break;
                case 4:
                    printf("Not correct. Keep trying\n");
                    break;
                default:
                    printf("wrong type\n");
                }
            }
        }
        rate = count / 10.0 * 100;
        printf("Total score: %d,", count * 10);
        printf("Rate of correct: %.0f%%\n", rate);
        if (rate < 75)
        {
            printf("Please try again\n");
            count = 0;
        }
    }while (rate < 75);
    return 0;
}
