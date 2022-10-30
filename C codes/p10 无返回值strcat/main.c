#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MyStrcat(char *s, char *t);
/*×Ö·ûÊý×é
void MyStrcat(char s[], char t[]);

int main()
{
    char s[100], t[100];
    printf("Input s string:");
    gets(s);
    printf("Input t string:");
    gets(t);
    MyStrcat(s, t);
    printf("%s", s);
    return 0;
}

void MyStrcat(char s[], char t[])
{
    int i, j;
    i = strlen(s);
    for (j = 0; t[j] != '\0'; j++)
    {
        s[i] = t[j];
        i++;
    }
}*/

void MyStrcat(char s[], char t[]);

int main()
{
    char s[100], t[100];
    printf("Input s string:");
    gets(s);
    printf("Input t string:");
    gets(t);
    MyStrcat(s, t);
    printf("%s", s);
    return 0;
}

void MyStrcat(char *s, char *t)
{
    while (*s != '\0')
    {
        s++;
    }
    while (*t != '\0')
    {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}
