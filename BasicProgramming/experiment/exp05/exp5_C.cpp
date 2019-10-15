#include<stdio.h>

int main()
{
    int p[4];
    for(int i = 0; i < 4; i = i + 1)
	scanf("%d", &p[i]);

    double x_n;
    double f_n, df_n;
    x_n = 1.0;

    double diff = 0.0;
    double item;
    int i;

    do
    {
	x_n = x_n - diff;
	for(i = 3, item = 1.0, f_n = 0.0; i >= 0; i = i - 1, item = item * x_n)
	    f_n = f_n + p[i] * item;
	for(i = 2, item = 1.0, df_n = 0.0; i >= 0; i = i - 1, item = item * x_n)
	    df_n = df_n + p[i] * item * (3 - i);
	diff = f_n / df_n;
    }while(diff > 1e-5 || diff < -1e-5);
    x_n = x_n - diff;
    printf("%.6lf\n", x_n);
    return 0;
}
