#ifndef FILEENTRY_H
#define FILEENTRY_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


class fileEntry
{
public:
    char* nombre;
    int firstBlock;
    int lastBlock;
    int isFolder;
    long size;

    fileEntry( char* nombre, int firstBlock, int lastBlock, int isFolder, long size );
};

#endif // FILEENTRY_H
