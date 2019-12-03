#include <iostream>
#include <new>

using namespace std;

void shellSort(int n, int *p)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i ++)
        {
            int temp = p[i];
            int j;
            for (j = i; j >= gap && p[j - gap] < temp; j -= gap)
            {
                p[j] = p[j - gap];
            }
            p[j] = temp;
        }
        for(int i = 0; i < n; i++)
        {
            cout << p[i] << ',';
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int *p = new int[n];

    if(p)
    {
        char comma;
        for(int i = 0; i < n; i++)
        {
            cin >> p[i] >> comma;
        }

        shellSort(n, p);

        delete[] p;
        return 0;
    }
    else
    {
        cout << "Mem ovfl." << endl;
        return 1;
    }
}
