#include<stdio.h>
#define SalerNum 4
#define ProductNum 5

void cleanTable(float a[ProductNum + 1][SalerNum + 1]);
void addRecord(float a[ProductNum + 1][SalerNum + 1]);
void outputTable(float a[ProductNum + 1][SalerNum + 1]);

int main()
{

    float table[ProductNum + 1][SalerNum + 1];
    cleanTable(table);
    
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
	addRecord(table);
/*
    for(int i = 0; i < SalerNum; i++)
	table[ProductNum][SalerNum] += table[ProductNum][i];
*/  
    outputTable(table);

    return 0;
}

void cleanTable(float a[ProductNum + 1][SalerNum + 1])
{
    for(int i = 0; i <= ProductNum; i++)
	for(int j = 0; j <= SalerNum; j++)
	    a[i][j] = 0;
}

void addRecord(float a[ProductNum + 1][SalerNum + 1])
{
    int saler, product;
    float revenue;
    scanf("%d%d%f", &saler, &product, &revenue);
    a[product - 1][saler - 1] += revenue;
    a[product - 1][SalerNum] += revenue;
    a[ProductNum][saler - 1] += revenue;
    
    a[ProductNum][SalerNum] += revenue;
}

void outputTable(float a[ProductNum + 1][SalerNum + 1])
{
    for(int i = 0; i <= ProductNum; i++)
    {
	for(int j = 0; j <= SalerNum; j++)
	{
	    printf("%.1f\t", a[i][j]);
	}
	printf("\n");
    }
}
