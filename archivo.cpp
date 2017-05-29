#include "archivo.h"
#include <iostream>

using namespace std;

Archivo::Archivo( char* file, int size ) {
    strcpy( this->path, file );
    this->fp = NULL;
    if( !this->device_exist() ){
        this->CreateFile( size );
    }
}

void Archivo::Open(){
    if( strlen( this->path ) > 0 ) {
        this->fp = fopen( this->path, "a+" );
    }
}

void Archivo::Close() {
    fclose( this->fp );
}

void Archivo::Write( int offset, char* data, int size ) {

    if( this->fp != NULL ){
        fseek( this->fp, offset, SEEK_SET );

        fwrite( data, 1, size, this->fp );
    }

}

char* Archivo::Read( int offset, int size ) {

    if( this->fp != NULL ) {

        char* data =  new char[ size ];

        fseek( this->fp, offset, SEEK_SET );

        fwrite( data, 1, size, this->fp );

        return data;
    }

    return NULL;

}

int Archivo::device_exist() {
    FILE *file;
    if( strlen( this->path ) > 0 ) {
        if( ( file = fopen( this->path, "r" ) ) ) {
            fclose( file );
            return 1;
        }
    }

    return 0;
}


void Archivo::CreateFile( int size ){
    FILE *file;
    if( strlen( this->path ) > 0 ) {
        file = fopen( this->path, "w" );
        fseek( file, size, SEEK_SET );
        fputc( '\0', file );
        fclose( file );
    }
}

