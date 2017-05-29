#ifndef BLOQUEARCHIVO_H
#define BLOQUEARCHIVO_H
#include "archivo.h"
#include "fileentry.h"
#include "bloque.h"


class BloqueArchivo:public Bloque
{
public:
    BloqueArchivo(char * nombre, int numB, Archivo * a, long tamanoB, bool disp);
    long getTamanoBloque();
    int getNumBloque();
    char * getNombre();
    bool getDisponible();
    Archivo * getArchivo();
    fileEntry * getFileEntry();
    //void setFileEntry(char* n, int firstBlock, int lastBlock, bool isFol, int s);

    void initFromChar(char * d);
    long tamanoBloque;
    int numBloque;
    char * nombre;
    bool disponible;
    Archivo * archivo;

};

#endif // BLOQUEARCHIVO_H
