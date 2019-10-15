#include<stdio.h>
//#include<stdlib.h>

int main()
{
    int n;
    int mass, dist;
    int price[9];
    int i;
    int overw;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &mass, &dist);
        
        if(mass > 5)
            overw = mass -5;
        else
            overw = 0;
        
        if(dist <= 200)
            price[i] = 6 + overw * 2;
        else if(dist <= 800)
            price[i] = 8 + overw * 4;
        else
            price[i] = 10 + overw * 5; 
    }
    
    for(i = 0; i < n; i++)
        printf("%d\n", price[i]);
        
//    system("pause");
    return 0;
}
