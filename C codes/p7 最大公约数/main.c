#include <stdio.h>
#include <stdlib.h>

int Gcd(int a,int b);

int main()
{
    int a, b, x;
    printf("Please input a and b:");
    scanf("%d%*c%d", &a, &b);
    x = Gcd(a,b);
    if (x)
    {
        printf("Greatest common divisor of %d and %d is %d\n", a, b, Gcd(a, b));
    }
    else
    {
        printf("Input error\n");
    }
    return 0;
}
/* 穷举法 先找到ab中较小数t，令t自减， 检验1到t之间所有整数，第一个满足公约数条件t的就是最大公约数；
int Gcd(int a,int b)
{
    int i, t;
    if (a <= 0 || b <= 0)
    {
        return -1;
    }
    t = a < b ? a : b;
    for (i = t; i >= 1; t--)
    {
        if ( a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}
*/

/*辗转相除法 非递归
int Gcd(int a, int b)
{
    int r;
    if (a <= 0 || b <= 0)
        return -1;
    do
    {
        r = a % b;
        a = b;
        b = r;
    }while(r != 0);
    return a;
}
*/

//递归法
int Gcd(int a, int b)
{
    if (a <= 0 || b <= 0)
        return -1;
    if (a == b)
        return a;
    else if (a > b)
    {
       return Gcd(a - b, b);
    }
    else
    {
       return Gcd(a, b - a);
    }
}
