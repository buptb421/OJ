#include<iostream>
#include<cstring>
using namespace std;

void KMP_stream(char s[], int ls, int match[], char t[], int lt, int next[])
{
    int i = 0, j = 0;
    match[i] = j;
    while (i < ls)
	{
        if(j == -1)
        {
        	
            i++;
            j++;
            match[i] = j;
        }
        else if(s[i] == t[j])
        {
            i++;
            j++;
            match[i] = j;
        }
		else
		{
			j = next[j];
		}
	}
}

void getNext(char t[], int lt, int next[])
{
	next[0] = -1;
    KMP_stream(t + 1, lt , next + 1, t, lt, next);
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
