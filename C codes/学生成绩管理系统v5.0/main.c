#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STUDENT_NUM 30
#define COURSE_NUM 6
#define MAX_LEN 10

struct student
{
    char num[MAX_LEN];
    char name[MAX_LEN];
    float score[COURSE_NUM];
    float sum;
    float avg;
    struct student *next;
};
typedef struct student STUDENT;

int Menu(void);
STUDENT *InputData(STUDENT *head, int n, int m);
STUDENT *AddData(STUDENT *head, int m, int *n);
STUDENT *InsertData(STUDENT *head, int m, int *n);
STUDENT *DeleteData(STUDENT *head, int m, int *n);
void CalculateEveryCourse(STUDENT *head, int n, int m);
STUDENT *CalculateEveryStudent(STUDENT *head, int n, int m);
STUDENT *SortScore(STUDENT *head, int n, int m, int (*compare)(float a, float b));
int Descending(float a, float b);
int Ascending(float a, float b);
void SwapScore(float *a, float *b);
void SwapId(char a[], char b[]);
void SwapName(char a[], char b[]);
STUDENT *SortName(STUDENT* head, int n, int m);
STUDENT *SortId(STUDENT *head, int n, int m);
void SearchId(STUDENT *head, int n, int m);
void SearchName(STUDENT *head, int n, int m);
void Statistic(STUDENT *head, int n, int m);
void PrintData(STUDENT *head, int n, int m);



int main()
{
    int select;
    int n, m;
    STUDENT *head = NULL;
    printf("Please input student number(n<%d):", STUDENT_NUM);
    scanf("%d", &n);
    printf("Please input course number(m<%d):", COURSE_NUM);
    scanf("%d", &m);
    while (1)
    {
        select = Menu();
        switch (select)
        {
        case 1:
            head = InputData(head, n, m);
            break;
        case 2:
            head = AddData(head, m, &n);
            break;
        case 3:
            head = InsertData(head, m, &n);
            break;
        case 4:
            head = DeleteData(head, m, &n);
            break;
        case 5:
            CalculateEveryCourse(head, n, m);
            break;
        case 6:
            head = CalculateEveryStudent(head, n, m);
            break;
        case 7:
            head =SortScore(head, n, m, Descending);
            printf("\nSort in Descending order by sum:\n");
            PrintData(head, n, m);
            break;
        case 8:
            head = SortScore(head, n, m, Ascending);
            printf("\nSort in Ascending order by sum:\n");
            PrintData(head, n, m);
            break;
        case 9:
            head = SortId(head, n, m);
            printf("\nSort in ascending order by number:\n");
            PrintData(head, n, m);
            break;
        case 10:
            head = SortName(head, n, m);
            printf("\nSort in dictionary order by name:\n");
            PrintData(head, n, m);
            break;
        case 11:
            SearchId(head, n, m);
            break;
        case 12:
            SearchName(head, n, m);
            break;
        case 13:
            Statistic(head, n, m);
            break;
        case 14:
            PrintData(head, n, m);
            break;
        case 0:
            printf("End of Program!\n");
            exit(0);
        default:
            printf("Input error!\n");
        }
    }
    return 0;
}

int Menu(void)
{
    int select;
    printf("\n1. Input record\n");
    printf("2. Add record\n");
    printf("3. Insert record by ascending ID\n");
    printf("4. Delete record by ID\n");
    printf("5. Calculate total and average score of every course\n");
    printf("6. Calculate total and average score of every student\n");
    printf("7. Sort in descending order by total score of every student\n");
    printf("8. Sort in ascending order by total score of every student\n");
    printf("9. Sort in ascending order by ID\n");
    printf("10. Sort in dictionary order by name\n");
    printf("11. Search by ID\n");
    printf("12. Search by name\n");
    printf("13. Statistic analysis for every course\n");
    printf("14. List record\n");
    printf("0. Exit\n");
    printf("Please enter your choice:");
    scanf("%d", &select);
    return select;
}

