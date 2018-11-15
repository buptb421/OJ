#include<stdio.h>

int main()
{
    int s[730][2] = {{2, 3}, {3, 5}};
    int a, b, c;
    int i, j;
    j = 0;
    for(i = 0; i < 730; i = i + 1)
    {
	if(s[i][1] >= a && s[i][1] <= b && s[i][2] <= c)
	{
	    j = j + 1;
	    printf("%d", s[i][1]);
	    if((j % 5) == 0)
		printf("\n");
	    else
		printf("\t");
	}
    }
    if((j % 5) != 0)
	printf("\n");
    if(j == 0)
	printf("There is no proper number in the interval.");
    return 0;
}
