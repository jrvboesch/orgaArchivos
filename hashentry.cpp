#include "hashentry.h"

hashEntry::hashEntry()
{

}

char* hashEntry::toChar(){
    int pos = 0;
    char data [ 28 ];

    memcpy(  &data[ pos ], nombre, 20 );
    pos += 20;
    memcpy(  &data[ pos ], &absolute, 4 );
    pos += 4;
    memcpy(  &data[ pos ], &relative, 4 );
    pos += 4;

    return data;
}

void hashEntry::initFromChar( char* data ){
    int pos = 0;

    memcpy( nombre, &data[ pos ], 20 );
    pos += 20;
    memcpy( &absolute, &data[ pos ], 4 );
    pos += 4;
    memcpy( &relative, &data[ pos ], 4 );
    pos += 4;
}
