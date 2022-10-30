#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int CountWords(char word[]);

int main()
{
    char word[100];
    printf("Please input letter\n");
    fgets(word, sizeof(word), stdin);
    printf("English Words :%d\n", CountWords(word));
    return 0;
}

int CountWords(char word[])
{
    int i;
    int num;
    num = (word[0] != ' ')? 1 : 0;
    for (i = 1; word[i] != '\0'; i++)
   {
        if (word[i] != ' ' && word[i - 1] == ' ')
        {
            num++;
        }
    }
    return num;
}
