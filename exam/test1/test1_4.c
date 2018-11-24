#include<stdio.h>
//#include<stdlib.h>

int main()
{
    int colum, row;
    int rowlenth;
    int i, j, k;
       
    scanf("%d%d", &colum, &row);
    rowlenth = 3 * row + 1;
    
    for(i = 0; i <= colum; i++)
    {
        if(i > 0)
        {
            for(j = 1; j <= row; j++)
                printf("*/\\");
            printf("*\n");
            for(j = 1; j <= row; j++)
                printf("*\\/");
            printf("*\n");
        }
        for (k = 1; k <= rowlenth; k++)
            printf("*");
        printf("\n");
    }
    
//    system("pause");
    return 0;
}
