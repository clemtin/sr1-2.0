#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/



int main(int argc, char* argv[]){
    if(argc!=3){
        fprintf(stdout,"Usage ./%s lecture ecriture",argv[0]);
    }
    char* lec = argv[1];
    char* ecr =  argv[2];
    while(512==read(lec,ecr,512)){

    }
}

