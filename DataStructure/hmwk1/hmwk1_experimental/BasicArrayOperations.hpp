#include<iostream>
#include<iomanip>

#include"structure.hpp"

using namespace std;

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
    bool noneZero = true;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            temp[i][j] = getPieceSum(a, i, j);
            if(temp[i][j] == 0)
            {
                noneZero = false;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        {
            for(int j = 0; j < i * 5; j++)
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
		
        for(int j = 0; j < i * 5; j++)
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
            cout << setiosflags(ios::left) << setw(4)<< temp[i][j];
        }
        cout << endl; 
    }
    if(noneZero)
    {
        cout << "The array has no 0 sum continous subsequence." << endl;
    }
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
