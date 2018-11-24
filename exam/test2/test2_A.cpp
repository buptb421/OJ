#include<stdio.h>
//#include<stdlib.h>

/*
    list augment matrix of system: 
      A =
         {1, 1, 1; | {m;
          2, 4, 6} |  n}
    make number of ji the free variable of this underdetermined system:
      A' =
         {2 , 1, 0; | {3 * m - n / 2;
          -1, 0, 1} |  n / 2 - 2 * m}
    which is, for all possible number of ji,
      tu = 3 * m - n / 2 - 2 * j;
      qintin = n / 2 - 2 * m + j;
*/

int main()
{
    int j, t, q;//ji tu qintin
    int m , n;
    scanf("%d%d", &m, &n);
    n = n / 2 - 2 * m;
    m = m - n;// After this procedure, {3 * m - n / 2; n / 2 - 2 * m} = {m', n'}
    int max;
    if(n < 0)
        max = -n;
    else
        max = 0;
    for(j = max; j <= m / 2; j = j + 1)// We can find out, to let j > 0 and t >= 0 and q >= 0, there should be m' / 2 >= j >= -n' and j > 0
    {
        t = m - 2 * j;
        q = n + j;
        printf("%d %d %d\n", j, t, q);       
    }
    //    system("pause");
    return 0;
}
