#include<stdio.h>

int main()
{
    double a;
    int b;
    scanf("%lf", &a);
    b = (a + 0.005) * 100;
    printf("%d", b);
    return 0;
}
