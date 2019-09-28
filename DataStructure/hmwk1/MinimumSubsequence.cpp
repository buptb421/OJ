#include<iostream>

using namespace std;

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

int getPiece(int n, int a[], int PieceStart, int &PieceEnd) //return the sum of the piece
{
    int i;
    int sum = 0;
    for(i = PieceStart; i < n && (a[i] != 0 || !(a[PieceStart] > 0 ^ a[i] > 0)); i++)
    {
        sum += a[i];
    }
    if(sum != 0)
    {
        PieceEnd = i - 1;
        return sum;
    }
    else
    {
        while(i < n && a[i] == 0)
        {
            i++;
        }
        PieceEnd = i - 1;
        return sum;
    }
}

int mergePiece(int n, int a[], int p1_s, int p1_e, int p1_sum, )
{
    if(abs())
}

void process(int n, int a[])
{

}

int main()
{
    int a[100];
    int n = getArray(a); 
    for(int i = 0; i < n; i++)
    {

    }
}