/* This KMP start from 0, just as the array we usually use.
 * FUCK THE DATA STRUCTURE TEXT BOOK!
 */
#include<iostream>
#include<string.h>

using namespace std;

void Get_next(char t[], int next[], int lent)
{
	int j = 0, k = -1;

	next[j] = k;
	while(j < lent - 1)
	{
		if((k == -1) || (t[j] == t[k]))
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

int StrIndex_KMP(char s[], char t[], int pos, int lens, int lent, int next[])
{
	int i = pos;
	int j = 0;
	while ((0 < lent - j) && (lent - j <= lens - i)) // maybe we can track lent - j instead of j 
	{
		if ((j == -1) || (s[i] == t[j]))
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= lent)
	{
		return (i - lent);
	}
	else 
	{
		return -1;
	}
}

int main()
{
	char s[201];
	cin.getline(s, 201);
	int lens = strlen(s);

	char t[21];
	cin.getline(t, 21);
	int lent = strlen(t);
	
	int next[21];
	Get_next(t, next, lent);
	for(int i = 0; i < lent; i++)
	{
		cout << next[i] + 1 << ',';
	}
	cout << endl;

	int j = 0, count = 0; 
	while(j != -1 && j < lens)
	{
		j = StrIndex_KMP(s, t, j, lens, lent, next);

		if(j != -1)
		{	
			cout << j + 1 << endl;
			j++;
			count++;
		}
	}
	if(count == 0)
	{
		cout << -1 << endl;
	}

	return 0;
}





