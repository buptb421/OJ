#include<iostream>
#include<cmath>
#include<vector>

#include "BasicArrayOperations.hpp"


using namespace std;

bool isCondensablePiece(piece left, piece mid, piece right)
{
    if(abs(left.sum) >= abs(mid.sum) && abs(right.sum) >= abs(mid.sum) && (abs(left.sum) != abs(mid.sum) || abs(right.sum) != abs(mid.sum)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

piece condensePiece(piece left, piece mid, piece right)
{
   return setPiece(left.s, right.e, left.sum + mid.sum + right.sum); 
}

void findLocalExtream(int n, int a[])
{
    int nPiece = 0;

    pt tempPT;
    tempPT.left = nullptr;
    tempPT.right = nullptr;
    tempPT.p = setPiece(0, 0, 0);

    vector<pt> extream(3 * LENGTH, tempPT);

    for(int i = 0; i < n; i++)
    {
        tempPT.p = getPiece(n, a, i, 1);
        extream[nPiece] = tempPT;
        if(i > 0)
        {
            extream[nPiece - 1].right = &extream[nPiece];
        }

        nPiece++;
        i = tempPT.p.e;
    }
    displayPieceTree(n, a, &extream[0], 0);
}
