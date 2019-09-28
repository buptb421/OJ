
#include<iostream>
#include<new>
#include"elemtype.hpp"

using namespace std;

#define STACK_INIT_SIZE 100

typedef struct stack_twin {
    ElemType *elem;
    int odnTop; // Ordinal top, Actually elem[odnTop] is the element next to the ordinal top element.
    int revTop; // Reversed top
    int stacksize;
} twStack;

bool isStackExist(twStack s)
{
    if(s.elem != nullptr && s.stacksize != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isOdnStackEmpty(twStack s)
{
    if(isStackExist(s) && s.odnTop == 0)
    {
        return true;
    }
    else
    {
        return false;
    }   
}

bool isRevStackEmpty(twStack s)
{
    if(isStackExist(s) && s.revTop == s.stacksize - 1)
    {
        return true;
    }
    else
    {
        return false;
    }   
}

void InitStack(twStack &s)
{
    ElemType *ptemp = new ElemType[STACK_INIT_SIZE];
    s.elem = nullptr;
     

    if(ptemp == nullptr)
    {
        cout << "[Failed to new the memory space for stack]" << endl;
        s.stacksize = 0;
    }
    else
    {
        s.elem = ptemp;
        s.stacksize = STACK_INIT_SIZE;
    }
    s.odnTop = 0;
    s.revTop = s.stacksize - 1;
}

void ClearStack(twStack &s)
{
    s.odnTop = 0;
    s.revTop = s.stacksize - 1;
    cout << "[stack cleared]" << endl;
}

void DestroyStack(twStack &s)
{
    if(isStackExist(s))
    {
        delete[] s.elem;
        s.elem = nullptr;
    }
    s.stacksize = 0;
    ClearStack(s);
    cout << "[stack destroyed]" << endl;
}

int OdnStackLength(twStack s)
{
    return s.odnTop;
}

int RevStackLength(twStack s)
{
    return s.stacksize - 1 - s.revTop;
}

void GetOdnTop(twStack s, ElemType &e)
{
    if(!isOdnStackEmpty(s))
    {
        return s.elem[s.odnTop - 1];
    }
}

void GetRevTop(twStack s, ElemType &e)
{
    if(!isRevStackEmpty(s))
    {
        return s.elem[s.revTop + 1];
    }
}

void pushOdn(twStack &s, ElemType e)
{
    if(isStackExist(s) && s.odnTop <= s.revTop)
    {
        s.elem[s.odnTop] = e;
        s.odnTop++;
    }
    else
    {
        cout << "[Memory overflow]" << endl;
    }
}

void pushRev(twStack &s, ElemType e)
{
    if(isStackExist(s) && s.odnTop <= s.revTop)
    {
        s.elem[s.revTop] = e;
        s.revTop++;
    }
    else
    {
        cout << "[Memory overflow]" << endl;
    }
}

ElemType popOdn(twStack &s)
{
    if(!isOdnStackEmpty(s))
    {
        return s.elem[s.odnTop - 1];
    }
    else
    {
        cout << "[The stack is empty, can't pop]" << endl;
        return DefaultElem;
    }
}

ElemType popRev(twStack &s)
{
    if(!isRevStackEmpty(s))
    {
        return s.elem[s.revTop + 1];
    }
    else
    {
        cout << "[The stack is empty, can't pop]" << endl;
        return DefaultElem;
    }
}



