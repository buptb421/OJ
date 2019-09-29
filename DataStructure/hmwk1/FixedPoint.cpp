#inclide<iostream>

#define LENTH 100

using namespace std;

int findFixPoint(int a[], int s, int e)
{
    int mid = (e - s) / 2;
    if(e - s > 1)
    {
	if(a[mid] > mid + 1)
	{
	    return findFixPoint(a, s, mid - 1);
	}
	else
	{
	    return findFixPoint(a, mid, e)
	}
    }
    else
    {
	if(e == s)
	{
	    if(a[e] == e + 1)
	    {
		return e;
	    }
	    else
	    {
		return -1;
	    }
	}
	else
	{
	    if(a[e] == e + 1)
	    {
		return e;
	    }
	    else
	    {
		if(a[s] == s + 1)
		{
		    return s;
		}
		else
		{
		    return -1;
		}
	    }
	}
    }
}

int main()
{
    int n;
    int a[LENGTH];

    cin >> n;
    for(int i = 0; i < n; i++)
    {
	cin >> a[i];
    }
    cout << findFixPoint(a, 0, n);
    return 0;
}
