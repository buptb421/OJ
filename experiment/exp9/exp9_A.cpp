#include<stdio.h>
#define LENp1 101

void inputString(char str[]);
void outputString(char str[]);
void back(char *p, int bkoffset);
void cleanEnd(char *p, int tl);
void delcharfun(char str[], char ch);

int main()
{
    char c[LENp1] = {'\0'}, del;
    inputString(c);
    scanf("%c", &del);
    delcharfun(c, del);
    outputString(c);
    return 0;
}

void inputString(char str[])
{
    int i;
    for(i = 0; i < LENp1 && str[i - 1] != '\n'; i++)
	scanf("%c", &str[i]);
    str[i] = '\0';
}// str = {afdsafsafdsfs'\n''\0'|<-(the end)}

void outputString(char str[])
{
    for(int i = 0; str[i] != '\0' && i < LENp1; i++)
	printf("%c", str[i]);
}

void back(char *p, int bkoffset)
{
    *(p - bkoffset) = *p;
}

void cleanEnd(char *p, int maxbkos)// p -> '\0', tl = max{bkoffset}(the last one)
{
    for(int i = 0; i < maxbkos; i++)
    {
	p--;
	*p = '\0';
    }
}// str[]={dfalsdfsa'\0''\0''\0''\0'|<-(the origin end,with tl + 1 \0 behind).....}()

void delcharfun(char str[], char ch)
{
    int i, bkos = 0;
    for(i = 0; i < LENp1 && str[i] != '\0'; i++)
    {
	if(bkos != 0)
	{
	    if(str[i] == ch)
		bkos++;
	    else
		back(&str[i],bkos);
	}
	else if(str[i] == ch)
	    bkos++;
    }
    str[i] = '\0';
    cleanEnd(&str[i], bkos);
}
