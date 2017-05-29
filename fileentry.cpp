#include "fileentry.h"

fileEntry::fileEntry(char *nombre, int firstBlock, int lastBlock, int isFolder, long size) {

    strcpy( this->nombre, nombre );
    this->firstBlock = firstBlock;
    this->lastBlock = lastBlock;
    this->isFolder = isFolder;
    this->size = size;
}

int fileEntry::getFirstBLock()
{
    return firstBlock;
}

int fileEntry::getLastBlock()
{
    return lastBlock;
}

void fileEntry::esFolder()
{
    if(isFolder)
        cout<<"Es un Folder"<<endl;
    else
        cout<<"Es un Archivo"<<endl;
}

int fileEntry::getSize()
{
    return size;
}
