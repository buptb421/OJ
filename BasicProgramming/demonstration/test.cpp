#include<stdio.h>

void outD1(int a[]);
void outD2(int a[][9]);
void outD3(int a[][9][9]);
void init(int a[][9][9]);

int main()
{
	int a[9][9][9];
	init(a);
	
	int *p = a[5][5];
	outD1(p);
	printf("D1\n");
	
	int (*q)[9] = a[5];
	outD2(q);
	printf("D2\n");

	int (*r)[9][9] = a;
	outD3(r);
//	outD3(a); 
} 

void init(int a[][9][9])
{
	int count = 0;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			for(int k = 0; k < 9; k ++)
			{
				a[i][j][k] = count;
				count ++;
			}
		}
	}
}

void outD1(int a[])
{
	for(int i = 0; i < 9; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void outD2(int a[][9])
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void outD3(int a[][9][9])
{
	for(int i = 0; i < 9; i++)
	{
		printf("page %d:\n", i);
		for(int j = 0; j < 9; j++)
		{
			for(int k = 0; k < 9; k ++)
				printf("%5d ", a[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}
