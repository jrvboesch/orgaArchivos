#include "bloquearchivo.h"

BloqueArchivo::BloqueArchivo(char * nombre, int numB, Archivo * a,long tamanoB, bool disp):Bloque(nombre,numB,tamanoB,disp)
{
    archivo = a;
}
/*
fileEntry * BloqueArchivo::getFileEntry()
{
    return fe;
}
*/
bool BloqueArchivo::getDisponible()
{
    return Bloque::getDisponible();
}

void BloqueArchivo::initFromChar(char * d)
{
    int pos = 0;
    memcpy(&nombre, &d[pos], 30);
    pos+=30;
    memcpy(&numBloque, &d[pos], 4);
    pos+=4;
    memcpy(&tamanoBloque, &d[pos], 4);
    pos+=4;
}

char * BloqueArchivo::getNombre()
{
    return Bloque::getNombre();
}

int BloqueArchivo::getNumBloque()
{
    return Bloque::getNumBloque();
}

long BloqueArchivo::getTamanoBloque()
{
    return Bloque::getTamanoBloque();
}

Archivo * BloqueArchivo::getArchivo()
{
    return archivo;
}
