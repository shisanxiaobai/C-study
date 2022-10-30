#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Inverse(char *s);
/* ×Ö·ûÊı×éÄæĞòÅÅÁĞ
void Inverse(char str[]);

int main()
{
    char str[100];
    printf("Input a string:");
    fgets(str, sizeof(str), stdin);
    Inverse(str);
    printf("%s", str);
    return 0;
}

void Inverse(char str[])
{
    int len;
    int i, j;
    char temp;
    len = strlen(str);
    for (i = 0, j =len -1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}*/

int main()
{
    char str[100];
    printf("Input a string:");
    fgets(str, sizeof(str), stdin);
    Inverse(str);
    printf("%s", str);
    return 0;
}

void Inverse(char *s)
{
    int len;
    char temp;
    char *pStart, *pEnd;
    len = strlen(s);
    for (pStart = s, pEnd = len + pStart - 1; pStart < pEnd; pStart++, pEnd--)
    {
        temp = *pStart;
        *pStart = *pEnd;
        *pEnd = temp;
    }
}
