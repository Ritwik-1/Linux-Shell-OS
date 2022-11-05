#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void File_content(char fileName[]){ 
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
    FILE* ptr = fopen(file,"r");

    if(ptr == NULL){
        printf("File not found!!\n");
        perror("Error");
        return;
    }
    char ch;
    int count = 1;
    size_t value = fread(&ch, sizeof(char),count,ptr);
    while(value == count){
        printf("%c",ch);
        value = fread(&ch,sizeof(char),count,ptr);
    }
    printf("\n");
    fclose(ptr);
    return;
}

void File_Dollar(char fileName[1000])
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
    FILE* ptr = fopen(file,"r");
    char ch;
    if(ptr == NULL){
        printf("File not found!!\n");
        return;
    }
    int count = 1;
    size_t value = fread(&ch, sizeof(char),count,ptr);
    while(value == count){
        if(ch == '\n'){
            printf("%s","$\n");
        }
        else{
            printf("%c",ch);
        }
        value = fread(&ch,sizeof(char),count,ptr);
    }
    printf("\n");
    fclose(ptr);
    return;
}

void File_Tab(char fileName[1000])
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
    FILE* ptr = fopen(file,"r");
    char ch;
    if(ptr == NULL){
        printf("File not found!!\n");
        return;
    }
    int count = 1;
    size_t value = fread(&ch, sizeof(char),count,ptr);
    while(value == count){
        if(ch == '\t'){
            printf("%s","^I");
        }
        else{
            printf("%c",ch);
        }
        value = fread(&ch,sizeof(char),count,ptr);
    }
    printf("\n");
    fclose(ptr);
    return;
}

int main(int argc, char *argv[]){

    // ./ls cat -E filename
    // ./ls cat filename
    // ./ls cat -T filename

    if(argc == 3){
        char fileName[1000] = "";
        strcpy(fileName,argv[2]);
        File_content(fileName);
    }
    else if(argc == 4){
        if(argv[2][1] == 'E'){
            char fileName[1000] = "";
            strcpy(fileName,argv[3]);
            File_Dollar(fileName);
        }
        else if(argv[2][1] == 'T'){
            char fileName[1000] = "";
            strcpy(fileName,argv[3]);
            File_Tab(fileName);
        }
        else{
            printf("Command not supported");
        }
    }   
}