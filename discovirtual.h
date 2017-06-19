#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H
#include <vector>
#include "archivo.h"
#include "masterblock.h"
#include "bloque.h"
#include "fileentry.h"
#include "folder.h"
#include "hashtable.h"

class DiscoVirtual
{
public:
    Archivo* archivo;
    MasterBlock* mb;
    Bloque* block;
    fileEntry* fe;
    hashTable* ht;

    DiscoVirtual( char * nombre, int fileSize );
    void format();
    void load();
    void CreateFile(char* path, char* name , int isFolder);
    vector<char *> readFile( char* path );
    void writeFile( char* path, char* buffer );
    vector <fileEntry> ls(char* path);
    vector <string> parsePath(char* path);
    fileEntry *getDir( char* path );
    fileEntry *getFile( char* path );

    int file_size;
    long block_size;
    int tamArch;
};

#endif // DISCOVIRTUAL_H
