#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int m[7][7] = {
        0, 2, 0, 1, 0, 0, 0,
        0, 0, 0, 3, 10, 0, 0,
        4, 0, 0, 0, 0, 5, 0,
        0, 0, 2, 0, 2, 8, 4,
        0, 0, 0, 0, 0, 0, 6,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0,
    };

    char comma;
    int f, t;
    cin >> f >> comma >> t;
    m[f - 1][t - 1] = 0;

    int path[7][7];
    int d[7][7];

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            p[i][j] = 0;
        }
    }

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            for(int k = 0; k < 7; k++)
            {

            }
        }
    }
    //path done.
    int fr = 0, to = 5;
    stack<int> one2six;
    do{
        if(path[fr][to] != to)
        {

        }
    }
    while(!one2six.empty());

}