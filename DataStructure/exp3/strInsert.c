#include<stdio.h>
#include<

#define LENGTH 1000

int main()
{
    char buffer[LENGTH];
    int a, b;
    a = getStr(buffer);
    b = getStr(&buffer[a + 1]);

    char k;
    scanf("%c", &k);

    
}

int getStr(char *w)
{
    gets(w);
    return strlen(w);
}


int findK(char *str, char k)
{
    int i = 0;
    while(*str != k && str != '\0')
    {
	str++;
	i++;
    }
    
    if(*str == k)
    {
	return i;
    }
    else
    {
	return -1;
    }
}

void insertConnectedStr(char *str, int a, int b, int k)
{
    
}

/* In a group of such permutation:
 * every element, with position 'pos' is rearranged to position addressMap(size, i, pos)
 * addressMap = { 
 */
int addressMap(int size, int i, int pos)
{
    
}

void permute(char *head, int size, int i)
{
    
}
