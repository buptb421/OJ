#ifndef _SCOPEOPERATION_HPP
#define _SCOPEOPERATION_HPP 

#include"LineOperation.cpp"

typedef struct Scope{
    int nLine;
    Line *Par;
}Scope;

Scope *constructScope(int lenSco);
void relateScope(Scope *p, int lenSco, Line *r);
void destroyScope_self(Scope *p);
void destroyScope_trav(Scope *p);

#endif
