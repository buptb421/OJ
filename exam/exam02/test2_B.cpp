#include<stdio.h>
//#include<stdlib.h>

// f(n) = f(n - 1) * 2 * (2 * n + 1) / n;

int main()
{
    long long product = 2;// f(1) = 2, as initial.
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i = i + 1)// i is index to item of f(n) / f(n - 1)
       product = product / i * 2 * (2 * i + 1);
    printf("%lld\n", product);
//    system("pause");
    return 0;
}
