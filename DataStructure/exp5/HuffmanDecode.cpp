#include<iostream>
#include<iomanip>
#include<stdio.h>

#define NUM 8
#define LENGTH 500

using namespace std;

typedef struct huffmanTreeNode{
    int parent, left, right;
    int weight;// percent * 100
} hfmn;// huffman tree node(array version)
/*
void displayNode(hfmn hfmTree[], int i)
{
    cout << '(';
    cout << setw(4) << i;
    cout << setw(4) << hfmTree[i].weight;
    cout << setw(4) << hfmTree[i].parent;
    cout << setw(4) << hfmTree[i].right;
    cout << setw(4)	<< hfmTree[i].left;
    cout << ')';
    cout << endl;
}

void displayTreeTable(hfmn hfmTree[])
{
	for(int i = 0; i < 15; i++)
	{
		displayNode(hfmTree, i);
	}
	cout << endl;
}

void displayTreeStructure(hfmn hfmTree[], int i, int indent)
{
	if(i != -1)
	{
		for(int j = 0; j < indent; j++)
		{
			cout << ' ';
		}
		displayNode(hfmTree, i);
		indent += 2;
		displayTreeStructure(hfmTree, hfmTree[i].left, indent);
		displayTreeStructure(hfmTree, hfmTree[i].right, indent);
	}
	
}
*/
void initHuffmanTree(hfmn hfmTree[], int m)
{
    for(int i = 0; i < m; i++)
    {
        hfmTree[i].weight = 0;
        hfmTree[i].left = -1;
        hfmTree[i].right = -1;
        hfmTree[i].parent = -1;
    }
}

void selectMin(hfmn hfmTree[], int i, int &s1, int &s2)
{
    int count = 0, temp;
    for(int j = 0; j < i; j++)
    {
        if(hfmTree[j].parent == -1)
        {
            if(count == 0)
            {
                s1 = j;
            }
            else if(count == 1)
            {
                s2 = j;
            }
            else
            {
            	if(hfmTree[s1].weight > hfmTree[s2].weight)
            	{
                	temp = s1;
               		s1 = s2;
                	s2 = temp;
            	}
            	if(hfmTree[j].weight < hfmTree[s2].weight)
            	{
            		s2 = j;
				}
			}
            count++;
        }
    }
    if(hfmTree[s1].weight > hfmTree[s2].weight)
	{
    	temp = s1;
   		s1 = s2;
    	s2 = temp;
	}
}

void makeFather(hfmn hfmTree[], int s1, int s2, int i)
{

    hfmTree[s1].parent = i;
    hfmTree[s2].parent = i;
    hfmTree[i].left = s1;
    hfmTree[i].right = s2;
    hfmTree[i].weight = hfmTree[s1].weight + hfmTree[s2].weight;
}

void buildHuffmanTree(int n, int frequency[], char alphabetTable[], hfmn hfmTree[])
{
    int m = 2 * n - 1;
    initHuffmanTree(hfmTree, m);
    for(int i = 0; i < n; i++)
    {
        hfmTree[i].weight = frequency[i];
    }
    int s1, s2;
    for(int i = n; i < m; i++)
    {
        selectMin(hfmTree, i, s1, s2);
        makeFather(hfmTree, s1, s2, i);
    }
}

int getCode(bool code[])
{
    int i;
    char c[LENGTH];
    gets(c);
    for(i = 0; c[i] != '\0'; i++)
    {
        if(c[i] == '0')
        {
            code[i] = false;
        }
        else
        {
            code[i] = true;
        }
    }
    return i;
}

void decodeHuffmanCode(int n, bool code[], hfmn hfmTree[], int root, char alphabetTable[])
{
    int prevNode = root;
    for(int i = 0; i < n; i++)
    {
        if(code[i]) // code[i] is true
        {
            prevNode = hfmTree[prevNode].right;
        }
        else
        {
            prevNode = hfmTree[prevNode].left;
        }
        if(hfmTree[prevNode].left == -1 && hfmTree[prevNode].right == -1)
        {
            cout << alphabetTable[prevNode];
            prevNode = root;
        }
    }
}

int main()
{
	const int m = NUM * 2 - 1; 
    int frequency[NUM] = {7, 19, 2, 6, 32, 3, 21, 10};
    char alphabetTable[NUM] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    hfmn hfmTree[m];
    buildHuffmanTree(NUM, frequency, alphabetTable, hfmTree);
	
	//displayTreeStructure(hfmTree, m - 1, 0);
	
    bool code[LENGTH];
    int n = getCode(code);
    
    decodeHuffmanCode(n, code, hfmTree, m - 1, alphabetTable);
    
    return 0;
}
