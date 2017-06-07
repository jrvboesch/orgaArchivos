#include "folder.h"

Folder::Folder( int b, Archivo *archivo )
{
    this->archivo = archivo;
    this->index = b;
    this->dir = new vector<fileEntry>();
    ls( b );
}

void Folder::ls(int b){
    Bloque *blo = new Bloque();
    blo->Cargar( this->archivo, b );
    fileEntry *fe =  new fileEntry();
    char data[ 36 ];
    int pos = 0;

    memcpy( data, &blo->data[ pos ], 36 );
    fe->InitFromChar( data );
    pos += 36;
    while( pos < 4092 && strcmp( fe->nombre, "" ) != 0  && fe->firstBlock > 0 ){

        dir->push_back( *fe );
        memcpy( data, &blo->data[ pos ], 36 );
        fe->InitFromChar( data );

        pos += 36;
    }
    if( blo->next != 0 )
        this->ls( blo->next );
}

void Folder::saveFolder(){
    Bloque *b = new Bloque();
    b->Cargar( this->archivo, this->index );
    int pos = 0;
    vector<fileEntry>::iterator d = this->dir->begin();

    while( d != this->dir->end() ){
        fileEntry fe = *d;
        memcpy( &b->data[ pos ], fe.toChar(), 36 );
        pos += 36;
        ++d;
    }

    b->Guardar( this->archivo, this->index );
}
