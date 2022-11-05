#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void RM(char fileName[1000]){   
    char file[1000];
    int i = 0;
    for(i;i<100;i++){
        if(fileName[i] == '\n'){
            file[i] = '\0';
            break;
        }
        else{
            file[i] = fileName[i];
        }
    }
    int r = unlink(file);
    if (r != 0)
    {
        perror(file);
        return;
    }
}

void RM_D(char fileName[1000])
{   
    char file[1000];
    int i = 0;
    for(i;i<100;i++){
        if(fileName[i] == '\n'){
            file[i] = '\0';
            break;
        }
        else{
            file[i] = fileName[i];
        }
    }
    if (rmdir(file) != 0)
    {
        perror(file);
    }
}

void RM_V(char fileName[1000])
{   char file[1000];
    int i = 0;
    for(i;i<100;i++){
        if(fileName[i] == '\n'){
            file[i] = '\0';
            break;
        }
        else{
            file[i] = fileName[i];
        }
    }
    if (unlink(file) == 0)
    {
        printf("removed '%s'\n", file);
    }
    else
    {
        perror(file);
    }
}

int main(int argc, char *argv[])
{
    // ./rm rm filename
    // ./rm rm -d filename
    // ./rm rm -v filename

    if(argc == 3){
        char fileName[1000] = "";
        strcpy(fileName,argv[2]);
        RM(fileName);
    }
    else if(argc == 4){
        if(argv[2][1] == 'v'){
            char fileName[1000] = "";
            strcpy(fileName,argv[3]);
            RM_V(fileName);
        }
        else if(argv[2][1] == 'd'){
            char fileName[1000] = "";
            strcpy(fileName,argv[3]);
            RM_D(fileName);
        }
        else{
            printf("Command not supported");
        }
    }   
    return 0;
}


