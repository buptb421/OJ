#include <iostream>
#include <new>

#define nullptr NULL

using namespace std;

typedef struct LINK_LIST_NODE{
    int data;
    LINK_LIST_NODE *next;
}llnode;

void displayLList(llnode *llist)
{
    /* begin{DEBUG}*
        int count = 0;
    /* end{DEBUG}*/
    llnode *p = llist;
    while(p)
    {
        /* begin{DEBUG}*
            count++;
            cout << '[' << p - llist << ']';
        /* end{DEBUG}*/
        cout << p->data << ',';
        p = p->next;
    }
    cout
        /* begin{DEBUG}*
            << '(' << count << ')'
        /* end{DEBUG}*/ 
        << endl;
}

void cycExchange(llnode *a, llnode *b, llnode *c)// a <- b <- c <- a
{
    llnode *temp = a->next;
    a->next = b->next;
    b->next = c->next;
    c->next = temp;
}

void insertionSort(llnode *llist)
{
    const int prev = 0;
    const int now = 1;
    llnode *extractor[2];
    llnode *carrier;
    int target;

    extractor[prev] = llist;
    extractor[now] = llist->next;
    while(extractor[now])
    {
        target = extractor[now]->data;
        carrier = llist;
        while(carrier->next->data <= target && carrier != extractor[prev])
        {
            carrier = carrier->next;
        }
        if(carrier != extractor[prev])
        {
            cycExchange(carrier, extractor[prev], extractor[now]);
            extractor[now] = extractor[prev]->next;
        }
        else
        {
        	extractor[prev] = extractor[now];
        	extractor[now] = extractor[now]->next;
		}
        if(extractor[prev] != llist->next)
        {
        	displayLList(llist->next);
		}
    }
}

int main()
{
    int n;
    cin >> n;
    llnode *llist = new llnode[n + 1];
    if(llist)
    {
    	char comma;
        for(int i = 1; i <= n; i++)
        {
            cin >> llist[i].data >> comma;
            llist[i - 1].next = &llist[i];
        }
        llist[n].next = nullptr;
        //displayLList(llist);

        insertionSort(llist);
        delete[] llist;
        return 0;
    }
    else
    {
        cout << "Mem ovfl." << endl;
        return 1;
    }
}
