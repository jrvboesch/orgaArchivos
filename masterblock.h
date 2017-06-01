#ifndef MASTERBLOCK_H
#define MASTERBLOCK_H
#include "archivo.h"


class MasterBlock
{
public:
    int blockSize;
    int blockCount;
    int First_block;
    int nextBlock;
    Archivo* archivo;
    MasterBlock(Archivo* archivo , int blockSize);
    void cargar();
    void guardar();
    int GetFreeBlock();
    char* toChar();
    void initFromChar( char* data );
};

#endif // MASTERBLOCK_H
