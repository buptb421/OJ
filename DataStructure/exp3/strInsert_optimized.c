#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 1000

int getStr(char *w)
{
    gets(w);
    return strlen(w);
}

int findK(char *str, char k)
{
    int i = 0;
    while (*str != k && *str != '\0')
    {
        str++;
        i++;
    }
    return i;
}

int GCD(int x, int y)
{
    if(y >= x)
    {
        return GCD(y, x);       
    }
    else if(y == 0)
    {
        return x;
    }
    else
    {
        return GCD(y, x % y);
    }
}

/* In a group of such permutation:
 * every element, with position 'pos' is rearranged to position of:
 * addressMap(size, i, pos) = 
 * {  
 *     pos + (size - i), o ~ (i -1)    ;
 *     pos - i         , i ~ (size - 1);
 * {
 */
int exchangeMap(int size, int i, int pos)
{
    if (pos < i)
    {
        return pos + size - i;
    }
    else
    {
        return pos - i;
    }
}

void permute(char *strHead, int size, int i) // strHead is the pointer to the keyword k, where we start to exchange the char.
{
    int nClass = GCD(size, i);
    if(nClass <= 1)
    {
    	nClass = 1; 
        char temp = strHead[0];
        int now = 0, next;
        i = size - i;
        for(int j = 1; j < size; j++)
        {
            next = exchangeMap(size, i, now);
            now = next;
            strHead[now] = strHead[next];
        }
        strHead[exchangeMap(size, i, now)] = temp;
    }
    else
    {
        int order = size / nClass, prev = 0;
        char temp;
        char **permuteList = (char **)malloc(sizeof(char *) * order);
        permuteList[0] = &strHead[prev];
        i = size - i;
        for(int j = 1; j < order; j++)
        {
            prev = exchangeMap(size, i, prev);
            permuteList[j] = &strHead[prev];
        }
        for(int j = 0; j < nClass; j++)
        {
            temp = *permuteList[0];
            for(int k = 1; k < order; k++)
            {
                *permuteList[k - 1] = *permuteList[k];
                permuteList[k - 1]++;
            }
            *permuteList[order - 1] = temp;
            permuteList[order - 1]++;
        }
    }
}

void insertConnectedStr(char *str, int aLen, int kPos, int bLen)
{
    permute(&str[kPos], aLen + bLen - kPos + 1, aLen - kPos + 1);
}

int main()
{
    char buffer[LENGTH];
    int a, b;
    a = getStr(buffer);
    b = getStr(&buffer[a + 1]);

    char k;
    scanf("%c", &k);

    insertConnectedStr(buffer, a, findK(buffer, k), b);
    puts(buffer);
}
