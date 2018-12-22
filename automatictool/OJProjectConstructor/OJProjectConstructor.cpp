/*
  Autamatic bulid individual .cpp files and makefile for OJ projects.
  Now only can build one file at a time.
  Now Can't build makefile.

  Now can only deal with built-in types.
 */

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
    FILE *pFile;
    (*argv)++;
    pFile = initFile(*argv);
    printf("File ");
    outputNString(*argv);
    printf(" has been created, please add lib functions.\n");

    
    
    
}
