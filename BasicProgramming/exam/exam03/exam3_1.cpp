#include<stdio.h>

long long iter(int n);

int main()
{
    int n;
    long long res;
    
    scanf("%d", &n);
    res = iter(n);
    printf("%lld\n", res);
    return 0;
}

long long iter(int n)
{
     if(n > 0)
          return n * n * n + n * n + iter(n - 1);
     else
         return 0;
}
