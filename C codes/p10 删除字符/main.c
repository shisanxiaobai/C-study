#include <stdio.h>
#include <stdlib.h>

void Strdelete(char *p, char c);
//void Strdelete(char str[], char c);
//字符数组作为函数参数
/*int main()
{
    char c;
    char str[100];
    printf("Input s:");
    fgets(str, sizeof(str), stdin);
    printf("Input c:");
    c = getchar();
    Strdelete(str, c);
    printf("%s\n", str);
    return 0;
}

void Strdelete(char str[], char c)
{
    int i, j;
    for (i = j = 0; str[i] != '\0'; i++)
    {
        if (str[i] != c)
        {
            str[j] = str [i];
            j++;
        }
    }
    str[j] = '\0';
}*/

int main()
{
    char c;
    char str[100];
    printf("Input s:");
    fgets(str, sizeof(str), stdin);
    printf("Input c:");
    c = getchar();
    Strdelete(str, c);
    printf("%s\n", str);
    return 0;
}

void Strdelete(char *p, char c)
{
    char *t1 = p, *t2 = p;
    for( ;*t1 != '\0'; t1++)
    {
        if (*t1 != c)
        {
            *t2 = *t1;
            t2++;
        }
    }
    *t2 = '\0';
}
