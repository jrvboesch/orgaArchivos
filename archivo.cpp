#include "archivo.h"
#include <iostream>

using namespace std;

Archivo::Archivo( char* file ) {
    this->path = file;
    this->fp = NULL;
}

void Archivo::Open(){
    if( strlen( this->path ) > 0 ) {
        this->fp = fopen( this->path, "a+" );
    }
}

void Archivo::Close() {
    if( this->fp != NULL ){
        fclose( this->fp );
    }
}

void Archivo::Write( int offset, char* data, int size ) {

    if( this->fp != NULL ){
        fseek( this->fp, offset, SEEK_SET );

        fwrite( data, 1, size, this->fp );
    }

}

char* Archivo::Read( int offset, int size ) {

    if( this->fp != NULL ) {

        char data[size];
        fseek( this->fp, offset, SEEK_SET );

        fread( data, 1, size, this->fp );

        return data;
    }

    return NULL;

}

bool Archivo::device_exist() {
    if( strlen( this->path ) > 0 ) {
        if( ( this->fp = fopen( this->path, "r" ) ) ) {
            this->Close();
            return true;
        }
    }

    return false;
}


void Archivo::CreateFile( int size ){
    if( strlen( this->path ) > 0 ) {
        this->fp = fopen( this->path, "w" );
        fseek( this->fp, size, SEEK_SET );
        fputc( '\0', this->fp );
        this->Close();
    }
}

