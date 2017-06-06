#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>


using namespace std;

class Archivo
{
public:
    FILE* fp;
    char* path;
    Archivo(char* file);
    void Open();
    void Close();
    void Write( int offset, char* data, int size );
    char* Read( int offset, int size );
    bool device_exist();
    void CreateFile( int size );
};

#endif // ARCHIVO_H
