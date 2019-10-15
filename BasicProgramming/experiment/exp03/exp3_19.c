// Experiment3_19

#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c;
    float delta;
    float real, imag;
    
    scanf("%f%f%f", &a, &b, &c);
    if (fabs(a) <= 0)
	printf("The equation is not quadratic.\n");
    else
    {
	    delta = b * b - 4 * a * c;
	    real = - b / 2 / a;
	    if((- delta) > 1e-6)
	    {
	        imag = fabs(sqrt(- delta) / 2 / a);
	        printf("The equation has two complex roots: %.4f+%.4fi and %.4f-%.4fi.\n", real, imag, real, imag);
	    }
	    else if(fabs(delta) <= 1e-6)
		    printf("The equation has two equal roots: %.4f.\n", real);	    
	    else 
		{
			imag = diff / 2;
	        printf("The equation has two distinct real roots: %.4f and %.4f.\n",real + imag, real - imag); 
        }
	}
    return 0;
}
