#include<iostream>
#include<iomanip>

#define NUM_WIDTH 4
#define LENGTH 100

using namespace std;

typedef struct function{
    int s;
    int e;
    int sum;
}piece;

piece setPiece(int s, int e, int sum)
{
    piece p;
    p.s = s;
    p.e = e;
    p.sum = sum;
    return p;
}

bool isPieceRight(piece p)
{
    if(piece.e >= piece.s)
    {
        return true;
    }
    else
    {
        return false;
    }  
}

void displayPiece(int a[], int start, int end)
{
    int sum = 0;
    for(int i = start; i <= end; i++)
    {
        cout << a[i] << ' ';
        sum += a[i];
    }
    cout << endl << "The sum is " << sum << '.' << endl;
}
int getPieceSum(int a[], int start, int end)
{
    int sum = 0;
    for(int i = start; i <= end; i++)
    {
        sum += a[i];
    }
    return sum; 
}

void DisplayPieceSumMatrix(int n, int a[])
{
    int temp[100][100]; 
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            temp[i][j] = getPieceSum(a, i, j);
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        {
            for(int j = 0; j < i * (NUM_WIDTH + 1); j++)
            {
                cout << ' ';
            }
            for(int j = i; j < n; j++)
            {
                cout << ' ';
                if(temp[i - 1][j] < temp[i][j])
                {
                    cout << "AA";
                }
                else if(temp[i - 1][j] > temp[i][j])
                {
                    cout << "VV";
                }
                else
                {
                    cout << "||";
                }
                cout << "  ";
            }
            cout << endl;
        }
		
        for(int j = 0; j < i * (NUM_WIDTH + 1); j++)
        {
            cout << ' ';
        }
        for(int j = i; j < n; j++)
        {
            if(j > i)
            {
                if(temp[i][j - 1] < temp[i][j])
                {
                    cout << '<';
                }
                else if(temp[i][j - 1] > temp[i][j])
                {
                    cout << '>';
                }
                else
                {
                    cout << '=';
                }
            }
            cout << setiosflags(ios::left) << setw(NUM_WIDTH)<< temp[i][j];
        }
        cout << endl; 
    }
}

int getArray(int a[])
{
    int n;
    cout << "Please enter the length of the array." << endl;
    cin >> n;
    cout << "Please input Array of " << n << " integers." << endl;
    for(int i = 0; i < 100 && i < n; i++)
    {
        cin >> a[i];
    }
    return n;
}

piece getPiece(int n, int a[], int start, int step)
{
    int i = start;
    piece p = setPiece(0,0,0);
    if(step > 0)
    {
        step = 1;
    }
    else if(step < 0)
    {
        step = -1;
    }
    else
    {
        cout << "[Wrong step, it can't be 0]" << endl;
        return p;
    }

    while(i < n && i >= 0 && ((a[start] > 0 && a[i] > 0) || (a[start] < 0 && a[i] < 0) || (a[start] == 0 && a[i] == 0 )))
    {
        p.sum += a[i];
        i += step;
    }
    i -= step;

    if(i > start)
    {
        p.s = start;
        p.e = i;
    }
    else
    {
        p.s = i;
        p.e = start;
    }
    return p;
}

bool isRightOrdered(piece first, piece second, int step) // >
{
    if((first.sum > second.sum && step > 0) || (first.sum < second.sum && step < 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isLeftOrdered(piece first, piece second, int step) // <
{
    if((first.sum > second.sum && step < 0) || (first.sum < second.sum && step > 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isZero(piece first, piece second) // x_n = - x_(n + 1)
{
    if(first.sum == -second.sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isCondensablePiece(piece left, piece mid, piece right)
{
    if(left.e < mid.s && mid.e < right.s && abs(left.sum) > abs(mid.sum) && abs(right.sum) > abs(mid.sum))
    {
        return true;
    }
    else
    {
        return false;
    }
}

piece condensePiece(piece left, piece mid, piece right)
{
   return setPiece(left.s, right.e, left.sum + mid.sum + right.sum); 
}

void findLocalExtream(int n, int a[])
{
    piece p[100];
    int nPiece = 0;
    piece le[100];
    int nLE = 0;

    int prevPloar = 0;
    int prevSum = 0;
    int prevS = 0;
    int prevE = 0;

    for(int i = 0; i < n; i++)
    {
        p[nPiece] = getPiece(n, a, i, 1);
        i = p[nPiece].e;
        nPiece++;
    }
    for(int i = 0; i < nPiece; i++)
    {
        if(p[i].sum == 0)
        {

        }
        else
        {
            if(prevPloar == 0)
            {
                if(p[i].sum > 0)
                {
                    prevPloar = 1;
                }
                else if (p[i].sum < 0)
                {
                    /* code */
                }
                
            }
        }
        
        
    }
}

piece getMergedPiece(int n, int a[], piece now) // When now > right
{
    if(now)
}

piece getMergablePiece(int n, int a[], piece now, piece right) // When now < right, notice there may not be a 'left' but <<<<<< all the way down, s.t. we still call 'now' 'now'
{
    piece left = setPiece(0, 0, 0);
    if()
}

piece iter1(int n, int a[], piece now)
{
    if(now.s > 0)
    {
        piece proceed = getPiece(n, a, now.s - 1, -1);
        if(abs(now.sum) )
    }
    
}

piece iter2(int n, int a[], piece mid, piece right)
{
    if(mid.s > 0)
    {
        piece left = getPiece(n, a, mid.s)
    }
}