#include<stdio.h>
#include<stdlib.h>
/*
struct{
    int length;
    char *
}typedef name;
later
*/

struct{
    int n;
    char **fname;
}typedef namel;

void Error(char *c)// Done
{
    while(*c != '\n')
    {
	printf("%c", *c);
	c++;
    }
    printf("%c", *c);
}

void destroyList(namel *p)
{
    char **ps = p->fname;
    for(int i = 0; i < p->n; i++, ps++)
    {
	delete[] *ps;
	*ps = nullptr;
    }
    delete[] p->fname;
    p->fname = nullptr;
    p->n = 0;
}

void fputName(FILE *pfile, char **ps)
{
    char *p = *ps;
    while(*p != '\0')
    {
	fprintf(pfile, "%c", *p);
	p++;
    }
}
/*
void putName(char **ps)
{
    char *p = *ps;
    while(*p != '\0')
    {
	printf("%c", *p);
	p++;
    }
}
*/
void fputList(FILE *pfile, namel *plist)
{
    char **ps = plist->fname;
    for(int i = 0; i < plist->n; i++)
    {
	fputName(pfile, ps);
	if(i < (plist->n - 1))
	    fprintf(pfile, " ");
	ps++;
    }
    printf("List into file.\n");
}
/*
void putList(namel *plist)
{
    char **ps = plist->fname;
    for(int i = 0; i < plist->n; i++)
    {
	putName(ps);
	if(i < (plist->n - 1))
	    printf(" ");
	ps++;
    }
    printf("\n");
}
*/
void constructSou(int argc, char **argv, namel *Sou)// Done
{
    Sou->n = argc - 1;
    Sou->fname = argv + 1;
}

int longTar(char *c)// Done
{
    int i;
    for(i = 0; *c != '\n' && *c != '.'; i++)
	c++;
    if(*c == '.')
	return i;
    else
    {
	char c[100] = {"Wrong file name.\n"};
	Error(c);
	return 0;
    }    
}

void constructTar(namel *Sou, namel *Tar)// rewrite
{ 
    char **put, **get = Sou->fname;
    char *p, *q;
    int num, len;
    num = Sou->n;
    Tar->n = Sou->n;
    put = new char*[num];
    if(put == nullptr)
    {
	char c[100] = {"Memory overflow.\n"};
	Error(c);
    }
    Tar->fname = put;
    for(int i = 0; i < num; i++)
    {
	len = longTar(*get);
	*put = new char[len + 1];
	if(*put == nullptr)
	{
	    char d[100] = {"Memory overflow.\n"};
	    Error(d);
	}
	p = *put;
	q = *get;
	for(int j = 0; j < len; j++)
	{
	    *p = *q;
	    p++;
	    q++;
	}
	*p = '\0';
	get++;
	put++;
    }
}

void constructTarSou(FILE *pfile, namel *Sou, namel *Tar)
{
    fputList(pfile, Tar);
    fprintf(pfile, " : ");
    fputList(pfile, Sou);
    fprintf(pfile, "\n");
}

void constructGPPCom(FILE *pfile, namel *Sou, namel *Tar)
{
    char **p = Sou->fname, **q = Tar->fname;
    for(int i = 0; i < Sou->n; i++)
    {
	fprintf(pfile, "\tg++ ");
	fputName(pfile, p);
	fprintf(pfile, " -o ");
	fputName(pfile, q);
	fprintf(pfile, "\n");
	p++;
	q++;
    }
}

void constructmake(FILE *pfile, namel *Sou, namel *Tar)
{
    constructTarSou(pfile, Sou, Tar);
    constructGPPCom(pfile, Sou, Tar);
    fprintf(pfile, "\n");
}

void constructclean(FILE *pfile, namel *Tar)
{
    fprintf(pfile, ".PHONY : clean\n\nclean :\n\trm ");
    fputList(pfile, Tar);
    fprintf(pfile, "\n");
}

int main(int argc, char **argv)
{
    FILE *pfile = fopen("makefile", "w");
    if(pfile == nullptr)
    {
	char c[100] = {"Can't open file.\n"};
	Error(c);
    }

    namel Souc, Tarc;
    
    namel *Sou = &Souc;
    constructSou(argc, argv, Sou);
    
    namel *Tar = &Tarc;
    constructTar(Sou, Tar);
    
    constructmake(pfile, Sou, Tar);
    constructclean(pfile, Tar);


    
    fclose(pfile);
    return 0;
}
