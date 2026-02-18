#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/


void process(){
    printf("pid = %d\n",getpid());
    printf("ppid = %d\n",getppid());
    printf("pgrp = %d\n",getpgrp());
    printf("login = %s\n",getlogin());
    printf("uid = %d\n",getuid());
    printf("gid = %d\n",getgid());

}


int main(int argc, char* argv[]){
    int fils;
    fils = fork();
    switch (fils)
    {
    case (-1):
        perror("fork");
        break;
    case (0):
        printf("je suis le fils je termine avec le code 0;  \n");
        process();
        exit(0);
        break;

    default:
        wait(&fils);
        printf("je suis le pere\n");
        process();
        printf("code retour du fils %d et le miens c'est 1\n",WEXITSTATUS(fils));
        exit(1);
        break;
    }


}