#include<stdio.h>
//#include<stdlib.h>

// Just do as required, but the transform function is universial when n is under 10.

int any2d(int xn, int n);
int d2any(int xd, int n);

int main()
{
    int m7, n7;
    int m10, n10;
    int sum10, sum7;
    scanf("%d%d", &m7, &n7);
    m10 = any2d(m7, 7);
    n10 = any2d(n7, 7);
    sum10 = m10 + n10;
    sum7 = d2any(sum10, 7);
    printf("%d(7) + %d(7) = %d(10) + %d(10) = %d(10) = %d(7)\n", m7, n7, m10, n10, sum10, sum7);
//    system("pause");
    return 0;
}

int any2d(int xn, int n)
{
    int xd, digitn;
    for(xd = 0, digitn = 1; xn > 0; xn = xn / 10, digitn = digitn * n)
        xd = xd + (xn % 10) * digitn;
    return xd;
}

int d2any(int xd, int n)
{
    int xn, digit10;
    for(xn = 0, digit10 = 1; xd > 0; digit10 = digit10 * 10, xd = xd / n)
        xn = xn + (xd % n) * digit10;
    return xn;
}
