#include "masterblock.h"

MasterBlock::MasterBlock( Archivo *archivo, int blockSize ) {
    this->blockSize = blockSize;
    this->archivo = archivo;
}

void MasterBlock::cargar() {
    this->archivo->Open();
    char* data = this->archivo->Read( 0, this->blockSize );
    this->initFromChar( data );
    this->archivo->Close();
}

void MasterBlock::initFromChar( char *data ) {
    int pos = 0;

    memcpy( &this->blockSize, &data[ pos ], 4 );
    pos += 4;
    memcpy( &this->blockCount, &data[ pos ], 4 );
    pos += 4;
    memcpy( &this->First_block, &data[ pos ], 4 );
    pos += 4;
    memcpy( &this->nextBlock, &data[  pos ], 4 );
    pos += 4;
}

void MasterBlock::guardar(){
    int pos = 0;
    char* data = new char( this->blockSize );

    memcpy(  &data[ pos ], &this->blockSize,4 );
    pos += 4;
    memcpy(  &data[ pos ], &this->blockCount, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &this->First_block, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &this->nextBlock, 4 );
    pos += 4;

    this->archivo->Write( 0, data, this->blockSize );
}
