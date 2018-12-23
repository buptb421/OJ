#ifndef _LINEOPERATION_CPP
#define _LINEOPERATION_CPP

Line *constructLine(int lenLine)
{
    Line *p = new Line;
    if(p == nullptr)
    {
	printf("\n\nMemory overflow when locating new Line.\n\n\n");
	return p;
    }
    else
    {
	p -> nChar = lenLine;
	p -> Str = new char[(p -> nChar) + 1];
	if (p -> Str == nullptr)
	{
	    printf("\n\nMemory overflow when locating new string.\n\n\n");
	    delete p;
	    return nullptr;
	}
	else
	{
	    p -> Str[p -> nChar] = '\0';
	    return p;
	}
    }
}

void relateLine(Line *p, int lenLine, char *r)
{
    char *w = p -> Str;
    for(int i = 0; i <= lenLine; i++, r++, w++)
	*w = *r;
    r--;
    if(*r != '\0')
	printf("Error ending: %c\n", *r);
}

void destroyLine(Line *p)
{
    if(p == nullptr)
    {
	printf("\n\nLine has already been deleted.\n\n\n");
    }
    else
    {
	if(p -> Str == nullptr)
	    printf("\n\nString is empty.\n\n\n");
	else
	    delete [](p -> Str);
	delete p;
    }
}


Line *storeLine(int lenLine, char *s)
{
    Line *p = constructLine(lenLine);
    if(p != nullptr)
	relateLine(p, lenLine, s);
    return p;
}

Line *freadLine_Line(FILE *pFile)
{
    Line *l;
    char line[MAX_LINE + 1];
    int lenLine;
    lenLine = freadLine_Str(pFile, line);
    if(lenLine != 0 && !feof(pFile))
    {
	l = storeLine(lenLine, line);
	if(l != nullptr)
	    return l;
	else
	    return constructLine(0);
    }
    else
	return constructLine(0);
}

void displayLine(Line *l)
{
    printf("[%-3d]", l -> nChar);
    outputString(l -> Str);
    printf("\n");
}

#endif
