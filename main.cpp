//#include <QCoreApplication>
//#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "shell.h"

using namespace std;

int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
    char command[30];
    shell *cmd = new shell();
    do{
        cout << " Menu " << endl;
        cout << "-$  ";
//        cin >> command;
        cmd->cmd( "new folder hola /" );
    }while( strcmp( command, "exit" ) != 0 );
//    Archivo *archivo = new Archivo("test.oa");
//    archivo->CreateFile(3*1024*1024);
//    Bloque* b = new Bloque();
//    Bloque* b2 = new Bloque();
//    char nombre[] = "ce la vi";
//    char nombre2[20];

//    archivo->Open();

//    archivo->Write( 0, nombre, 20 );

//    cout << nombre << endl;
//    cout << "El nombre es: " << archivo->Read( 0, 20 ) << endl;

//    archivo->Close();

//    return a.exec();
}

// 30/5/2017
// 1pt+ por participar en clase!
