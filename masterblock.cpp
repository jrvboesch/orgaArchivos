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

    memcpy( &blockSize, &data[ pos ], 4 );
    pos += 4;
    memcpy( &blockCount, &data[ pos ], 4 );
    pos += 4;
    memcpy( &First_block, &data[ pos ], 4 );
    pos += 4;
    memcpy( &nextBlock, &data[  pos ], 4 );
    pos += 4;
}

void MasterBlock::guardar(){
    char data [ this->blockSize ];

    this->archivo->Open();

    memcpy( data, this->archivo->Read( 0, this->blockSize ), this->blockSize );

    this->initFromChar( data );

    this->archivo->Close();

}

int MasterBlock::GetFreeBlock(){

    this->archivo->Open();

    this->archivo->Write( 0, this->toChar(), this->blockSize );

    this->archivo->Close();
}

char* MasterBlock::toChar(){
    int pos = 0;
    char data [ this->blockSize ];

    memcpy(  &data[ pos ], &blockSize,4 );
    pos += 4;
    memcpy(  &data[ pos ], &blockCount, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &First_block, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &nextBlock, 4 );
    pos += 4;

    return data;
}
