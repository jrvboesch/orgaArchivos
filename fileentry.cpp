#include "fileentry.h"

fileEntry::fileEntry(char *nombre, int firstBlock, int lastBlock, int isFolder, long size) {

    strcpy( this->nombre, nombre );
    this->firstBlock = firstBlock;
    this->lastBlock = lastBlock;
    this->isFolder = isFolder;
    this->size = size;
}
