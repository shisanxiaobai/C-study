#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertCharacter(char *s);

//×Ö·ûÊı×é²åÈë
/*void InsertCharacter(char str[]);

int main()
{
    char str[100];
    printf("Please input character:");
    fgets(str, sizeof(str), stdin);
    InsertCharacter(str);
    printf("%s", str);
    return 0;
}

void InsertCharacter(char str[])
{
    int i, j;
    char t[100];
    strcpy(t, str);
    for (i = j = 0; str[i] != '\0' ; i++,j++)
    {
        str[j] = t[i];
        j++;
        str[j] = ' ';
    }
    str[j] = '\0';
}
*/

int main()
{
    char str[100];
    printf("Please input character:");
    fgets(str, sizeof(str), stdin);
    InsertCharacter(str);
    printf("%s\n", str);
    return 0;
}

void InsertCharacter(char *s)
{
    char str[100];
    char *t = str;
    strcpy(t, s);
    for( ; *t != '\0'; t++, s++)
    {
        *s = *t;
        s++;
        *s = ' ';
    }
    *s = '\0';
}
