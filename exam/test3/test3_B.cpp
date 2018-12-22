#include<stdio.h>

void fill(int *p, int m);
void sort(int a[100], int n, int i, int j);

int main()
{
    int n;
    scanf("%d", &n);
    
    int a[100];
    fill(a, n);

    sort(a, n, 0, (n + 1) / 2);
    int sum = 0;
    for(int i = 0; i < (n + 1) / 2; i++)
        sum = sum + (a[i] + 1) / 2;
        
    printf("%d", sum);
    return 0;
}

void fill(int *p, int m)
{
    for(int i = 0; i < m; i++, p++)
        scanf("%d", p);
}

void sort(int a[100], int n, int i, int j)
{
     if(i < j)
     {
          int temp;
          for(int k = i; k < n; k++)
          {
                  if(a[k] < a[i])
                  {
                          temp = a[k];
                          a[k] = a[i];
                          a[i] = temp;
                  }
          }
          sort(a, n, i + 1, j);
     }
}
