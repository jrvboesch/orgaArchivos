#include <QCoreApplication>
#include <QDebug>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <shell.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char command[30];
    shell *cmd = new shell();
    qDebug() << "";
    do{
        cout << " Menu " << endl;
        cout << "-$  ";
//        cin >> command;
        cmd->cmd( "new folder hola /" );
    }while( strcmp( command, "exit" ) != 0 );

    return a.exec();
}

// 30/5/2017
// 1pt+ por participar en clase!
