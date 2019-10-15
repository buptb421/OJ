#include<stdio.h>

int judgeTriangle(int a, int b, int c);

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    
    int n = judgeTriangle(a, b, c);
    if(n == -1)
	printf("It is not a triangle.\n");
    else if(n == 0)
	printf("It is a scalenous triangle.\n");
    else if(n == 1)
	printf("It is a right-angled triangle.\n");
    else if(n == 2)
	printf("It is an isosceles triangle.\n");
    else
	printf("It is a equilateral triangle.\n");
    
    return 0;
}

int judgeTriangle(int a, int b, int c)
{
    if((a + b) <= c ||
       (b + c) <= a ||
       (a + c) <= b)
	return -1;
    else if((a * a + b * b) == (c * c) ||
	    (a * a + c * c) == (b * b) ||
	    (b * b + c * c) == (a * a))
	return 1;
    else if(a == b &&
	    b == c)
	return 3;
    else if (a == b ||
	     b == c ||
	     c == a)
	return 2;
    else
	return 0;
}