STUDENT *InputData(STUDENT *head, int n, int m)
{
    STUDENT *p = NULL, *pr = head;
    int i, j;
    if (n > 0)
    {
        // 建立头结点
        p = (STUDENT *)malloc(sizeof(STUDENT));
        if (p == NULL)
        {
            printf("No enough memory to allocate!\n");
            exit(0);
        }
        head = p;
        pr = p;
        printf("Input Please input student's id,name and score of every course:");
        scanf(" %s", p -> num);
        scanf(" %s", p -> name);
        for (j = 0; j < m; j++)
        {
            scanf("%f", &p -> score[j]);
        }
        for (i = 1; i < n ; i++)// 继续添加剩余n-1人数据
        {
            p = (STUDENT *)malloc(sizeof(STUDENT));
            if (p == NULL)
            {
                printf("No enough memory to allocate!\n");
                exit(0);
            }
            printf("Input Please input student's id,name and score of every course:");
            scanf(" %s", p -> num);
            scanf(" %s", p -> name);
            for (j = 0; j < m; j++)
            {
                scanf("%f", &p -> score[j]);
            }
            pr -> next = p;
            pr = p;
        }
        pr -> next = NULL;
    }
    else head = NULL;
    return head;
}

STUDENT *AddData(STUDENT *head, int m, int *n)
{
    STUDENT *p = NULL, *pr = head;
    char c;
    int j;
    int count = 0;
    printf("Do you add a new record(Y/N)?");
    scanf(" %c", &c);
    while (c == 'y' || c == 'Y')
    {
        p = (STUDENT *)malloc(sizeof(STUDENT));
        if (p == NULL)
        {
            printf("No enough memory to allocate!\n");
            exit(0);
        }
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            while (pr -> next != NULL)
            {
                pr = pr -> next;
            }
            pr ->next = p;
        }
        printf("Input Please input student's id,name and score of every course:");
        scanf(" %s", p -> num);
        scanf(" %s", p -> name);
        for (j = 0; j < m; j++)
        {
            scanf("%f", &p -> score[j]);
        }
        p -> next = NULL;
        printf("Do you add a new record(Y/N)?");
        scanf(" %c", &c);
        count++;
    }
    printf("Add %d student record\n", count);
    *n += count;
    return head;
}

STUDENT *InsertData(STUDENT *head, int m, int *n)
{
    STUDENT *p = head, *pr = head, *temp = NULL;
    char c;
    int j;
    int count = 0;
    printf("Do you insert a new record(Y/N)?");
    scanf(" %c", &c);
    while (c == 'y' || c == 'Y')
    {
        p = (STUDENT *)malloc(sizeof(STUDENT));
        if (p == NULL)
        {
            printf("No enough memory to allocate!\n");
            exit(0);
        }
        p -> next = NULL;
        printf("Input Please input student's id,name and score of every course:");
        scanf(" %s", p -> num);
        scanf(" %s", p -> name);
        for (j = 0; j < m; j++)
        {
            scanf("%f", &p -> score[j]);
        }
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            while(pr -> next != NULL && strcmp(pr -> num, p -> num ) < 0)
            {
                temp = pr;
                pr = pr -> next;
            }
            if (strcmp(pr -> num , p -> num) >= 0 )
            {
                if (pr == head)
                {
                    p -> next = head;
                    head = p;
                }
                else
                {
                    pr = temp;
                    p -> next = pr -> next;
                    pr -> next = p;
                }
            }
            else
            {
                pr -> next = p;
            }
        }
        count ++;
        printf("Do you insert a new record(Y/N)?");
        scanf(" %c", &c);
        pr = head;
        temp = NULL;
    }
    *n += count;
    printf("Insert %d student record\n", count);
    return head;
}

