#include <iostream>
#include <new>

using namespace std;

void displayMatrix(int a[], int m, int n)
{
    cout << m << ", " << n << '{' << endl;
    for(int i = 0; i < m; i++)
    {
        cout << "  ";
        for(int j = 0; j < n; j++)
        {
            cout << a[i * n + j] << ", ";
        }
        cout << endl;
    }
    cout << '}' << endl;
}

void getMatrixLine(int a[], int n, int s)
{
    char comma;
    for(int i = 0; i < n; i++)
    {
        cin >> a[s + i] >> comma;
    }
}

void getMatrix(int a[], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        getMatrixLine(a, n, n * i);
    }
}

bool FoundWhenBinarySearch(int a[], int s, int e, int target)
{
    if(s > e)
    {
        return false;
    }
    else
    {
        int m = (s + e) / 2;
        if(a[m] == target)
        {
            return true;
        }
        else if(a[m] > target)
        {
            return FoundWhenBinarySearch(a, s,     m - 1, target);
        }
        else
        {
            return FoundWhenBinarySearch(a, m + 1, e,     target);
        }
    }
}

int main()
{
    char comma;
    int m, n;
    cin >> m >> comma >> n;
    int *a = new int[m * n];
    if(a)
    {
        getMatrix(a, m, n);

        int target;
        cin >> target;

        if(FoundWhenBinarySearch(a, 0, m * n - 1, target))
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
        
        delete[] a;
    }
    else
    {
        cout << "Error." << endl;
    }
    return 0;
}