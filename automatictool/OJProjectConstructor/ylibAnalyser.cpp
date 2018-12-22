#include"dataheader.hpp"
#include"stringoperation.hpp"
#include"readfile.hpp"

int main()
{
    char filename[MAX_FILENAME + 7];
    int lenFilename = inputString(filename);
    {
	moveStringPiece(filename, lenFilename + 1, 7);
	lenFilename += 8;
	addStringPiece("./ylib/", filename);
    }// Add dir to filename.

    FILE *pFile;
    pFile = fopen(filename, "r");
    
    displayFile(pFile);
    
    fclose(pFile);
    pFile = nullptr;
    return 0;
}


