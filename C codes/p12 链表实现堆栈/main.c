#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct stack
{
    int data;
    struct stack *next;
};
typedef struct stack STACK;
STACK *head, *pr;
int nodeNum = 0;

STACK *CreatNode(int num);
STACK *PushStack(int num);
int PopStack(void);

int main()
{
    int pushNum[5] = {111, 222, 333, 444, 555};
    int popNum[5];
    int i;
    for (i = 0; i < 5; i++)
    {
        PushStack(pushNum[i]);
        printf("Push %dth Data:%d\n", i + 1, pushNum[i]);
    }
    for (i = 0; i < 5; i++)
    {
        popNum[i] = PopStack();
        printf("Pop %dth  data:%d\n", 5 - i, popNum[i]);
    }
    return 0;
}

STACK *CreatNode(int num)
{
    STACK *p;
    p = (STACK *)malloc(sizeof(STACK));
    if (p == NULL)
    {
        printf("No enough memory!\n");
        exit(0);
    }
    p -> next = NULL;
    p -> data = num;
    return p;
}

STACK *PushStack(int num)
{
    if (nodeNum == 0)
    {
        head = CreatNode(num);
        pr = head;
        nodeNum++;
    }
    else
    {
        pr -> next = CreatNode(num);
        pr = pr -> next;
        nodeNum++;
    }
    return pr;
}



int PopStack(void)
{
    STACK *p = head;
    int result;
    while(1)
    {
        if (p -> next == NULL)
        {
            break;
        }
        else
        {
            pr = p;
            p = p -> next;
            nodeNum--;
        }
    }
    pr -> next = NULL;
    result = p -> data;
    free(p);
    return result;
}
