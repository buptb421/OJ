#include<stdio.h>

int main()
{
    int p[4];
    for(int i = 0; i < 4; i = i + 1)
	scanf("%d", p[i]);

    int derivate_p[3];
    for(int i = 0; i < 3; i = i + 1)
	derivate_p[i] = p[i + 1] * (i + 1);
    
    double x_n, x_np1;
    double f_n, df_n;
    x_n = 1.0;
    x_np1 = 0.0;
    do
    {
	for(int i = 3, double item = 1.0, f_n = 0; i >= 0; i = i - 1, item = item * x)
	    f_n = f_n + p[i] * item;
	for(int i = 2, double item = 1.0, df_n = 0; i >= 0; i = i - 1, item = item * x)
	    
    }while(x_n - x_np1 > 1e-5 || x_n)
    
