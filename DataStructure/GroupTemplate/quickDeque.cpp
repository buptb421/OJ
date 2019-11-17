/* In this programme, you should notice that this programe is aimed to be as brief as possible,   /
 * so that you may have to modify some behavior of it by hand. The instruction of manual override /
 * will be on the top of modifing area.                                                          */

#include <new>
#include <iostream>

using namespace std;

// 1. Modify some pre-compilation constant, you can change 'double'.
#define elemType double

typedef struct DEQUEUE{
    int MemSize; // size of allocated memory
    elemType *list;
    int front;
    int back;
}dequeue;

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

void clearDequeue(dequeue &d)
{
    d.front = d.MemSize;
    d.back = d.MemSize;
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
    /* We know front or back should be a number between [0, size - 1].                            /
     * It's just a notation of empty state.                                                      */
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

bool exist(dequeue d)
{
    return d.list != nullptr && d.MemSize != 0;
}

bool empty(dequeue d)
{
    /* Note that it's empty when all the heads are at 'empty position' d.MemSize.                 /
     * this will simplify push functions(push_front, push_back).                                  /
     * BTW, a not existing dequeue will be empty and full, so that you won't push or pop it.     */
    return d.front != d.MemSize && d.back != d.MemSize;
}

bool full(dequeue d)
{
    /* A not existing dequeue will be empty and full, so that you won't push or pop it.           /
     * You shouldn't use "d.front == prev(d, d.back)", since it doesn't have above property.     */
    return d.back == next(d, d.front);
}

int length(dequeue d)
{
    if(!empty(d))
        return  (d.MemSize - d.back + d.front) % d.MemSize + 1;
    else
        return 0;
}

elemType* pfront(dequeue &d)
{
    if(exist(d) && !empty(d))
        return d.list + d.front;
    else
    {
        cout << "Wrong operation, empty dequeue." << endl;
        return nullptr;
    }
}

elemType* pback(dequeue &d)
{
    if(exist(d) && !empty(d))
        return d.list + d.back;
    else
    {
        cout << "Wrong operation, empty dequeue." << endl;
        return nullptr;
    }
}

void push_front(dequeue &d, elemType data)
{
    if(exist(d) && !full(d))
    {
        d.front = next(d, d.front);
        d.list[d.front] = data;
        if(empty(d))
            d.back = d.front;
    }
    else
        cout << "Can't push front." << endl;
}

void push_back(dequeue &d, elemType data)
{
    if(exist(d) && !full(d))
    {
        d.back = prev(d, d.back);
        d.list[d.back] = data;
        if(empty(d))
            d.front = d.back;
    }
    else
        cout << "Can't push back." << endl;
}

void pop_front(dequeue &d)
{
    if(exist(d) && !empty(d))
    {
        d.front = prev(d, d.front);
        if(d.front == d.back)
            clearDequeue(d);
    }
    else
        cout << "Can't pop front." << endl;
}

void pop_back(dequeue &d)
{
    if(exist(d) && !empty(d))
    {
        d.back = next(d, d.back);
        if(d.front == d.back)
            clearDequeue(d);
    }
    else
        cout << "Can't pop back." << endl;
}

// From there, all the codes are just for demonstration.


// This main function is only for demonstration, you can see how to use previous functions.
int main()
{
    dequeue d;
    constructDequeue(d, 4);
    
    destroyDequeue(d);
    return 0;
}
