#include<stdio.h>

void inputData(int data[],int elementCount);
void SelectSort(int a[],int n);
int findMin(int data[], int startLoc, int endLoc);
void outputData(int data[],int elementCount);

int main()
{
    int n, a[1000];
    scanf("%d", &n);
    inputData(a, n);

    SelectSort(a, n);
    
    return 0;
}

void inputData(int data[],int elementCount)
{
    for(int i = 0; i < elementCount; i++)
	scanf("%d", &data[i]);
}

void SelectSort(int a[],int n)
{
    int swapLoc, temp;
    for(int i = 0; i < n - 1; i++)
    {
	swapLoc = findMin(a, i, n - 1);
	if(swapLoc != i)
	{
	    temp = a[i];
	    a[i] = a[swapLoc];
	    a[swapLoc] = temp;
	}
	outputData(a, n);
    }
}

int findMin(int data[], int startLoc, int endLoc)
{
    int min = data[startLoc], minLoc = startLoc;
    for(int i = startLoc + 1; i <= endLoc; i++)
	if(data[i] < min)
	{
	    min = data[i];
	    minLoc = i;
	}
    return minLoc;
}

void outputData(int data[],int elementCount)
{
    for(int i = 0; i < elementCount; i++)
	printf("%d ", data[i]);
    printf("\n");
}
