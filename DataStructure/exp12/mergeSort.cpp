#include <iostream>

using namespace std;

#define len 100

int getArray(int a[])
{
    char s[2 * len];
    cin.getline(s, len);
    int count = 0;
    for(int i = 0, num = 0; i < 2 * len && s[i] != '\0'; i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            num = num * 10 + s[i] - '0';
        }
        else if(s[i] == ',')
        {
            a[count] = num;
            count++;
            num = 0;
        }
    }
    return count;
}

int main()
{
    int a[len], b[len];

    int na = getArray(a), nb = getArray(b);
    int c[len];
    int ra = 0, rb = 0;
    for(int i = 0; i < na + nb; i++)
    {
        if(rb < nb && (ra == na || a[ra] > b[rb]))
        {
            c[i] = b[rb];
            rb++;
        }
        else
        {
            c[i] = a[ra];
            ra++;
        }
    }
    for(int i = 0; i < na + nb; i++)
    {
        cout << c[i] << ',';
    }
}