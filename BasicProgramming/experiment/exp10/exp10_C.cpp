#include<stdio.h>

void swapDatMap(int data[], int mapping[], const int i, const int j);
void sort(int data[], int mapping[], const int n);
/*
//some real operation
int countLoop(int a[], int start);
void loopexchange();
*/


int main()
{
    int n;
    scanf("%d", &n);

    int data[100][100];
    int sum[100];
    for(int i = 0; i < n; i++)
    {
	sum[i] = 0;
	for(int j = 0; j < n; j++)
	{
	    scanf("%d", &data[i][j]);
	    sum[i] += data[i][j];
	}
    }
    
    int mapping[100];
    for(int i = 0; i < n; i++)
	mapping[i] = i;

    sort(sum, mapping, n);

    for(int i = 0; i < n; i++)
    {
	for(int j = 0; j < n; j++)
	    printf("%d ", data[mapping[i]][j]);
	printf("\n");
    }

    return 0;
}

void swapDatMap(int data[], int mapping[], const int i, const int j)
{
    int tempd = data[i], tempm = mapping[i];
    data[i] = data [j];
    data[j] = tempd;
    mapping[i] = mapping[j];
    mapping[j] = tempm;
}

void sort(int data[], int mapping[], const int n)
{
    for(int i = 0; i < n; i++)
	for(int j = 0; j < n - 1; j++)
	    if(data[j] > data[j + 1])
		swapDatMap(data, mapping, j, j + 1);
}
