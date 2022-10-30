#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct card
{
    char suit[10];
    char face[10];
};

typedef struct card POKER;

void FillCard(POKER card[], char * suit[], char * face[]);
void Shuffle(POKER card[]);
void Deal(POKER card[]);

int main()
{
    char * suit[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    char * face[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    POKER card[52];
    srand(time(NULL));
    FillCard(card, suit, face);
    Shuffle(card);
    Deal(card);
    return 0;
}

void FillCard(POKER card[], char * suit[], char * face[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        strcpy(card[i].suit, suit[i / 13]);
        strcpy(card[i].face, face[i % 13]);
    }
}

void Shuffle(POKER card[])
{
    int i, j;
    POKER temp;
    for (i = 0; i < 52; i++)
    {
        j = rand() % 52;
        temp = card[i];
        card[i] = card[j];
        card[j] = temp;
    }
}

void Deal(POKER card[])
{
    int i;
    for (i = 0; i < 52; i++)
    {
        printf("%9s%9s%c", card[i].suit, card[i].face, i%2==0?'\n':'\t');
    }
}
