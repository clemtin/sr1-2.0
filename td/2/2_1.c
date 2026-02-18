#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/



int main(int argc, char * argv[]){


    int pid = fork();
    if(pid==-1){
        perror("Echec d'appel fork");
        exit(1);
    }


    else if(pid){
        // père 
        printf("pere dit pid pere =%d\n",getpid());
    }

    else{
        printf("fils dit pid = %d et pere = %d \n",getpid(),getppid());

    }
    exit(0);
}
