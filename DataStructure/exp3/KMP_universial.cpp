#include<iostream>
#include<cstring>
using namespace std;

void displayMatchPos(char str[], int strL, char pattern[], int patL, int i, int j)
{
    cout << '{' << i << endl;
    for(int k = 0; k < strL; k++)
    {
        if(k == i)
        {
            cout << '|' << str[k] << '|';
        }
        else
        {
	    cout << str[k];
	}
    }
    cout << endl;
   
    if(j == -1)
    {
	for(int k = 0; k < i; k++)
	{
	    cout << ' ';
	}
        cout << "| |";
    }
    else
    {
	for(int k = j; k < i; k++)
	{
	    cout << ' ';
	}
    }
    for(int k = 0; k < patL; k++)
    {
	if(k == j)
	{
	    cout << '|' << pattern[k] << '|';
	}
	else
	{
	    cout << pattern[k];
	}
    }
    cout << endl << '}' << j << endl << endl;
} 


void KMP_stream(char s[], int ls, int match[], char t[], int lt, int next[])
{
    int i = -1, j = -1;
    while (i < ls)
    {
	if(j == -1 || s[i] == t[j])
        {
        	
	    i++;
	    j++;
	    displayMatchPos(s, ls, t, lt, i, j);
	    match[i] = j;
        }
	else
	{
	    j = next[j];
	    displayMatchPos(s, ls, t, lt, i, j);	
	}
    }
}

void getNext(char t[], int lt, int next[])
{
    next[0] = -1;
    KMP_stream(t + 1, lt - 1, next + 1, t, lt, next);
}

int main()
{
	
    char s[201];
    cin.getline(s, 201);
    int ls = strlen(s);
	
    char t[21];
    cin.getline(t, 21);
    int lt = strlen(t);
	
    int next[21];
    getNext(t, lt, next);
    for(int i = 0; i < lt; i++)
    {
	cout << next[i] + 1 << ',';
    }
    cout << endl;
	
    int match[201];
    KMP_stream(s, ls, match, t, lt, next);

    int count = 0;
    for(int i = 0; i <= ls; i++)
    {
	if(match[i] >= lt)
	{
	    cout << i - lt + 1 << endl;
	    count++;
	}
    }
    if(count == 0)
    {
	cout << -1 << endl;
    }
	
    return 0;
}
