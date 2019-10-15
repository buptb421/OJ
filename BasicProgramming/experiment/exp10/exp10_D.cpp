#include<stdio.h>

void carryforward(int a[], int i, int j);

void tocode(int o[], int e[], int n);
void decode(int e[], int o[], int n);

int main()
{
    int in[100], out[100];
    
    int n;
    scanf("%d", &n);
    
    int mode;
    scanf("%d", &mode);
    
    for(int i = 0; i < n; i++)
	scanf("%d", &in[i]);
    
    if(mode == 1)
	tocode(in, out, n);
    else
	decode(in, out, n);
    
    for(int i = 0; i < n; i++)
	if(i < n - 1)
	    printf("%d ", out[i]);
	else
	    printf("%d\n", out[i]);
    
    return 0;
}

void tocode(int o[], int e[], int n)
{
    for(int i = 0; i < n; i++)
    {
	e[i] = 0;
	for(int j = 0; j <= i; j++)
	    if(o[j] < o[i])
		e[i]++;
    }
}

void carryforward(int a[], int i, int j)// Carries the i th elem to j th elem, while put back all elem between them 1 step.
{
    int temp = a[i];
    for(int index  = i; index < j; index++)
	a[index] = a[index + 1];
    a[j] = temp;
}

void decode(int e[], int o[], int n)
{
    for(int i = 0; i < n; i++)
	o[i] = n - i - 1;
    // Init the origin to {n-1, .. , 0}, which have code of {0, ... , 0}.
    for(int i = n - 1; i >= 0; i--)
	if(e[i] != 0)
	    carryforward(o, i - e[i], i);
}
