#include<iostream>

using namespace std;

void getArray(int a[], int n)
{
    char comma;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> comma;
    }
}

void displayArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << ',';
    }
    cout << '\n';
}

int locateSmallest(int a[], int n, int start)
{
    int sml, s_pos;
    s_pos = start;
    sml = a[s_pos];
    for(int i = start + 1; i < n; i++)
    {
        if(a[i] < sml)
        {
            sml = a[i];
            s_pos = i;
        }
    }
    return s_pos;
}

void selectSort(int a[], int n)
{
    int temp, s_pos;
    for(int i = 0; i < n - 1; i++)
    {
        s_pos = locateSmallest(a, n, i);
        //cout << "[" << s_pos << "]" << a[s_pos] << endl;
        temp = a[i];
        a[i] = a[s_pos];
        a[s_pos] = temp;
        displayArray(a, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    getArray(a, n);
    //displayArray(a, n);
    selectSort(a, n);
    return 0;
}
