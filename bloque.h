#ifndef BLOQUE_H
#define BLOQUE_H
#include "archivo.h"


class Bloque
{
public:
    int next;
    char data[4092];
    int blockSize;
    Bloque();
    void setNext( int next );
    void setData( char* data );
    int getNext();
    char* getData();
    void Cargar( Archivo* archivo, int index );
    void Guardar( Archivo* archivo, int index );
    void InitFromChar(char* dat );
    char* toChar();
};

#endif // BLOQUE_H
