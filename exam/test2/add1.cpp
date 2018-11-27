#include<stdio.h>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    
    int t1, t2, t3, t4;
    for(t2 = 0; (t2 * 2) <= n && t2 <= m; t2 = t2 + 1)
    {
	for(t3 = 0; (t2 + t3) <= m && (t3 * 3 + t2 * 2) <= n; t3 = t3 + 1)
	{
	    t4 = n - t2 - 2 * t3 - m;
	    if(t4 % 3 == 0)
	    {
		t4 = t4 / 3;
		t1 = m - t2 - t3 - t4;
		if(t4 >= 0 && t1 >= 0)
		    printf("%d %d %d\n", t2, t3, t4);
	    }
	}
    }
    return 0;
}
