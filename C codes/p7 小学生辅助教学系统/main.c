#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Calculate (int a, char op, int b);
int RandomNumber();
char RandomOperator();
void RandomRightEvaluation();
void RandomWrongEvaluation();

int main()
{
    int a, b;
    int count = 0;
    int userAnswer;
    float rate;
    char op;
    srand(time(NULL));
    do
    {
        a = RandomNumber();
        b = RandomNumber();
        op = RandomOperator();
        printf("%d %c %d = ?\n", a, op, b);
        scanf("%d", &userAnswer);
        if (userAnswer == Calculate(a, op, b))
        {
            RandomRightEvaluation();
            count++;
        }
        else
        {
            RandomWrongEvaluation();
        }
        rate = count / 10.0 * 100;
        printf("Total score is %d \n", count * 10);
        printf("Rate of correctness is %.1f%%\n", rate);
        if (rate < 75)
        {
            printf("Once again\n");
            count = 0;
        }
    }while (rate < 75);
    return 0;
}

int Calculate(int a, char op, int b)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: printf("Operator error!\n");
    }
}


int RandomNumber()
{
    return rand() % 10 + 1;
}


char RandomOperator()
{
    int op;
    op = rand() % 4 + 1;
    switch (op)
    {
        case 1: return '+';
        case 2: return '-';
        case 3: return '*';
        case 4: return '/';
        default: printf("Operator error!\n");
    }
}


void RandomRightEvaluation()
{
    int i;
    i = rand() % 4 + 1;
    switch (i)
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
}


void RandomWrongEvaluation()
{
    int i;
    i = rand() % 4 + 1;
    seitch (i)
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
