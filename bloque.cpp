#include "bloque.h"

Bloque::Bloque()
{
    this->blockSize = 4096;
    this->setNext( 0 );
}

void Bloque::setNext( int next ){
    this->next = next;
}

void Bloque::setData( char* data ){
    memcpy( this->data, data, this->blockSize - 4 );
}

int Bloque::getNext(){
    return this->next;
}

char* Bloque::getData(){
    return this->data;
}

void Bloque::Cargar( Archivo* archivo, int index ){
    char dat[ this->blockSize ];
    int offset = index * this->blockSize;

    archivo->Open();

    memcpy( dat, archivo->Read( offset, this->blockSize ), this->blockSize );
    this->InitFromChar( dat );

    archivo->Close();
}

void Bloque::Guardar( Archivo* archivo, int index ){
    char dat[ this->blockSize ];
    int offset = index * this->blockSize;
    archivo->Open();

    memcpy( dat, this->toChar(), this->blockSize );

    archivo->Write( offset, dat, this->blockSize );

    archivo->Close();
}

void Bloque::InitFromChar( char* dat ){
    int pos = 0;

    memcpy( &next, &dat[ pos ], 4 );
    pos += 4;
    memcpy( data, &dat[ pos ], this->blockSize - 4 );
}

char* Bloque::toChar(){
    int pos = 0;
    char dat [ this->blockSize ];

    memcpy(  &dat[ pos ], &next, 4 );
    pos += 4;
    memcpy(  &dat[ pos ], data, this->blockSize - 4 );

    return dat;
}
