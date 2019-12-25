#include <iostream>
#include <utility>

#define NUM 10
#define CUTOFF 3

using namespace std;

int medianThree(int a[], int left, int right)// A hand-made sort, are you serious?
{
    int center = (left + right) / 2;
    if (a[left] > a[center])
    {
        swap(a[left], a[center]);
    }
    if (a[left] > a[right])
    {
        swap(a[left], a[right]);
    }
    if (a[center] > a[right])
    {
        swap(a[center], a[right]);
    }   
    swap(a[center], a[right - 1]);
    return a[right - 1];
}

void displayQs(int a[], int left, int right)
{
    cout << "Qsort(" << left << ',' << right << "):";
    for (int i = 0; i < NUM; i++)
    {
        cout << a[i] << ',';
    }
    cout << endl;
}
void displayIs(int a[], int left, int right)
{
    cout << "insert(" << left << ',' << right - left + 1 << "):";
    for (int i = 0; i < NUM; i++)
    {
        cout << a[i] << ',';
    }
    cout << endl;
}

void insertSort(int a[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        for (int j = i; j > left && a[j - 1] > a[j]; j--)
        {
            swap(a[j - 1], a[j]);
        }
    }
}

void quickSort(int a[], int left, int right)
{
    if (right - left >= CUTOFF)
    {
        int pivot = medianThree(a, left, right);
        int i = left, j = right - 1;
        for(;;)
        {
            while(a[++i] < pivot){}
            while(a[--j] > pivot){}
            if(i < j)
            {
                swap(a[i], a[j]);
            }	
            else
            {
                break;
            } 	
    	}
        swap(a[i], a[right - 1]);
        displayQs(a, left, right);

        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    else
    {
        insertSort(a, left, right);
        displayIs(a, left, right);
    }
}

void myQsort(int a[], int n, int k)
{
    int left = 0, right = n - 1;
    if (right - left >= CUTOFF)
    {
        swap(a[k], a[right]);
        int pivot = a[right];
        int i = left, j = right - 1;
        swap(a[i], a[j]);
        do
        {
            swap(a[i], a[j]);
            while (a[i] < pivot)
            {
                i++;
            }
            while (a[j] > pivot)
            {
                j--;
            }
        }while(i < j);
        swap(a[i], a[right]);

        displayQs(a, left, right);

        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    else
    {
        insertSort(a, left, right);
        displayIs(a, left, right);
    }
}

int main()
{
    /*
    int a[] = {49, 38, 65, 97, 76, 13, 27, 50, 2, 8};

    int k;
    cin >> k;
    
    myQsort(a, NUM, k);
    */
    int a[] = {20,38,24,23,26,32,21,29,38,28};
    
    quickSort(a, 0, 9);

    return 0;
}