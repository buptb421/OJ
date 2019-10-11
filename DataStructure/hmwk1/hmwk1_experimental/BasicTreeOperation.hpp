#include <iostream>
#include <cmath>

#include "structure.hpp"

using namespace std;

void displayPieceTree(int n, int a[], pt *ppt, int indent)
{
    if(ppt != nullptr)
    {
        for(int i = 0; i < indent; i++)
        {
            cout << ' ';
        }
        if(ppt->p.sum > 0)
        {
            cout << "POSITIVE"; 
        }
        else if(ppt->p.sum < 0)
        {
            cout << "NEGATIVE";
        }
        else
        {
            cout << "zero";
        }
        
        cout << ": sum([" << ppt->p.s << "] - [" << ppt->p.e << "]) = " << ppt->p.sum;
        cout << '{';
        cout << endl;
        
        if(ppt->left == nullptr)
        {
            for(int i = 0; i < indent + 2; i++)
            {
                cout << ' ';
            }
            for(int i = ppt->p.s; i <= ppt->p.e; i++)
            {
                
                cout << a[i];
                if(i < ppt->p.e)
                {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        else
        {
            displayPieceTree(n, a, ppt->left, indent + 2);
        }

        for(int i = 0; i < indent; i++)
        {
            cout << ' ';
        }
        cout << '}';
        if(ppt->p.sum > 0)
        {
            cout << "POSITIVE"; 
        }
        else if(ppt->p.sum < 0)
        {
            cout << "NEGATIVE";
        }
        else
        {
            cout << "zero";
        }
        cout << ": sum([" << ppt->p.s << "] - [" << ppt->p.e << "]) = " << ppt->p.sum;
        cout << endl;

        if(ppt->right != nullptr)
        {
            for(int i = 0; i < indent; i++)
            {
                cout << ' ';
            }
            if(abs(ppt->p.sum) > abs(ppt->right->p.sum))
            {
                cout << "VV";
            }
            else if(abs(ppt->p.sum) < abs(ppt->right->p.sum))
            {
                cout << "AA";
            }
            else
            {
                cout << "||";
            }
            cout << endl;
            
            
        }
        displayPieceTree(n, a, ppt->right, indent);
    }
}

void mergeExtreamTree()