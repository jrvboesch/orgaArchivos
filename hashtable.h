#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "FileEntry.h"
#include "Bloque.h"
#include "Archivo.h"
#include "hashentry.h"


class hashTable
{
public:
    Archivo* archivo;
    int hashBlock;
    hashTable(int hashBlock, Archivo *archivo);
    int getHashKey( char* value );
    fileEntry Search( char* name );
    void Guardar(fileEntry *fe , int pos);
    void insert(hashEntry* he , int key);
};

#endif // HASHTABLE_H
