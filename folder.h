#ifndef FOLDER_H
#define FOLDER_H
#include <vector>
#include "FileEntry.h"
#include "Bloque.h"
#include "MasterBlock.h"


class Folder
{
public:
    vector<fileEntry> *dir;
    int index;
    Archivo *archivo;
    Folder( int b, Archivo* archivo);
    void ls(int b);
    void saveFolder();
};

#endif // FOLDER_H
