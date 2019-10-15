#include<stdio.h>

int inputString(char c[])
{
    int i = 0;
    scanf("%c", &c[0]);
    while(c[i] != '\n' && i < 101)
    {
	i = i + 1;
	scanf("%c", &c[i]);
    }
    return i;
}

void inputEncryptionList(char c[])
{
    for(int i = 0; i < 26; i = i + 1)
	scanf("%c", &c[(i + 25) % 26]);
    char temp;
    scanf("%c", &temp);
}

void printString(char c[], int length)
{
    for(int i = 0; i < length; i = i + 1)
	printf("%c", c[i]);
    printf("\n");
}

void encrypt(char origin[], int length, char upperc[], char lowerc[])
{
    for(int i = 0; i < length; i = i + 1)
    {
	if(origin[i] >= 'a' && origin[i] <= 'z')
	    origin[i] = lowerc[origin[i] - 'a']; 
	else
	    origin[i] = upperc[origin[i] - 'A'];
    }
}

int main()
{
    char s[101], upperc[26], lowerc[26];
    
    int length = inputString(s);

    inputEncryptionList(upperc);
    
    inputEncryptionList(lowerc);
    
    encrypt(s, length, upperc, lowerc);

    printString(s, length);
    
    return 0;
}
