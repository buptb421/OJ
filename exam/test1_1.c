#include<stdio.h>
//#include<stdlib.h>

int main()
{
    char opr;
    long a, b;

    scanf("%c %ld %ld", &opr, &a, &b);

    if(opr == '+')
        printf("%ld", a + b);
    else if(opr == '-')
        printf("%ld", a - b);
    else if(opr == '*')
        printf("%ld", a * b);
    else
    { 
        if(b != 0)
        {
            if(opr == '%')
                printf("%ld", a % b);
            else if(opr == '/')
                printf("%ld", a / b);
            else 
                printf("error");
        }
        else
            printf("error");
    }
    
//    system("pause");
    return 0;    
}
