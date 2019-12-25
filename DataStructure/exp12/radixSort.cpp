#include <iostream>
#include <stack>

using namespace std;

#define LEN 20

void displayNum(char str[], int pos_com)// will print a ',' after the number
{
    int to_s;
    for(to_s = pos_com - 1; to_s >= 0 && str[to_s] != ','; to_s--);
    if(to_s != 0)
    {
        to_s++;
    }
    for(int i = to_s; i <= pos_com; i++)
    {
        cout << str[i];
    }
}

void displayAllNum(char str[], int n, int count, int a[])
{
    cout << "Number of num: " << n << ", max digit pos: " << count << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Comma pos: [" << a[i] << "], ";
        displayNum(str, a[i]);
        cout << endl;
    }
}

void displayBucket(char str[], int n, int count, int a[], int next[], int buc[10])
{
    for(int i = 0; i < 10; i++)
    {
        //cout << "In Bucket[" << i << "]{" << endl;
        int p = buc[i];
        while(p >= 0)
        {
            //cout << "  Num[" << p << "] = ";
            displayNum(str, a[p]);
            //cout << endl;
            p = next[p];
        }
        //cout << '}' << endl;
    }
}



char getDigit(char str[], int pos_com, int exp10)
{
    for(int i = pos_com - 1; i >= pos_com - exp10 - 1; i--)
    {
        if(i < 0 || str[i] == ',')
        {
            return 0;
        }
    }
    return str[pos_com - exp10 - 1] - '0';
}

int extract(int n, int next[], int buc[10], int i) // from head
{
    int temp = buc[i];
    buc[i] = next[temp];
    next[temp] = -1;
    return temp;
}

void insert(int next[], int buc[10], int i, int e) // to end
{
    if(buc[i] < 0)
    {
        buc[i] = e;
    }
    else
    {
        int p = buc[i];
        while(next[p] >= 0)
        {
            p = next[p];
        }
        next[p] = e;
    }
}

void radixSort_key(char str[], int n, int a[], int next[], int oldbuc[10], int buc[10], int k)
{
    int temp;
    for(int i = 0; i < 10; i++)
    {
        while(oldbuc[i] >= 0)
        {
            temp = extract(n, next, oldbuc, i);
            insert(next, buc, getDigit(str, a[temp], k), temp);
        }
    }
}

void radixSort(char str[], int n, int count, int a[], int next[], int buc[10], int k)
{
    int tempbuc[10];
    for(int i = 0; i < 10; i++)
    {
        tempbuc[i] = -1;
        buc[i] = -1;
    }
    buc[0] = 0;
    for(int i = 0; i < n - 1; i++)
    {
        next[i] = i + 1;
    }
    next[n - 1] = -1;
    cout << endl;
    for(int i = 0; i < count; i++)
    {
        radixSort_key(str, n, a, next, buc, tempbuc, i);
        for(int j = 0; j < 10; j++)
        {
            buc[j] = tempbuc[j];
            tempbuc[j] = -1;
        }
        if(k == i + 1)
        {
            displayBucket(str, n, count, a, next, buc);
        }
    }
}


int main()
{
    char str[LEN * 6];
    cin.getline(str, LEN * 6);

    int count = 0, n = 0;
    int a[LEN], next[LEN], buc[10];
    for(int i = 0, prev = 0; i < LEN * 6 && str[i] != '\0'; i++)
    {
        if(str[i] == ',')
        {
            a[n] = i;
            prev = i - prev - 1;
            if(prev > count)
            {
                count = prev;
            }
            prev = i;
            n++;
        }
    }

    int k;
    cin >> k;

    radixSort(str, n, count, a, next, buc, k);

    return 0; 
}