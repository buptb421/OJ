#include<stdio.h>
#include<math.h>

int main()
{
    double sum, obj, fac;
    double x;
    sum = 0.0;
    obj = 1.0;
    fac = 1.0;
    scanf("%lf", &x);
    while(fabs(obj) >= 1e-8)
    {
        sum = sum + obj;
	obj = obj / fac * x;
	fac = fac + 1.0;
    }
    printf("%.4lf", sum);
//    printf(" %.4lf\n", exp(x));
    return 0;
}
