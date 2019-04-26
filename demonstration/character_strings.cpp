/*
  This program can be improved as long as you use a technique called a "function pointer".  
 */ 

#include<stdio.h>

void inputStr(char str[], const int buffer_length);
void outputStr(char str[], const int buffer_length);
void outputStrArr(char divided[][60], const char sep, const int wordN);

int divide(char ori[], const int bl_ori, char div[][60]);

void copyWord_to(char ori[], char cop[], const int buffer_length);
void reverseSent(char div[][60], const int wordN, char rev[][60]);

void reverseWord_self(char str[], const int buffer_length);
void reverseAllWord(char str[][60], const int wordN);

int main()
{
    char ori[300];
    char div[5][60];
    char rev[5][60];
    
    int wordN;
    
    printf("Input:");
    inputStr(ori, 300);
    
    wordN = divide(ori, 300, div);
    
    reverseSent(div, wordN, rev);
    
    outputStrArr(div, ' ', wordN);
    outputStrArr(rev, ' ', wordN);

    reverseAllWord(rev, wordN);

    outputStrArr(rev, ' ', wordN);
    
    return 0;
}

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

void outputStr(char str[], const int buffer_length)
{
    int i;
    for(i = 0; i < buffer_length && str[i] != '\0'; i++)
    {
	printf("%c", str[i]);
    }
}

void outputStrArr(char divided[][60], const char sep, const int wordN)
{
    int i;
    for(i = 0; i < wordN; i++)
    {
	outputStr(divided[i], 60);
	if(i < wordN - 1)
	    printf("%c", sep);
    }
    printf("\n");
}

int divide(char ori[], const int bl_ori, char div[][60])
{
    int i, j, wordN;
    for(i = 0, j = 0, wordN = 0; i < bl_ori && (ori[i - 1] != '\0' || i == 0); i++)
    {
	if(i > 0 && ori[i - 1] == ' ')
	{
	    div[wordN][j - 1] = '\0';
	    wordN++;
	    j = 0;
	}
	if(j < 60)
	{
	    div[wordN][j] = ori[i];
	    j++;
	}
    }
    return wordN + 1;
}

void copyWord_to(char ori[], char cop[], const int buffer_length)
{
    int i;
    for(i = 0; i < buffer_length && (ori[i - 1] != '\0' || i == 0); i++)
    {
	cop[i] = ori[i];
    }
}

void reverseSent(char div[][60], const int wordN, char rev[][60])
{
    int i;
    for(i = 0; i < wordN; i++)
    {
	copyWord_to(div[i], rev[wordN - 1 - i], 60);
    }
}

void reverseWord_self(char str[], const int buffer_length)
{
    int len, i;
    char temp;
    for(len = 0; len < buffer_length && str[len] != '\0'; len++);
    for(i = 0; i < len / 2; i++)
    {
	temp = str[i];
	str[i] = str[len - i - 1];
	str[len - i - 1] = temp;
    }
}

void reverseAllWord(char str[][60], const int wordN)
{
    int i;
    for(i = 0; i < wordN; i++)
    {
	reverseWord_self(str[i], 60);
    }
}
