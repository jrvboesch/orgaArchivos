#ifndef DISCOVIRTUAL_H
#define DISCOVIRTUAL_H
#include "archivo.h"
#include "masterblock.h"

class DiscoVirtual
{
public:
    Archivo* archivo;
    MasterBlock* masterBlock;
    long file_size;
    long block_size;
    DiscoVirtual();
    void format();
};

#endif // DISCOVIRTUAL_H
