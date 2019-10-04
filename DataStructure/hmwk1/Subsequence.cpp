#include<iostream>
#include"MinimumSubsequence.hpp"

using namespace std;

int main()
{
    int test1[8] = {1, 2, 3, 4, -4, -3, -2, -1};
    int ntest1 = 8;

    /*
    int a[100];
    int na = getArray(a); 
    */
   DisplayPieceSumMatrix(ntest1, test1);
   return 0;
}
