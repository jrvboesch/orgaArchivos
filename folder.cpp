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
    while( pos < blo->blockSize - 4 && fe->firstBlock != 0  ){

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
    int reg = 36 * this->dir->size();
    char data[ reg ];
    int pos = 0;
    int temp_index = 0;
    MasterBlock *mb;
    mb->cargar();

    for( vector<fileEntry>::iterator i = this->dir->begin(); i != this->dir->end(); ++i ){
        fileEntry fe = *i;
        memcpy( &data[ pos ], fe.toChar(), 36 );
        pos += 36;
    }
    pos = 0;
    memcpy( b->data, &data[ pos ], b->blockSize - 4 );
    pos += 36;
    if( pos <= reg ){
        temp_index = mb->GetFreeBlock();
        b->next = temp_index;
        b->Guardar(this->archivo, this->index );
        mb->blockCount += 1;
        mb->guardar();

        while( pos <= reg ){

            Bloque *b2 = new Bloque();
            if( pos + 36 <= reg ){

                b2->next = mb->GetFreeBlock();

                memcpy( b2->data, &data[ pos ], b->blockSize - 4 );

                b2->Guardar( this->archivo, temp_index );

                temp_index = mb->GetFreeBlock();
                mb->blockCount += 1;
                mb->nextBlock += 1;
                mb->guardar();
            }else{
                memcpy( b2->data, &data[ pos ], b2->blockSize - 4 );

                b2->Guardar( this->archivo, temp_index );
            }

            pos += 36;
        }
    }else{
        b->Guardar(this->archivo, this->index );
    }
}
