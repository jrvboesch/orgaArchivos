#include "discovirtual.h"

DiscoVirtual::DiscoVirtual( char * nombre, int fileSize )
{
   this->archivo = new Archivo( nombre );
   tamArch = fileSize;
   if( !archivo->device_exist() ){
       this->archivo->CreateFile( fileSize );
       this->format();
   }
   this->load();
}


void DiscoVirtual::format(){
    mb = new MasterBlock(archivo, tamArch);
    mb->guardar();
    fileEntry* fe = new fileEntry();
    strcpy( fe->nombre, "root");
    fe->firstBlock = 2;
    fe->isFolder = 1;
    fe->lastBlock = 1;
    fe->size = 1;

    Bloque* indice = new Bloque();
    memcpy( &indice->data[0], fe->toChar(), 36 );
    indice->Guardar( this->archivo, 1 );
}

void DiscoVirtual::load(){
    archivo->Open();
    mb = new MasterBlock(archivo, tamArch);
    this->mb->cargar();
}

vector<string> DiscoVirtual::parsePath(char* path){

    vector<string> resultado;
    do {
        char *begin = path;
        while(*path != '/' && *path) {
            path++;
        }
        resultado.push_back(string(begin, path));
    } while (0 != *path++);
    return resultado;

}

vector<fileEntry> DiscoVirtual::ls(char *path){
    Folder *f = new Folder( 1, archivo );
    vector<string> p = this->parsePath( path );
    const char* current;
    vector<string>::iterator pi = p.begin();
    string pi2 = *pi;
    current = pi2.c_str();
    vector<fileEntry>::iterator i = f->dir->begin();
    while( i != f->dir->end() ){
        fileEntry fe = *i;
        if( fe.isFolder == 1 && strcmp( current, fe.nombre ) == 0 ){
            f = new Folder( fe.firstBlock, this->archivo );
            i = f->dir->begin();

            ++pi;
            if( pi == p.end()){
                break;
            }else{
                pi2 = *pi;
                current = pi2.c_str();
            }
        }else{
            ++i;
        }
        if( pi == p.end() ){
            break;
        }
    }
    return *(f->dir);
}

void DiscoVirtual::CreateFile( char* path, char* name, int isFolder ){
    int test = 0;
    fileEntry *dir = this->getDir( path );
    if( dir != NULL ){

        int block_index = this->mb->GetFreeBlock();
        int b =  dir->firstBlock;
        Archivo* arch = this->archivo;
        Folder *f = new Folder( b, arch );
        fileEntry *nuevo = new fileEntry( name, block_index, block_index, isFolder, 1 );
        f->dir->push_back( *nuevo );
        f->saveFolder();
        this->mb->nextBlock += 1;
        this->mb->blockCount += 1;
        this->mb->guardar();
    }
}

//char* DiscoVirtual::readFile( char* path ){
//    fileEntry dir = this->getDir( path );
//    if( dir ){
//        Folder *f = new Folder( dir.firstBlock, this->archivo );

//    }
//    // To-do
//}

fileEntry* DiscoVirtual::getDir( char* path ){
    Folder *f = new Folder( 1, this->archivo );
    fileEntry root = f->dir->at( 0 );
    vector<string> p = this->parsePath( path );
    const char* current;
    vector<string>::iterator pi = p.begin();
    string pi2 = *pi;
    current = pi2.c_str();
    for( vector<fileEntry>::iterator i = f->dir->begin(); i != f->dir->end(); ++i ){
        fileEntry fe = *i;
        if( fe.isFolder == 1 && strcmp( current, fe.nombre ) == 0 ){
            f = new Folder( fe.firstBlock, this->archivo );
            i = f->dir->begin();
            ++pi;

            if( pi == p.end() ){
                return &fe;
            }else{
                pi2 = *pi;
                current = pi2.c_str();
            }
        }
    }
    if( p.size() == 1 ){
        return &root;
    }
    return NULL;
}








