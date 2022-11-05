#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sysexits.h>
#include <errno.h>

void Date()
{
    time_t rawtime = time(NULL);
    if (rawtime == -1)
    {
        perror("Error is");
        return;
    }
    struct tm *ptm;
    char buf1[4], buf2[4], buf3[6];
    ptm = localtime(&rawtime);
    if (ptm == NULL)
    {
        perror("Error is");
        return;
    }
    strftime(buf1, 4, "%a", ptm);
    strftime(buf2, 4, "%b", ptm);
    strftime(buf3, 6, "%z", ptm);
    printf("%s %s %02d %02d:%02d:%02d %s %d\n", buf1, buf2, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, buf3, ptm->tm_year + 1900);
}

void Date_U()
{
    time_t rawtime = time(NULL);
    if (rawtime == -1)
    {
        perror("Error");
        return;
    }
    struct tm *ptm;
    char buf1[4], buf2[4], buf3[6];
    ptm = gmtime(&rawtime);
    if (ptm == NULL)
    {
        perror("Error");
        return;
    }
    strftime(buf1, 4, "%a", ptm);
    strftime(buf2, 4, "%b", ptm);
    strftime(buf3, 6, "%z", ptm);
    printf("%s %s %02d %02d:%02d:%02d UTC %d\n", buf1, buf2, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, ptm->tm_year + 1900);
}

void Date_R()
{
    time_t rawtime = time(NULL);
    if (rawtime == -1)
    {
        perror("Error");
        return;
    }
    struct tm *ptm;
    char buf1[4], buf2[4], buf3[6];
    ptm = localtime(&rawtime);
    if (ptm == NULL)
    {
        perror("Error");
        return;
    }
    strftime(buf1, 4, "%a", ptm);
    strftime(buf2, 4, "%b", ptm);
    strftime(buf3, 6, "%z", ptm);
    printf("%s, %02d %s %d %02d:%02d:%02d %s\n", buf1, ptm->tm_mday, buf2, ptm->tm_year + 1900, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, buf3);
}

int main(int argc, char *argv[])
{
    // ./date date
    // ./date date -u
    // ./date date -R

    if(argc == 2){
        Date();
    }

    if(argc == 3){
        if(argv[2][1] == 'U'){
            Date_U();
        }
        else if(argv[2][1] == 'R'){
            Date_R();
        }
        else{
            printf("Command not supported!!");
        }
    }
}