#include "hashtable.h"

hashTable::hashTable( int hashBlock, Archivo* archivo ) {
    this->hashBlock  = hashBlock;
    this->archivo = archivo;
}

int hashTable::getHashKey( char* value ){
    char* str = value;
    int key = 0;
    int seed = 300;
    int hash = 0;
    int size = 4092/28;

    while( *str ){
        hash = (hash * seed ) + *str;
    }

    key = hash % size;

    return key;
}


fileEntry hashTable::Search( char* name ){
    int key = this->getHashKey( name );
    int pos = key * 28;
    char hedata[28];
    char fedata[36];
    hashEntry* he = new hashEntry();
    fileEntry* fe = new fileEntry();
    Bloque *block = new Bloque();
    block->Cargar( this->archivo, this->hashBlock );

    memcpy( hedata, &block->data[pos], 28 );
    he->initFromChar( hedata );

    pos = he->relative * 36;
    block->Cargar( this->archivo, he->absolute );
    memcpy( fedata, &block->data[pos], 36 );

    fe->InitFromChar( fedata );

    return *fe;
}


void hashTable::Guardar( fileEntry* fe, int pos ){
    hashEntry* he = new hashEntry();
    int key = this->getHashKey( fe->nombre );
    memcpy( he->nombre, fe->nombre, 20 );
    he->absolute = fe->firstBlock;
    he->relative = pos;

    this->insert( he, key );
}


void hashTable::insert( hashEntry* he, int key ){
    Bloque *block = new Bloque();
    char data[28];
    block->Cargar( this->archivo, this->hashBlock );
    int pos = key * 28;
    hashEntry* temp = new hashEntry();

    memcpy( data, &block->data[pos], 28 );
    temp->initFromChar( data );
    if( memcmp( temp->nombre, "", 20 ) == 0 ){
        memcpy( &block->data[pos], he->toChar(), 28 );
        block->Guardar( this->archivo, this->hashBlock );
    }

}
