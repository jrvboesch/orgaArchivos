#ifndef BLOQUE_H
#define BLOQUE_H
#include "archivo.h"


class Bloque
{
public:

    Bloque(char * nombre, int numB,long tamanoB,bool disp );
    virtual long getTamanoBloque();
    virtual int getNumBloque();
    virtual char * getNombre();
    virtual bool getDisponible();

    virtual void initFromChar(char * d);
    long tamanoBloque;
    int numBloque;
    char * nombre;
    bool disponible;
};

#endif // BLOQUE_H
