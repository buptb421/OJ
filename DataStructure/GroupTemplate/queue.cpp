#include<iostream>
#include<new>

typedef struct QUEUE
{
    int head;
    int tail;
    int data*;
    int size;
}queue;

void init(queue &q, int sizeo)
{
    q.data = new int[sizeo];
    if(q.data)
    {
        q.head = 0;
        q.tail = sizeo - 1;
        q.size = sizeo;
    }
    else
    {
        cout<<"wrong";
    }
}

int size(queue q)
{
    int i;
    i = q.tail -q.head;
    if(i<0)
    {
        i = i + sizeo;
    }
    return iï¼›   
}

int empty(queue q)
{
    if(size(q))
    {
        return 1;
    }
    else
        return 0;
}

int full(queue q)
{
    if(size(q) == q.size)
        return 1;
    else 
        return 0;
}

int front(queue q)
{
    if(q.data)
        return q.data[q.tail];
}

int back(queue q)
{
    if(q.date)
        return q.date[q.head];
}

int pop(queue &q)
{
    if(q.data&&!empty(q))
    {
        q.tail = (q.tail+1)%size;
        return q.data[q.tail];
    }
}

void push(queue &q, int n)
{
    if(q.data&&!full(q))
    {
        q.data[q.head] = n;
        q.head = (q.head+1)%size;
    }
}
