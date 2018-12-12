#include<stdio.h>

int main()
{
    int a;
    int row, column;
    scanf("%d%d", &row, &column);
    
    int PeakPos[100], PeakVal[100], ValePos[100], ValeVal[100];
    
    for(int i = 0; i < row; i++)
    {
	for(int j = 0; j < column; j++)
	{
	    scanf("%d", &a);
	    
	    if(i == 0 || a < ValeVal[j])
	    {
		ValeVal[j] = a;
		ValePos[j] = i;
	    }
	    
	    if(j == 0 || a > PeakVal[i])
	    {
		PeakVal[i] = a;
		PeakPos[i] = j;
	    }
	}
    }

    int donthave = 1;
    for(int i = 0; donthave && i < row; i++)
	if(ValePos[PeakPos[i]] == i)
	{
	    printf("The saddle point is (%d,%d)=%d.\n", i, PeakPos[i], PeakVal[i]);
	    donthave = 0;
	}
    
    if(donthave)
	printf("There is no saddle point in the matrix.");
    
    return 0;
}
