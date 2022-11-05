#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void LS()
{
    struct dirent **names;
    int n;
    n = scandir(".", &names, NULL, alphasort);

    int i = 0;
    if (n < 0)
    {
        perror("scandir");
    }
    else
    {
        while (i < n)
        {
            if (names[i]->d_name[0] == '.')
            {
                free(names[i++]);
                continue;
            }
            printf("%s ", names[i]->d_name);
            free(names[i++]);
        }
        printf("\n");
        free(names);
    }
}

void lsa(){
    struct dirent **names;
    int n;
    n = scandir(".", &names, NULL, alphasort);
    
    int i = 0;
    if (n < 0)
    {
        perror("scandir");
    }
    else
    {
        while (i < n)
        {
            printf("%s ", names[i]->d_name);
            free(names[i++]);
        }
        printf("\n");
        free(names);
    }
}

void lsm(){
    struct dirent **names;
    int n;
    n = scandir(".", &names, NULL, alphasort);

    int i = 0;
    if (n < 0)
    {
        perror("scandir");
    }
    else
    {
        while (i < n)
        {
            if (names[i]->d_name[0] == '.')
            {
                free(names[i++]);
                continue;
            }
            printf("%s ,", names[i]->d_name);
            free(names[i++]);
        }
        printf("\n");
        free(names);
    }
}

int main(int argc,char* argv[]){

        if(argc == 2){
            // ls 
            LS();
        }
        else if(argc == 3){
            // ls -a
            // ls -m
            if(argv[2][1] == 'a'){
                lsa();
            }
            else if(argv[2][1] == 'm'){
                lsm();
            }
            else{
                printf("Command not supported \n");
            return 1;
        } 
        }
}