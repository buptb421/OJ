#include<iostream>

#define ElemType char
#define DefaultElem '\0'

void Display_ElemType(char e)
{
    if(e >= 40 && e < 127)
    {
        std::cout << e;
    }
    else
    {
        std::cout << '[' << (int)e << ']';
    }
}
