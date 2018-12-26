#include<stdio.h>

struct s {
    int a[5];
};

void outputArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    struct s
	a = {.a = {1, 2, 3, 4, 5}},
	b = {.a = {6, 7, 8, 9, 0}},
	c;
    c = b;
    b = a;
    a = c;

    outputArray(a.a, 5);
    outputArray(b.a, 5);
    outputArray(c.a, 5);
}
