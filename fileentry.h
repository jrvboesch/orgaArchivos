#ifndef FILEENTRY_H
#define FILEENTRY_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class fileEntry
{
public:
    char nombre[ 20 ];
    int firstBlock;
    int lastBlock;
    int isFolder;
    long size;

    fileEntry( char* nombre, int firstBlock, int lastBlock, int isFolder, long size );

    void UpdateSize( int fileSize );
    char* toChar();
    void InitFromChar( char* data );
};

#endif // FILEENTRY_H
