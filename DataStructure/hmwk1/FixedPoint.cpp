#include <iostream>

#define LENGTH 100

using namespace std;

int getArray(int a[])
{
    int n;
    cout << "Please enter the length of the array, the number should be a nature number below" << LENGTH  << '.' << endl;
    cin >> n;
    cout << "Please input Array of " << n << " integers." << endl;
    for(int i = 0; i < 100 && i < n; i++)
    {
        cin >> a[i];
    }
    return n;
}

int findFixPoint(int a[], int s, int e)
{
	int mid = (e - s) / 2;
	if (e - s > 1)
	{
		if (a[mid] > mid + 1)
		{
			return findFixPoint(a, s, mid - 1);
		}
		else
		{
			return findFixPoint(a, mid, e);
		}
	}
	else
	{
		if(a[e] == e + 1)
		{
			return e + 1;
		}
		else if(a[s] == s + 1)
		{
			return s + 1;
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	int n;
	int a[LENGTH];
	int fixPoint;

	n = getArray(a);
	fixPoint = findFixPoint(a, 0, n);

	if(fixPoint) // 0 : there is no such fix point, 1~n : the fix point is this.
	{
		cout << "The fix point is " << fixPoint << '.' << endl; 
	}
	else
	{
		cout << "There is no fix point." << endl;
	}
	
	return 0;
}
