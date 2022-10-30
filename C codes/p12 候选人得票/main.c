#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANDISATE_NUM 3
#define ELECTION_NUM 10



struct candidate
{
    char name[10];
    int vote;
};

int Election(struct candidate candidate[]);

int main()
{
    struct candidate candidate[3] = {"li", 0, "zhang", 0, "wang", 0};
    int i, wrong;
    wrong = Election(candidate);
    printf("Election result:\n");
    for (i = 0; i < 3; i++)
    {
        printf("%8s:%d\n", candidate[i].name, candidate[i].vote);
    }
    printf("Wrong vote:%d\n", wrong);
    return 0;
}

int Election(struct candidate candidate[])
{
    char name[10];
    int i, j;
    int wrong = 0;
    int flag = 1;
    for (i = 0; i < 10; i++)
    {
        printf("Please input vote %d:", i + 1);
        scanf("%s", name);
        strlwr(name);
        flag = 1;
        for (j = 0; j < CANDISATE_NUM; j++)
        {
            if (strcmp(name, candidate[j].name) == 0)
            {
                candidate[j].vote++;
                flag = 0;
            }
        }
        if (flag)
        {
            wrong++;
            flag = 0;
        }

    }
    return wrong;
}
