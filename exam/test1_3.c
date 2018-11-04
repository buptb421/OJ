#include<stdio.h>
//#include<stdlib.h>

int main()
{
    int c, c3, c5, c7;
    int a;
    float p3, p5, p7;
    
    c = 0;
    c3 = 0;
    c5 = 0;
    c7 = 0;
    
    for(;;)
    {
        scanf("%d", &a);
        if(a == 0)
            break;
        else 
        {
            c = c + 1;
            if((a % 3) == 0 && (a % 5) != 0 && (a % 7) != 0)
                c3 = c3 + 1;
            else if((a % 3) != 0 && (a % 5) == 0 && (a % 7) != 0)
                c5 = c5 + 1;
            else if((a % 3) != 0 && (a % 5) != 0 && (a % 7) == 0)
                c7 = c7 + 1;
        }
    }
    
    p3 = 100.0 * c3 / c;
    p5 = 100.0 * c5 / c;
    p7 = 100.0 * c7 / c;
    
    printf("%.2f%%\n", p3);
    printf("%.2f%%\n", p5);
    printf("%.2f%%\n", p7);
    
//    system("pause");
    return 0;
}
