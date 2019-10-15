#include<stdio.h>

int main()
{
    char c;
    double n = 0.0;
    scanf("%c", &c);
    while(c != '#' && c != '.')
    {
        n = n * 2.0;
        n = n + (c - '0');
        scanf("%c", &c);
    }
    if(c == '.')
        scanf("%c", &c);
    else
    {
        int z;
        z = n;
        printf("%d", z);
        return 0;
    }
    double dec = 1.0;
    while(c != '#')
    {
        dec = dec / 2.0;
        n = n + dec * (c - '0');
        scanf("%c", &c);
    }
    printf("%.6lf", n);
    return 0;
}
