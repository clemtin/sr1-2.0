#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/


int main(int argc, char* argv[]){
    printf("Maintenant: ");
    fflush(stdout);
    execlp("date","date",NULL);
    /* pas affiché car execlp remplace le code par la fonction date */
    printf("Terminé\n");
}