#include<stdio.h>

int main()
{
    int c;
    int i, j;
    int sum, diff;
    int count = 0;
    FILE *pf = fopen("generated.c", "w");
    if(pf == NULL)
	return 1;
    //Input following content
/*
#include<stdio.h>

int main()
{
    int s[730][2] = {
*/
    
    for(i = 2; i <= 10000; i++)
    {
	sum = 1;
	for(j = 2; (j * j) < i; j++)
	    if((i % j) == 0 && (sum - i) <= 100)
		sum = sum + j + i / j;
	if((j * j + 2 * j + 1) == i)
	    sum = sum + j + 1;
	diff = sum - i;
	if(diff >= -100 && diff <= 100)
	{
	    //Input following content
	    /*{%d, %d}, 
	      {%d, %d}}
	     */
	    fprintf(pf,"",);
	    count = count + 1;
	}
    }


    fclose(pf);
    return 0;
}
