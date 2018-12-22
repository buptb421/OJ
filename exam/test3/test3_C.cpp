#include<stdio.h>

void inputM(int m, int n, int l[10][10]);
void inputO(int t, int opex[20], int opey[20]);

int inRange(int m, int n, int x, int y);
void turn_u_r(int m, int n, int l[10][10], int x, int y);
void turn_u_l(int m, int n, int l[10][10], int x, int y);
void turn_d_r(int m, int n, int l[10][10], int x, int y);
void turn_d_l(int m, int n, int l[10][10], int x, int y);
void turn_s(int l[10][10], int x, int y);

void outputM(int m, int n, int l[10][10]);

int main()
{
    int m, n;
    int l[10][10];
    scanf("%d%d", &m, &n);
    inputM(m, n, l);
    
    int nOpe;
    int opex[20], opey[20];
    scanf("%d", &nOpe);
    inputO(nOpe, opex, opey);
    
    for(int i = 0; i < nOpe; i++)
    {
            turn_u_r(m, n, l, opex[i], opey[i]);
            turn_u_l(m, n, l, opex[i], opey[i]);
            turn_d_r(m, n, l, opex[i], opey[i]);
            turn_d_l(m, n, l, opex[i], opey[i]);
            turn_s(l, opex[i], opey[i]);
    }
    
    outputM(m, n, l);
    
//    system("pause");
    
    return 0;
}

void inputM(int m, int n, int l[10][10])
{
     for(int i = 0; i < m; i++)
     {
             for(int j = 0; j < n; j++)
             {
                     scanf("%d", &l[i][j]);
             }
     }
}

void inputO(int nOpe, int opex[20], int opey[20])
{
     for(int i = 0; i < nOpe; i++)
     {
            scanf("%d%d", &opex[i], &opey[i]);
            opex[i]--;
            opey[i]--;
     }
}

int inRange(int m, int n, int x, int y)
{
    if(x >= 0 && x < m && y >= 0 && y < n)
         return 1;
    else
        return 0;    
}

int turn(int state)
{
    if(state == 0)
        return 1;
    else
        return 0;   
}

void turn_s(int l[10][10], int x, int y)
{
     l[x][y] = turn(l[x][y]);     
}
void turn_u_r(int m, int n, int l[10][10], int x, int y)
{
     if(inRange(m, n, x + 1, y - 1))
         turn_s(l, x + 1, y - 1);
}
void turn_u_l(int m, int n, int l[10][10], int x, int y)
{
     if(inRange(m, n, x - 1, y - 1))
         turn_s(l, x - 1, y - 1);
}
void turn_d_r(int m, int n, int l[10][10], int x, int y)
{
     if(inRange(m, n, x + 1, y + 1))
         turn_s(l, x + 1, y + 1);     
}
void turn_d_l(int m, int n, int l[10][10], int x, int y)
{
     if(inRange(m, n, x - 1, y + 1))
	 turn_s(l, x - 1, y + 1);   
}


void outputM(int m, int n, int l[10][10])
{
     for(int i = 0; i < m; i++)
     {
             for(int j = 0; j < n - 1; j++)
             {
                     printf("%d ", l[i][j]);
             }
             printf("%d\n", l[i][n - 1]);
     }
}
