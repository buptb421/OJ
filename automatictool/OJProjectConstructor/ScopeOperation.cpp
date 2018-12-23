#ifndef _SCOPEOPERATION_CPP
#define _SCOPEOPERATION_CPP

Scope *constructScope(int lenSco)
{
    Scope *p = new Scope;
    if(p == nullptr)
    {
	printf("\n\nMemory overflow when locating new Scope.\n\n\n");
	return nullptr;
    }
    else
    {
	p -> nLine = lenSco;
	p -> Par = new Line[lenSco];
	if(p -> Par == nullptr)
	{
	    printf("\n\nMemory overflow when locating new line in scope.\n\n\n");
	    delete p;
	    return nullptr;
	}
	else
	    return p;
    }
}

void relateScope(Scope *p, int lenSco, Line *r)
{
    Line *w = p -> Par;
    for(int i = 0; i <= lenSco; i++, r++, w++)
	*w = *r;
}

void destroyScope_self(Scope *p)
{
    if(p == nullptr)
    {
	printf("\n\nScope already deleted.\n\n\n");
    }
    else
    {
	if(p -> Par == nullptr)
	    printf("\n\nScope is empty.\n\n\n");
	else
	    delete [](p -> Par);
	delete p;
    }
}

void destroyScope_trav(Scope *p)
{
    if(p == nullptr)
    {
	printf("\nScope is already deleted.\n\n\n");
    }
    else
    {
	Line *templ = p -> Par;
	for(int i = 0; i < p -> nLine; i++, templ++)
	    destroyLine(templ);
	destroyScope_self(p);
    }
}

#endif
