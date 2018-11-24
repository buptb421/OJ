#include<stdio.h>
//#include<stdlib.h>

int mypow(int base, int po)
{
    int product = 1;
    for(int i = 1; po >= i; i = i + 1)
        product = product * base;
    return product;                    
}

int isPalindrome(long long num, int len)
{
    int high;
    int low;
    int half = (len + 1) / 2;
    for(int i = 1; i <= half; i = i + 1)
    {
        high = (num / mypow(10, len - i)) % 10;
        low = (num / mypow(10, i - 1)) % 10;
        
        printf("%d %d\n", high, low);
        if(high != low)
            return 0;      
    }
    return 1;
}

int main()
{
    long long num;
    int len;
    scanf("%lld%d", &num, &len);
    if(isPalindrome(num, len))
        printf("Yes\n");
    else
        printf("No\n");
//    system("pause");
    return 0;
}
