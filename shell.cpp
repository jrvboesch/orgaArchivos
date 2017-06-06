#include "shell.h"

shell::shell()
{
    this->dv = new DiscoVirtual( "fs.oa", 3*1024*1024);
}

void shell::cmd( char *command ){
    //    char* accion = strtok( command, " " );
        char* accion = "new";
    //    char* opt1 = strtok(NULL, " ");
        char* opt1 = "folder";
    char* opt2 = "hola";
    char* opt3 = "root";
    if( strcmp( accion, "new" ) == 0 ){
        if( strcmp( opt1, "folder" ) == 0 ){
            this->dv->CreateFile( opt3, opt2, 1 );
        }else if( strcmp( opt1, "file" )  == 0 ){
            this->dv->CreateFile( opt3, opt2, 0 );
        }
    }else if( strcmp( accion, "ls" ) == 0){
        this->ls( opt1);
    }
}


void shell::ls( char* path ){
    vector<fileEntry> list = this->dv->ls( path );

    cout << path << endl;
    for( vector<fileEntry>::iterator i = list.begin(); i != list.end(); ++i ){
        fileEntry fe = *i;
        cout << "/" << fe.nombre << endl;
    }
}
