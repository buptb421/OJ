/* This is a prototype which would not output correct result, please use KMP_book.cpp or KMP_universial.cpp as reference.
 */

#include<iostream>
#include<string.h>

using namespace std;

void displayArray(int n, int a[], char sep)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << sep;
    }
    if(sep != '\n');
    {
        cout << endl;
    } 
}

void displayMatchPos(char str[], int strL, char pattern[], int patL, int i, int j)
{
	cout << '{' << endl;
	for(int k = 0; k < strL; k++)
	{
        if(k == i)
        {
            cout << '|' << str[k] << '|';
        }
        else
        {
        	cout << str[k];
		}
	}
	cout << endl;
	for(int k = j; k < i; k++)
	{
		cout << ' ';
	}
	for(int k = 0; k < patL; k++)
	{
        if(k == j)
        {
            cout << '|' << pattern[k] << '|';
        }
        else
        {
        	cout << pattern[k];
		}
	}
	cout << endl << '}' << endl;
} 

// intuitively, we notice getNext is doing a counted KMP to pattern itself.
// which, made it possible to form 1 universial procedure to simulate usual 2-part KMP-algorithm.
// The problem is, why books and blog authors doesn't do that?
void getNext(char pattern[], int patL, int next[]) 
{
    next[0] = -1;
    int i = 1, j = 0;
    
    while(i < patL)
    {
        // BEGIN{DEBUG}
    	//displayMatchPos(pattern, patL, pattern, patL, i, j);
        // END{DEBUG}
        if(pattern[i] == pattern[j])
        {
            next[i] = j;
        }
        else
        {
            
            j = next[j];
            // BEGIN{DEBUG} : restrict
            //int restrict = 0;
            while(j >= 0 && pattern[i] != pattern[j] 
			  //&& restrict<10
			)
            {
            	//restrict++;
            // END{DEBUG}
                // BEGIN{DEBUG}
    	        //displayMatchPos(pattern, patL, pattern, patL, i, j);
                // END{DEBUG}
                j = next[j]; 
            }
            if(j == -1)
            {
                next[i] = 0;
            }
            else
            {
                next[i] = j;
                // BEGIN{DEBUG}
    	        //displayMatchPos(pattern, patL, pattern, patL, i, j);
                // END{DEBUG}
            }
        }
        i++;
        j++;
    }
    next[i] = -1;
}

// return number of match records. 
int searchAlienStr(char str[], int strL, char pattern[], int patL, int next[], int match[])
{
    int i = 0, j = 0;
    int nMatch = 0;
    while(strL - i >= patL - j)
    {
        if(str[i] == pattern[j])
        {
            // BEGIN{DEBUG}
    	    displayMatchPos(str, strL, pattern, patL, i, j);
            // END{DEBUG}
            i++;
            j++;
            if(j == patL)
            {
                match[nMatch] = i - j;
                nMatch++;
            }
        }
        else
        {
            // BEGIN{DEBUG}
    	    displayMatchPos(str, strL, pattern, patL, i, j);
            // END{DEBUG}
            j = next[j];
            if(j >= 0)
            {
                // BEGIN{DEBUG}
    	        displayMatchPos(str, strL, pattern, patL, i, j);
                // END{DEBUG}
                i++;
                j++;
            }
            else
            {
            	i++;
            	j++;
			}
        }
    }
    return nMatch;
}

int main()
{
    
    char str[201];
    cin.getline(str, 201);
    int strL = strlen(str);
    
    char pattern[21];
    cin.getline(pattern, 21);
    int patL = strlen(pattern);
    
    int next[20];
    getNext(pattern, patL, next);
    displayArray(patL, next, ',');
    
    int nMatch;
    int match[200];
    nMatch = searchAlienStr(str, strL, pattern, patL, next, match);
    displayArray(nMatch, match, '\n');
    
    return 0;
}
