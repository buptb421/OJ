#include<iostream>

using namespace std;

typedef struct SingleMan{
    int next;
} manNode;

void displayRing(manNode man[], int lastManID)
{
    int securityCount = 101;
	int tempID = man[lastManID].next;
	while(tempID != lastManID && securityCount >= 0)
	{
		cout << tempID << ' ';
		tempID = man[tempID].next;
        securityCount--;
	}
	cout << lastManID << endl;
}

void jumpMMan(manNode man[], int &lastManID, int m) // as long as the ring exist, it will work.
{
    int tempID = lastManID;
    for(int i = 0; i < m; i++)
    {
        tempID = man[tempID].next;
    }

    if(tempID >= 0)
    {
        lastManID = tempID;
    }
    else
    {
        cout << "jump error." << endl;
    }
}

void deletNextMan(manNode man[], int &lastManID) // WARNING! this function only delet in a ring of > 1 elements, when there is <= 1 element it will do nothing.
{
    int tempID = man[lastManID].next; // ID of previous man
    if(lastManID != tempID && tempID >= 0)
    {
        man[lastManID].next = man[tempID].next;
        man[tempID].next = -1;
    }
}

int main()
{
    int m, n;
    char comma;
    manNode man[101];
    int output[100];
    int lastManID;

    cin >> n >> comma >> m;

    for(int i = 0; i < n; i++)
    {
        man[i].next = i + 1; // 0 ~ (n - 1) th man in chain
    }
    man[n].next = 0; // n th man make chain a loop 

    lastManID = n; // potato is always in the hand of the man next to the last man.

    for(int i = 0; i <= n; i++)
    {
        if(i != 0) // out put the previous man if is not the init loop.
        {
        	output[i - 1] = man[lastManID].next;
        }
        // do the procedure as follow:
        //displayRing(man, lastManID);
        deletNextMan(man, lastManID);
        jumpMMan(man, lastManID, m);
    }
    
    for(int i = 0; i < n - 1; i++)
    {
    	cout << output[i] << ',';
	}
	cout << output[n - 1];
    return 0;
}

