#include<iostream>

#define LENGTH 100

using namespace std;

int getArray(int a[])
{
    int n;
    cout << "Please enter the length of the array, the number should be a nature number below" << LENGTH  << '.' << endl;
    cin >> n;
    cout << "Please input Array of " << n << " integers." << endl;
    for(int i = 0; i < 100 && i < n; i++)
    {
        cin >> a[i];
    }
    return n;
}

int MinSubsequenceSum(const int A[], int N) 
{ 
	int ThisSum, MinSum, j; 
	ThisSum = MinSum = 0; 
 	for ( j = 0; j < N; j++ )
    { 
 	    ThisSum += A[j]; //-ThisSum += -a[j] => ThisSum += a[j]
	    if (ThisSum < MinSum) // -ThisSum > MinSum => ThisSum < MinSum
        {
            MinSum = ThisSum; 
        }
	    else if (ThisSum > 0) // -ThisSum < 0 => ThisSum > 0
        {
           ThisSum = 0; 
        }
	}
 	return MinSum; 
} // This is -MaxSubsequenceSum over -A = {-a_n}(n = 1, 2, 3...), which complexity is of course O(N).

int main()
{
    int n;
    int a[LENGTH];
    n = getArray(a);
    cout << "The minimum subsequence sum is " << MinSubsequenceSum(a, n) << '.' << endl;
    return 0;
}