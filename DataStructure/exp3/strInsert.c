#include<stdio.h>
#include<string.h>

#define LENGTH 1000

int getStr(char *w)
{
    gets(w);
    return strlen(w);
}


int findK(char *str, char k)
{
    int i = 0;
    while(*str != k && *str != '\0')
    {
	str++;
	i++;
    }
    return i;
}

/* In a group of such permutation:
 * every element, with position 'pos' is rearranged to position addressMap(size, i, pos)
 * addressMap(size, i, pos) = 
 * { 
 *     pos + (size - i), o ~ (i -1)    ;
 *     pos - i         , i ~ (size - 1);
 * {
 */
int exchangeMap(int size, int i, int pos)
{
    if(pos < i)
    {
	return pos + size - i;
    }
    else
    {
	return pos - i;
    }
}

int inverseI(int size, int i)
{
    return size - i;
}

void permute(char *strHead, int size, int i) // strHead is the pointer to the keyword k, where we start to exchange the char.
{
    int cycle_size = 0, cycle_start = 0, nowPos = 0, newPos;
    char temp;
    /*
    // BEGIN{DEBUG}
    printf("size: %d, i: %d\n==========\n", size, i);
    // END{DEBUG}
    */
    do
    {
	/*
	// BEGIN{DEBUG}
	printf("Cycle, start: %d\n", cycle_size);
	// END{DEBUG}
	*/
	nowPos = cycle_start;
	newPos = exchangeMap(size, inverseI(size, i), nowPos);
	temp = strHead[cycle_start];
	do
	{
	    if(cycle_start == 0)
	    {
		cycle_size++;
	    }
	    
	    if(newPos == cycle_start)
	    {
		strHead[nowPos] = temp;
		/*
		// BEGIN{DEBUG}
		printf("[%d] <- [%d], ", nowPos, newPos);
		// END{DEBUG}
		*/
	    }
	    else
	    {
		strHead[nowPos] = strHead[newPos];
		/*
		// BEGIN{DEBUG}
		printf("[%d] <- [%d], ", nowPos, newPos);
		// END{DEBUG}
		*/
	    }
	    
	    nowPos = newPos;
	    newPos = exchangeMap(size, inverseI(size, i), nowPos);
	}while(nowPos != cycle_start);
	/*
	// BEGIN{DEBUG}
	printf("\n");
	for(int j = 0; j < size; j++)
	{
	    if(strHead[j] >= 40 && strHead[j] <= 127)
	    {
		printf("%c", strHead[j]);
	    }
	    else
	    {
		printf("[%d]", strHead[j]);
	    }
	}
	printf("\n----------\n");
	// END{DEBUG}
	*/
	cycle_start++;
    }
	while(cycle_start < (size / cycle_size));
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