STUDENT *DeleteData(STUDENT *head, int m, int *n)
{
    STUDENT *p = head, *pr = head;
    char DelId[MAX_LEN];
    char c;
    int count = 0;
    if (head == NULL)
    {
        printf("Student record is empty!\n");
        return(head);
    }
    printf("Do you delete a record(Y/N)?");
    scanf(" %c", &c);
    while (c == 'y' || c == 'Y')
    {
        printf("Please input you want to delete student's ID:");
        scanf(" %s", DelId);
        while (strcmp(DelId , p -> num) != 0 && p -> next != NULL)
        {
            pr = p;
            p = p -> next;
        }
        if (strcmp(DelId , p -> num) == 0)
        {
            if (p == head)
            {
                head = p -> next;
            }
            else
            {
                pr -> next = p -> next;
            }
            free(p);
            count++;
        }
        else
        {
            printf("This ID has not been found!\n");
        }
        printf("Do you delete a record(Y/N)?");
        scanf(" %c", &c);
    }
    *n -= count;
    printf("Delete %d student record\n", count);
    return head;
}

void CalculateEveryCourse(STUDENT *head, int n, int m)
{
    STUDENT *p = head;
    int i, j;
    float sum[COURSE_NUM], average[COURSE_NUM];
    for (j = 0; j < m; j++)
    {
        sum[j] = 0;
        for (i = 0; i < n; i++)
        {
            sum[j] += p -> score[j];
            p = p -> next;
        }
        average[j] = n > 0 ? sum[j] / n : -1;
        printf("Course %d. sum = %.0f average = %.2f\n", j + 1, sum[j], average[j]);
        p = head;
    }
}

STUDENT *CalculateEveryStudent(STUDENT *head, int n, int m)
{
    STUDENT *p = head;
    int i, j;
    for (i = 0; i < n; i++)
    {
        p -> sum = 0;
        for(j = 0; j < m; j++)
        {
            p -> sum += p -> score[j];
        }
        p -> avg = m > 0 ? p -> sum / m : -1;
        printf("Student %d. %s\t%s\tsum = %.0f, average = %.2f\n", i + 1, p -> num, p -> name, p -> sum, p -> avg);
        p = p -> next;
    }
    return head;
}

STUDENT *SortScore(STUDENT *head, int n, int m, int (*compare)(float a, float b))
{
    STUDENT *p = head, *pr = head, *pi = head;
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            p = p -> next;
            if ((*compare)(p -> sum, pr -> sum))
            {
                k = j;
                pr = p;
            }
        }
        if (k != i)
        {
            for (t = 0; t < m; t++)
            {
                SwapScore(&pi -> score[t], &pr -> score[t]);
            }
            SwapScore(&pi -> sum, &pr -> sum);
            SwapScore(&pi -> avg, &pr -> avg);
            SwapId(pi -> num, pr -> num);
            SwapName(pi -> name, pr -> name);
        }
        pi = pi -> next;
        p = pi;
        pr = pi;
    }
    return head;
}

int Descending(float a, float b)
{
    return a > b;
}

int Ascending(float a, float b)
{
    return a < b;
}

