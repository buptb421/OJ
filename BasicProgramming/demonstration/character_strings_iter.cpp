#include<stdio.h>

void inputStr(char str[], const int buffer_length)
{
    int i;
    for(i = 0; i < buffer_length && (str[i - 1] != '\n' || i == 0); i++)
    {
	scanf("%c", &str[i]);
    }
    if(i < buffer_length)
	str[i - 1] = '\0';
}

int isEdge(char str[], int i)
{
    if(i < 0 or str[i] == '\0')
	return 1;
    else
	return 0;
}

int isSep(char str[], int i)
{
    if(str[i] == ' ')
	return 1;
    else
	return 0;
}

int reachEnd(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
	i++;	
    }
    return i - 1;	
} 

int readWord(char str[], int i, int step)
{
    int j;
    for(j = i; !isEdge(str, j) && !isSep(str, j); j = j + step)
	printf("%c", str[j]);
    
    return j;
}

int readSent(char str[], int i, int s_step, int w_step)
{
    int j;
    if(s_step * w_step > 0)
    {
	for(j = i; !isEdge(str, j); j = j + s_step)
	{
	    if(!isSep(str, j))
	    {
		j = readWord(str, j, w_step) - s_step;
		printf(" ");
	    }
	}
	printf("\n");
    }
    else
    {
	int sep_handler;
	for(j = i; !isEdge(str, j); j = j + s_step)
	{
	    if(isSep(str, j))
	    {
		if(sep_handler == 0)
		{
		    sep_handler = 1;
		    readWord(str, j - s_step, w_step);
		    printf(" ");
		}
	    }
	    else
		sep_handler = 0;
	}
	readWord(str, j - s_step, w_step);
	printf("\n");
    }
}

int main()
{
    char ori[300];
    
    printf("Input:");
    inputStr(ori, 300);
    
    readSent(ori, 0, 1, 1);
    readSent(ori, 0, 1, -1);
    readSent(ori, reachEnd(ori), -1, 1);
    readSent(ori, reachEnd(ori), -1, -1);
    
    return 0;
}
 

