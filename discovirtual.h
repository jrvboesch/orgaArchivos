#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H
#include <qstring.h>'
#include <vector>
#include "archivo.h"
#include "masterblock.h"
#include "bloque.h"
#include "fileentry.h"
#include "folder.h"

class DiscoVirtual
{
public:
    Archivo* archivo;
    MasterBlock* mb;
    Bloque* block;
    fileEntry* fe;

    DiscoVirtual(Archivo *archivo, int fileSize);
    void format();
    void load();
    void CreateFile(char* path, char* name , int isFolder);
//    char* readFile( char* path );
    vector <fileEntry> ls(char* path);
    vector <string> parsePath(char* path);
    fileEntry *getDir( char* path );

    int file_size;
    long block_size;
    int tamArch;
};

#endif // DISCOVIRTUAL_H
