#include "masterblock.h"

MasterBlock::MasterBlock( Archivo *archivo, int blockSize ) {
    this->blockSize = blockSize;
    this->archivo = archivo;
    this->blockCount = 0;
    this->First_block = 1;
    this->nextBlock = 3;
}

void MasterBlock::cargar() {
    char data [ 4096 ];

    this->archivo->Open();

    memcpy( data, this->archivo->Read( 0, 4096 ), 4096 );

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
    char data [ 4096 ];

    this->archivo->Open();

    memcpy( data, this->toChar(), 4096 );

    this->archivo->Write( 0, data, 4096);

    this->archivo->Close();

}

int MasterBlock::GetFreeBlock(){

    return this->nextBlock;

}

char* MasterBlock::toChar(){
    int pos = 0;
    char data [ 4096 ];

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
