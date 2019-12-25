#include <stdio.h>

int seperateBinarySearch(int a[], int s, int e, int target)
{
    if(s > e)
    {
        return -1;
    }
    else
    {
        int m = (s + e) / 2;
        if(a[m] == target)
        {
            return m;
        }
        else if(a[m] < target || target < a[s])
        {
            return seperateBinarySearch(a, m + 1, e,     target);
        }
        else
        {
            return seperateBinarySearch(a, s,     m - 1, target);
        }   
    }
}

int main()
{
    int n;
    scanf("%d,", &n);

    int a[100];
    for(int i = 0; i < n; i++)
    {
        scanf("%d,", &a[i]);
    }

    int target;
    scanf("%d", &target);

    printf("%d", seperateBinarySearch(a, 0, n - 1, target));

    return 0;
}