#include <new>
#include <iostream>

using namespace std;

#define elemType double

// Position indicators
#define POS_BACK 0
#define POS_FRONT 1

// Step direction indicators
#define STEP_BACKWARD 0
#define STEP_FOWARD 1


typedef struct DEQUEUE{
    int MemSize;
    elemType *list;
    int head[2];
}dequeue;
void clearDequeue(dequeue &d)
{
    for(int i = POS_BACK; i <= POS_FRONT; i++)
        d.head[i] = d.MemSize;
}
bool constructDequeue(dequeue &d, int size)
{
    d.MemSize = 0;
    d.list = nullptr;
    if(size > 0)
    {
        d.list = new elemType[size];
        if(d.list)
            d.MemSize = size;
        else
            cout << "Memory overflow." << endl;
    }
    else
        cout << "Size can't be 0." << endl;
    clearDequeue(d);
    return d.MemSize != 0;
}
void destroyDequeue(dequeue &d)
{
    d.MemSize = 0;
    clearDequeue(d);
    if(d.list)
    {
        delete[] d.list;
        d.list = nullptr;
    }
}

int next(dequeue d, int now)
{
    now++;
    if(now < d.MemSize)
        return now;
    else
        return 0;
}
int prev(dequeue d, int now)
{
    if(now <= 0)
        return d.MemSize - 1;
    else
        return now - 1;
}
int step(dequeue d, int stp_ind, int now)
{
    if(stp_ind == STEP_FOWARD)
        return next(d, now);
    else
        return prev(d, now);
}

bool exist(dequeue d)
{
    return d.list != nullptr && d.MemSize != 0;
}
bool empty(dequeue d)
{
    return d.head[POS_FRONT] == d.MemSize || d.head[POS_BACK] == d.MemSize;
}
bool full(dequeue d)
{
    return d.head[POS_BACK] == next(d, d.head[POS_FRONT]);
}

int length(dequeue d)
{
    if(!empty(d))
        return  (d.MemSize - d.head[POS_BACK] + d.head[POS_FRONT]) % d.MemSize + 1;
    else
        return 0;
}

elemType* phead(dequeue &d, int pos_ind)
{
    if(exist(d) && !empty(d))
        return d.list + d.head[pos_ind];
    else
    {
        cout << "Wrong operation, empty dequeue." << endl;
        return nullptr;
    }
}
void push(dequeue &d, int pos_ind, elemType data)
{
    int stp_ind = pos_ind;
    if(exist(d) && !full(d))
    {
        d.head[pos_ind] = step(d, stp_ind, d.head[pos_ind]);
        d.list[d.head[pos_ind]] = data;
        if(empty(d))
            d.head[1 - pos_ind] = d.head[pos_ind];
    }
    else
        cout << "Can't push." << endl;
}
// I noticed that we can even unify push and pop, as long as I have a good mood, i'll try it.
void pop(dequeue &d, int pos_ind)
{
    int stp_ind = 1 - pos_ind;
    if(exist(d) && !empty(d))
    {
        d.head[pos_ind] = step(d, stp_ind, d.head[pos_ind]);
        if(full(d))
            clearDequeue(d);
    }
    else
        cout << "Can't pop." << endl;
}

// Operation interface. All the same to STL except front/back return pointers instead of reference.
elemType* front(dequeue &d){return phead(d, POS_FRONT);}
elemType* back(dequeue &d){return phead(d, POS_BACK);}
void push_front(dequeue &d, elemType data){push(d, POS_FRONT, data);}
void push_back(dequeue &d, elemType data){push(d, POS_BACK, data);}
void pop_front(dequeue &d){pop(d, POS_FRONT);}
void pop_back(dequeue &d){pop(d, POS_BACK);}
