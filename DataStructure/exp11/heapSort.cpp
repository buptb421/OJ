#include<iostream>

using namespace std;

int c2p(int c) // children to parent
{
    return (c - 1) / 2;
}

int p2l(int p) // parent to left
{
    return 2 * p + 1;
}
/*
int p2r(int p) // parent to right
{
    return 2 * p + 2;
}
*/

int bigChild(int a[], int n, int p)
{
    int c = p2l(p);
    if(c < n - 1 && a[c] < a[c + 1])
    {
        c++;
    }
    return c;
}

int getArray(int a[])
{
    char s[100];
    cin.getline(s, 100);
    int count = 0;
    for(int i = 0, num = 0; i < 100 && s[i] != '\0'; i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            num = num * 10 + s[i] - '0';
        }
        else if(s[i] == ',')
        {
            a[count] = num;
            count++;
            num = 0;
        }
    }
    return count;
}

void displayArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ',';
    }
    cout << endl;
}
/*
void iter_displayHeap(int a[], int n, int p, int level)
{
    if(p < n)
    {
        for(int i = 0; i < level; i++)
        {
            cout << "  ";
        }
        cout << '[' << p << ']' << a[p] << endl;
        p = p2l(p);
        level++;
        iter_displayHeap(a, n, p, level);
        iter_displayHeap(a, n, p + 1, level);
    }
}

void displayHeap(int a[], int n, int count)
{
    cout << "Loop: " << count << '{' << endl;
    iter_displayHeap(a, n, 0, 1);
    cout << '}' << endl;
}
*/
void maxheapdown(int a[], int s, int e
/*begin{DEBUG}*
    ,int n
/*end(DEBUG)*/
)
{
    /* begin{DEBUG}*
        cout << "pos: [" << s << " - " << e << "]{" << endl << "  Before:" << endl;
        iter_displayHeap(a, n, 0, 1);
    /* end{DEBUG}*/
    int temp = a[s], ind = s;

    const int parent = 0;
    const int child = 1;
    for(int pos[2] = {s, bigChild(a, e + 1, s)};
        pos[child] <= e && temp <= a[pos[child]]; 
        pos[child] = bigChild(a, e + 1, pos[parent]))
    {
        ind = pos[child];
        a[pos[parent]] = a[pos[child]];
        pos[parent] = pos[child];
    }
    a[ind] = temp;
    /*begin{DEBUG}*
        cout << endl << "  After:" << endl;
        iter_displayHeap(a, n, 0, 1);
        cout << '}' << endl;
    /*end(DEBUG)*/
}

void heapsort(int a[], int n, int k)
{
    int temp, count;
    count = 0;
    count++;
    //displayHeap(a, n, count);
    for(int i = n / 2 - 1; i >= 0; i--)
    {
      	maxheapdown(a, i, n - 1/*begin{DEBUG}*,n/*end(DEBUG)*/);
    }
    if(k == count)
    {
    	displayArray(a, n);
        //displayHeap(a, n, count);
	}
	
    for(int i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        count++;
        //displayHeap(a, i, count);
        maxheapdown(a, 0, i-1/*begin{DEBUG}*,n/*end(DEBUG)*/);
		
        if(k == count)
        {
            displayArray(a, n);
            //displayHeap(a, i, count);
        }
    }
}

int main()
{
    
    int a[100];
    int n = getArray(a);
    
    /*
    int a[100] = {31, 41, 59, 26, 53, 58, 97, };
    int n = 7;
    */
    int k = 0;
    cin >> k;

    heapsort(a, n, k);

    return 0;
}
