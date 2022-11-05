#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <pthread.h>


void cdL(char** input_array){
    char path[100];
    strcat(path,input_array[2]);
    int v = chdir(path);
    if(v == -1){
        perror("Error ");
        return;
    }
    printf("\n");
}

void cdP(char** input_array){
    char path[100];
    strcat(path,input_array[2]);
    char r[100];
    char* real_path = realpath(path,r);

     int v = chdir(real_path);
     if(v == -1){
        perror("Error ");
        return;
     }
     printf("\n");
}

void cd(char** input_array){

    if(input_array[1] == NULL){
        int a = chdir(getenv("HOME"));
        if(a!= 0){
            perror("Error in command -");
        }
        else{
            char buf[200];
            char* pat = getcwd(buf,sizeof(buf));
            printf("%s",pat);
        }
    }
    else{

        if(strcmp(input_array[1],"-P") == 0){
            cdP(input_array);
            char buf[200];
            char* path = getcwd(buf,sizeof(buf));
            printf("%s",path);
        }
        else if(strcmp(input_array[1],"-L") == 0){
            cdL(input_array);
            char buf[200];
            char* path = getcwd(buf,sizeof(buf));
            printf("%s",path);
        }
        else if(strcmp(input_array[1],"..") == 0 || strcmp(input_array[1],"-") == 0){
            int ans = chdir("..");
            if(ans != 0){
            perror("Error in command !");
            }
            char buf[200];
            char* path = getcwd(buf,sizeof(buf));
            printf("%s",path);
        }
        else{
            char* p = strtok(input_array[1],"\n");
            int v = chdir(p);
            if(v!=0){
                perror("Error in command ");
            }
            else{
                char buf[200];
                char* pat= getcwd(buf,sizeof(buf));
                printf("%s",pat);
            }
        }
    }
}
void* thread_ls(void* argv){
    char* l = (char*)argv;
    if( l[0] == '&'){
        char* new_s = malloc(sizeof(char)*1000);
        for(int i=0;i<strlen(l)-3;i++){
            new_s[i] = l[i+3];
        }
        printf("executing by threads\n");

        char s[1000] = "./ls ";
        strcat(s,new_s);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
    else{
        char s[1000] = "./ls ";
        strcat(s,l);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
}

void* thread_cat(void* argv){
    char* l = (char*)argv;
    if( l[0] == '&'){
        char* new_s = malloc(sizeof(char)*1000);
        for(int i=0;i<strlen(l)-3;i++){
            new_s[i] = l[i+3];
        }
        printf("executing by threads\n");

        char s[1000] = "./cat ";
        strcat(s,new_s);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
    else{
        char s[1000] = "./cat ";
        strcat(s,l);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
}
void* thread_mkdir(void* argv){
    char* l = (char*)argv;
    if( l[0] == '&'){
        char* new_s = malloc(sizeof(char)*1000);
        for(int i=0;i<strlen(l)-3;i++){
            new_s[i] = l[i+3];
        }
        printf("executing by threads\n");

        char s[1000] = "./mkdir ";
        strcat(s,new_s);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
    else{
        char s[1000] = "./mkdir ";
        strcat(s,l);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
}
void* thread_rm(void* argv){
    char* l = (char*)argv;
    if( l[0] == '&'){
        char* new_s = malloc(sizeof(char)*1000);
        for(int i=0;i<strlen(l)-3;i++){
            new_s[i] = l[i+3];
        }
        printf("executing by threads\n");

        char s[1000] = "./rm ";
        strcat(s,new_s);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
    else{
        char s[1000] = "./rm ";
        strcat(s,l);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
}
void* thread_date(void* argv){
    char* l = (char*)argv;
    if( l[0] == '&'){
        char* new_s = malloc(sizeof(char)*1000);
        for(int i=0;i<strlen(l)-3;i++){
            new_s[i] = l[i+3];
        }
        printf("executing by threads\n");

        char s[1000] = "./date ";
        strcat(s,new_s);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
    else{
        char s[1000] = "./date ";
        strcat(s,l);

        int n = system(s);
        if(n == -1){
            printf("Error");
        }    
        pthread_exit(0);
        return NULL;
    }
}


void pwdP()
{
    char newarr[1024];
    char *cwd2 = getcwd(newarr, sizeof(newarr));
    printf("%s", cwd2);
    printf("\n");
}

void pwdL()
{
    char buf[10000];
    char newarr[1024];
    char *res = realpath(newarr, buf);
    char *cwd2 = getcwd(newarr, sizeof(newarr));
    printf("%s", cwd2);
    printf("\n");
}


void pwd(char** input_array){
    char arr[2000];
    if(input_array[1] != NULL){
        if(strcmp(input_array[1],"--help") == 0){
            printf("This command is used to print the current working directory");
            printf("FLAGS : -P ,-L ");
        }
        else if(strcmp(input_array[1],"-P") == 0){
            pwdP();
        }
        else if(strcmp(input_array[1],"-L") == 0){
            pwdP();
        }
    }
    else{
        char* cwd = getcwd(arr,sizeof(arr));
        if(cwd == NULL){
            perror("Error : ");
        }
        else{
            printf("%s",cwd);
        }
    }
    printf("\n");
}

void echon(char **input_array, int size){
    int i = 2;
    while (i < size)
    {
        if (input_array[i] != NULL)
        {
            printf("%s ", input_array[i]);
        }
        i++;
    }
}

void echoE(char **input_array, int size){

    // {"echo","-E","input"}
    int i = 2;

    while(input_array[i] != NULL){
        for(int j=0;j<strlen(input_array[i]);j++){
            // printf("%c\n",input_array[i][j]);
            if(input_array[i][j] == '/')
            {
                continue;
            }
            else{
                printf("%c",input_array[i][j]);
            }
        }
        printf(" ");
        i++;
    }
    printf("\n");
}

void echo(char** input_array,int size){
    if(input_array[1] != NULL){
        if(strcmp(input_array[1],"-n") == 0){
            echon(input_array,size);
        }
        else if(strcmp(input_array[1],"-E") == 0){
            echoE(input_array,size);
        }
        else if(strcmp(input_array[1],"--help") == 0){
            printf("This command is used to print input given after echo");
        }
        else{
            int i;
            for(i=1;i<size;i++){
                printf("%s ",input_array[i]);
            }
            printf("\n");
        }
    }
    else{
        return;
    }
}

char* readline(){
    char* line = NULL;
    size_t n = 0;
    errno = 0;
    ssize_t l =getline(&line,&n,stdin);

    if(l < 0){
        if(errno){
            perror("Shell");
        }
        exit(1);
    }
    return line;
}

char** split_line(char* line){

    // line = string version of command
    // token = one word of the line 
    // tokens = string array of the words in line

    int length = 0;
    int capacity = 20;

    char* token;

    char** tokens = malloc(capacity*sizeof(char*));

    if(!tokens){
        perror("Shell!!");
        exit(1);
    }

    char *delimiters = " \t\r\n";

    token = strtok(line,delimiters);

    while(token != NULL){
        tokens[length] = token;
        length=length+1;

        if(length >= capacity){
            capacity = (int)(capacity*2);
            tokens = realloc(tokens,capacity*sizeof(char*));
            if(!tokens){
                perror("Shell!!");
                exit(1);
            }
        }

        token = strtok(NULL,delimiters);
    }   

    tokens[length] = NULL;
    return tokens;
}

int main(){
    while(true){
            printf(">>>");

            // size = size of tokenized array
            // line = command
            // innput array = tokenized array

            char* line = readline();
            char line2[1000];
            strcpy(line2,line);
            char** input_array = split_line(line2);

            int size = 0;
            int i=0;
            while(input_array[i] != NULL){
                size++;
                i++;
            }
            if(strcmp(input_array[0],"cd") == 0){
                cd(input_array);
            }
            else if(strcmp(input_array[0],"pwd") == 0){
                pwd(input_array);
            }
            else if(strcmp(input_array[0],"echo") == 0){
                echo(input_array,size);
            }
            else if(strcmp(input_array[0],"exit") == 0){
                printf("SHELL TERMINATED\n");
                break;
            }
            else if(strcmp(input_array[0],"ls") == 0){
                    pid_t pid;
                    pid = fork();

                    if (pid  == 0){   
                        char** args = (char**)malloc(100*sizeof(char*));
                        
                        args[0] = "./ls";

                        int i = 0;
                        while(input_array[i] != NULL){
                            args[i+1] = input_array[i];
                            i++;
                        }
                        args[i+1] = NULL;
        
                        execvp("./ls", args);
                        exit(0);
                    }
                    else{
                        wait(NULL);
                    }
            }
            else if(strcmp(input_array[0],"cat") == 0){
                    pid_t pid;
                    pid = fork();

                    if (pid  == 0){   
                        char** args = (char**)malloc(100*sizeof(char*));
                        
                        args[0] = "./cat";

                        int i = 0;
                        while(input_array[i] != NULL){
                            args[i+1] = input_array[i];
                            i++;
                        }
                        args[i+1] = NULL;
        
                        execvp("./cat", args);
                        exit(0);
                    }
                    else{
                        wait(NULL);
                    }
            }
            else if(strcmp(input_array[0],"date") == 0){
                     pid_t pid;
                    pid = fork();

                    if (pid  == 0){   
                        char** args = (char**)malloc(100*sizeof(char*));
                        
                        args[0] = "./date";

                        int i = 0;
                        while(input_array[i] != NULL){
                            args[i+1] = input_array[i];
                            i++;
                        }
                        args[i+1] = NULL;
        
                        execvp("./date", args);
                        exit(0);
                    }
                    else{
                        wait(NULL);
                    }
            }
            else if(strcmp(input_array[0],"rm") == 0){
                     pid_t pid;
                    pid = fork();

                    if (pid  == 0){   
                        char** args = (char**)malloc(100*sizeof(char*));
                        
                        args[0] = "./rm";

                        int i = 0;
                        while(input_array[i] != NULL){
                            args[i+1] = input_array[i];
                            i++;
                        }
                        args[i+1] = NULL;
        
                        execvp("./rm", args);
                        exit(0);
                    }
                    else{
                        wait(NULL);
                    }
            }
            else if(strcmp(input_array[0],"mkdir") == 0){
                     pid_t pid;
                    pid = fork();

                    if (pid  == 0){   
                        char** args = (char**)malloc(100*sizeof(char*));
                        
                        args[0] = "./mkdir";

                        int i = 0;
                        while(input_array[i] != NULL){
                            args[i+1] = input_array[i];
                            i++;
                        }
                        args[i+1] = NULL;
        
                        execvp("./mkdir", args);
                        exit(0);
                    }
                    else{
                        wait(NULL);
                    }
            }

            else if(strcmp(input_array[0],"&t") == 0){
                if(strcmp(input_array[1],"ls") == 0){
                    pthread_t tid;
                    pthread_create(&tid,NULL,thread_ls,line);
                    pthread_join(tid,NULL);
                }
                else if(strcmp(input_array[1],"cat") == 0){
                    pthread_t tid;
                    pthread_create(&tid,NULL,thread_cat,line);
                    pthread_join(tid,NULL);
                }
                else if(strcmp(input_array[1],"date") == 0){
                    pthread_t tid;
                    pthread_create(&tid,NULL,thread_date,line);
                    pthread_join(tid,NULL);
                }
                else if(strcmp(input_array[1],"rm") == 0){
                    pthread_t tid;
                    pthread_create(&tid,NULL,thread_rm,line);
                    pthread_join(tid,NULL);
                }
                else if(strcmp(input_array[1],"mkdir") == 0){
                    pthread_t tid;
                    pthread_create(&tid,NULL,thread_mkdir,line);
                    pthread_join(tid,NULL);
                }
            }
            else{
                printf("%s", "Error: Unrecognised Command");
            }
            free(input_array);
            free(line);
    }
}