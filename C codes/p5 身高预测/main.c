#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    char sex, sports, diet;
    float faHeight, moHeight, myHeight;
    printf("please enter your sex, boy input M and girl input the F: ");
    scanf(" %c", &sex);
    printf("please input your father's height: ");
    scanf("%fcm", &faHeight);
    printf("please input your mother's height: ");
    scanf("%fcm", &moHeight);
    printf("Do you like sports ? (Y/N): ");
    scanf(" %c", &sports);
    printf("Do you have a health diet? (Y/N): ");
    scanf(" %c", &diet);
    if(sex == 'M' || sex == 'm')
    {
        myHeight = (faHeight + moHeight) * 0.54;
    }
    else
    {
        myHeight = (faHeight * 0.923 + moHeight) / 2.0;
    }
    if(sports == 'Y' || sports == 'y')
    {
        myHeight = myHeight * (1 + 0.02);
    }
    if(diet == 'Y' || diet == 'y')
    {
        myHeight = myHeight * (1 + 0.015);
    }
    printf("myHeight is %.1f cm", myHeight);
    return 0;
}
