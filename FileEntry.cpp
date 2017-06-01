#include "fileentry.h"

fileEntry::fileEntry() {

}

fileEntry::fileEntry(char *nombre, int firstBlock, int lastBlock, int isFolder, long size) {

    strcpy( this->nombre, nombre );
    this->firstBlock = firstBlock;
    this->lastBlock = lastBlock;
    this->isFolder = isFolder;
    this->size = size;
}

void fileEntry::UpdateSize( int fileSize ){
    this->size += fileSize;
}

char* fileEntry::toChar(){
    int pos = 0;
    char data [ 36 ];

    memcpy(  &data[ pos ], nombre, 20 );
    pos += 20;
    memcpy(  &data[ pos ], &firstBlock, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &lastBlock, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &isFolder, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &size, 4 );
    pos += 4;

    return data;
}

void fileEntry::InitFromChar( char* data ){
    int pos = 0;

    memcpy( nombre, &data[ pos ], 20 );
    pos += 20;
    memcpy( &firstBlock, &data[ pos ], 4 );
    pos += 4;
    memcpy( &lastBlock, &data[ pos ], 4 );
    pos += 4;
    memcpy( &isFolder, &data[ pos ], 4 );
    pos += 4;
    memcpy( &size, &data[  pos ], 4 );
    pos += 4;
}