void SwapScore(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void SwapId(char a[], char b[])
{
    char temp[MAX_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void SwapName(char a[], char b[])
{
    char temp[MAX_LEN];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}


STUDENT *SortId(STUDENT *head, int n, int m)
{
    STUDENT *p = head, *pr = head, *pi = head;
    int i, j, k, t;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            p = p -> next;
            if (strcmp(p -> num, pr -> num) < 0)
            {
                k = j;
                pr = p;
            }
        }
        if (k != i)
        {
            for (t = 0; t < m; t++)
            {
                SwapScore(&pi -> score[t], &pr -> score[t]);
            }
            SwapScore(&pi -> sum, &pr -> sum);
            SwapScore(&pi -> avg, &pr -> avg);
            SwapId(pi -> num, pr -> num);
            SwapName(pi -> name, pr -> name);
        }
        pi = pi -> next;
        p = pi;
        pr = pi;
    }
    return head;
}

STUDENT *SortName(STUDENT *head, int n, int m)
{
    STUDENT *p = head, *pr = head, *pi = head;
    int i, j, t;
    for (i = 0; i < n - 1; i++)
    {
        pi = pi -> next;
        for (j = i + 1; j < n; j++)
        {
            p = p -> next;
            if (strcmp(pr -> name, p -> name) > 0)
            {
                for (t = 0; t < m; t++)
                {
                    SwapScore(&pr -> score[t], &p -> scoret[t]);
                }
                SwapName(pr -> name, p -> name);
                SwapId(pr -> num, p -> num);
                SwapScore(&pr -> avg, &p -> avg);
                SwapScore(&pr -> sum, &p -> sum);
            }
            pr = pr -> next;
        }
        pr = pi;
        p = pi;
    }
    return head;
}

void SearchId(STUDENT *head, int n, int m)
{
    STUDENT *p = head;
    char number[MAX_LEN];
    int i, t;
    printf("Input the number you want to search:");
    scanf(" %s", number);
    for (i = 0; i < n; i++)
    {
        if (strcmp(p -> num , number) == 0)
        {
            printf("%s\t%s\t", p -> num, p -> name);
            for (t = 0; t < m; t++)
            {
                printf("%.0f\t", p -> score[t]);
            }
            printf("%.0f\t%.2f\n", p -> sum, p -> avg);
            return;
        }
        p = p -> next;
    }
    printf("\nNot found!\n");
}

void SearchName(STUDENT *head, int n, int m)
{
    STUDENT *p = head;
    char studentName[MAX_LEN];
    int i, t;
    printf("Input the name you want to search:");
    scanf(" %s", studentName);
    for (i = 0; i < n; i++)
    {
        if (strcmp(p -> name, studentName) == 0)
        {
            printf("%s\t%s\t",p -> num, p -> name);
            for (t = 0; t < m; t++)
            {
                printf("%.0f\t", p -> score[t]);
            }
            printf("%.0f\t%.2f\n", p -> sum, p -> avg);
            return;
        }
        p = p -> next;
    }
    printf("\nNot found!\n");
}

void Statistic(STUDENT *head, int n, int m)
{
    STUDENT *p = head;
    int i, j;
    int total;
    int count[6];
    for (j = 0; j < m; j++)
    {
        printf("For course %d:\n", j + 1);
        memset(count, 0, sizeof(count));
        for (i = 0; i < n; i++)
        {
            if (p -> score[j] >= 0 && p -> score[j] < 60) count[0]++;
            else if (p -> score[j] < 70) count[1]++;
            else if (p -> score[j] < 80) count[2]++;
            else if (p -> score[j] < 90) count[3]++;
            else if (p -> score[j] < 100) count[4]++;
            else if (p -> score[j] == 100) count[5]++;
            p = p -> next;
        }
        p = head;
        for (total = 0, i = 0; i <= 5; i++)
        {
            total += count[i];
        }
        printf("total count number:%d\n", total);

        for (i = 0; i <= 5; i++)
        {
            if (i == 0)
            {
                printf("<60\t%d %.2f%%\n", count[i], (float)count[i] / n * 100);
            }
            else if (i == 5)
            {
                printf("%d\t%d %.2f%%\n", (i+5) * 10, count[i], (float)count[i] / n * 100);
            }
            else
            {
                printf("%d%C%d\t%d %.2f%%\n", (i+5)*10, '~', (i+5)*10+9, count[i], (float)count[i]/n*100);
            }
        }
    }
}

void PrintData(STUDENT *head, int n, int m)
{
    STUDENT *p = head;
    int i, t;
    printf("学号\t姓名\t科目分数\t\\总分\\平均分\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\t%s\t", p -> num, p -> name);
        for (t = 0; t < m; t++)
        {
            printf("%.0f\t", p -> score[t]);
        }
        printf("%.0f\t%.2f\n", p -> sum, p -> avg);
        p = p -> next;
    }
}
