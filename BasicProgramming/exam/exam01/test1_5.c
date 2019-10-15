#include<stdio.h>
//#include<stdlib.h>

int main()
{
    int c2, c5;
    int n;
    
    c2 = 0;
    c5 = 0;
    n = 1;
    
    do
    {
        /*
        while((n % 10) == 0)
        {
            c2 = c2 + 1;
            c5 = c5 + 1;
            n = n / 10;
        }
        */
        while((n % 5) == 0)
        {
            c5 = c5 + 1;
            n = n / 5;
        }
        while((n % 2) == 0)
        {
            c2 = c2 + 1;
            n = n / 2;
        }
        scanf("%d", &n);    
    }while(n != 0);
    
    if(c2 > c5)
        printf("%d", c5);
    else
        printf("%d", c2);
        
//    system("pause");
    return 0;
}
