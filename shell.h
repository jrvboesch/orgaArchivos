#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <Discovirtual.h>
#include <vector>

using namespace std;

class shell
{
public:
    DiscoVirtual *dv;
    shell();
    void cmd( char* command );
    void ls(char *path);

};

#endif // SHELL_H
