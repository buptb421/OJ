#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int i, j;
    int nd10 = n / 10;
    for(i = 1, j = 1; nd10 >= i;i = i * 10, j = j + 1);

    int k;
    int start = 0, end = 0;
    int halfj = j / 2;
    for(k = 1; k <= halfj && start != end; k = k + 1)
    {
        start = n / i;
        end = n - 10 * nd10;
        if(start != end)
        {
            printf("No\n");
        }
	else
	{
	    i = i / 10;
	    n = nd10 - start * i;
	    nd10 = n / 10;
	    i = i / 10;
	}
    }
    if (start == end)
        printf("Yes\n");
    return 0;
}
