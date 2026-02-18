#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/

int main(int argc, char* argv[]){


    int fils = fork();
    switch (fils)
    {
    case (-1):
        perror("fork");
        break;
    case (0):
        execlp("ls","ls","-al",NULL);
    default:
        wait(&fils);
        execlp("date","date",NULL);
        break;
    }
}