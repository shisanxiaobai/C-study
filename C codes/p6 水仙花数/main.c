#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    int ones ,tens, hundreds, n;
    for (n = 100; n < 1000; n++)
    {
        ones = n % 10;
        hundreds = n / 100;
        tens = (n - 100 * hundreds) / 10 ;
        if (n == hundreds * hundreds * hundreds + tens * tens * tens + ones * ones * ones)
        {
            printf("daffodils number is %6d\n", n);
        }
    }
    return 0;
}
*/

int main()
{
   int i, j, k;

   for(i = 1; i <= 9; i++)
   {
       for (j = 0; j <= 9; j++)
       {
           for (k = 0; k <= 9; k++)
           {
               if (100 * i + 10 * j + k == i * i * i + k * k * k + j * j * j)
               {
                   printf("daffodils number is %6d\n", 100 * i + 10 * j + k);
               }
           }
       }
   }
   return 0;
}
