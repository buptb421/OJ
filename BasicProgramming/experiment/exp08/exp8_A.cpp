#include<stdio.h>

int main()
{
    int score[100];
    int number;
    scanf("%d", &number);
    
    int *p = score;
    for(int i = 1; i <= number; i = i + 1, p = p + 1)// Let pointer run from a[0] to a[n]
	scanf("%d", p);

    p = score;

    int sum = 0;
    for(int i = 1; i <= number; i = i + 1, p = p + 1)// The same
	sum = sum + *p;

    double average = sum;
    average = average / number;
    printf("%.2lf\n", average);

    return 0;
}
