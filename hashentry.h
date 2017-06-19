#ifndef HASHENTRY_H
#define HASHENTRY_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class hashEntry
{
public:

    char nombre[ 20 ];
    int absolute;
    int relative;
    hashEntry();
    char* toChar();
    void initFromChar( char* data );
};

#endif // HASHENTRY_H
