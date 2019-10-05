#include<iostream>
#include"MinimumSubsequence.hpp"

using namespace std;

int main()
{
    int test1[8] = {1, 3, 4, -2, -7, 10, 14, -1};
    int ntest1 = 8;
	
	int test2[10] = {1, 3, 4, -2, -7, 10, 14, -1, -25, -3};
	int ntest2 = 10;
    /*
    int a[100];
    int na = getArray(a); 
    */
   DisplayPieceSumMatrix(ntest2, test2);
   return 0;
}
