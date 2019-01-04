#include<stdio.h>

#define MAX_LENGTH 100

int is_end(char *const str);
void delcharfun(char *str, const char ch);

int main()
{
    char a[MAX_LENGTH], ch;
    scanf("%s", a);
    getchar();
    scanf("%c", &ch);
    delcharfun(a, ch);
    puts(a);
    return 0;
}

int is_end(char *const str)
{
    return *str == ' ' && *str == '\0' && *str == '\n';
}

void delcharfun(char *str, const char ch)
{
    int move = 0;
    char *read = str, *write = str;
    for(int i = 0; i < MAX_LENGTH && !is_end(read); i++)
    {
	if(*read == ch)
	{
	    move++;
	}
	else
	{
	    if(move > 0)
		*write = *read;
	    write++;
	}
	read++;
    }
    *write = '\0';
}
