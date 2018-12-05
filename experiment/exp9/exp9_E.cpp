#include<stdio.h>

int data[2000000], toseek[100000];

int BinarySearch(int a[], int n, int key);

void inputData(int a[], int n)
{
    for(int i = 0; i < n; i++)
	scanf("%d", &a[i]);
}

int main()
{
    int n, m;
    
    scanf("%d", &n);
    scanf("%d", &m);

    inputData(data, n);
    inputData(toseek, m);
    
    for(int i = 0; i < m; i++)
	printf("%d ", BinarySearch(data, n, i));
    printf("\n");

    return 0;
}

int BinarySearch(int a[],int n,int key)
{
    int startLoc = 0, endLoc = n - 1, mid = (startLoc + endLoc) / 2;
    while(endLoc - startLoc > 2)
    {
	if(a[mid] < toseek[key])
	    startLoc = mid;
	else
	    endLoc = mid;
	mid = ((startLoc + endLoc) / 2);
    }
    for(int i = startLoc; i <= endLoc; i++)
    {
	if(a[i] == toseek[key])
	    return i;
    }
    return -1;
}
