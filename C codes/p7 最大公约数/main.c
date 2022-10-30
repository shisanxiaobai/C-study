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
/* ��ٷ� ���ҵ�ab�н�С��t����t�Լ��� ����1��t֮��������������һ�����㹫Լ������t�ľ������Լ����
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

/*շת����� �ǵݹ�
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

//�ݹ鷨
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
