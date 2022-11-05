#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void mkdir_dir(char dir[])
{
    int r = mkdir(dir, 0777);
    if (r == -1)
    {
        perror(dir);
    }
}

void mkdir_V(char dir[])
{
    int r = mkdir(dir, 0777);
    if (r == -1)
    {
        perror(dir);
    }
    else
    {
        printf("mkdir: created directory '%s'\n", dir);
    }
}


int main(int argc, char *argv[])
{
    // ./mkdir mkdir dirname
    // ./mkdir mkdir -v dirname

    if(argc == 3){
        char dir[100];
        strcpy(dir,argv[2]);
        mkdir_dir(dir);
    }
    else if(argc == 4){
        if(argv[2][1] == 'v'){
            char dir[100];
            strcpy(dir,argv[3]);
            mkdir_V(dir);
        }
        else{
            printf("Command not supported!!");
        }
    }
}