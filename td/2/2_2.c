#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/


#define NBPROC 4    /* NBR DE PROCESSUS FILS*/
#define N 10


void affichage(pid_t pid){
    for(int k=0;k<N;k++){
        printf("[%d] Hello world! \n",(int)pid);
        sleep(1);
    }
}

int main(int agrc,char* argv[]){

    int successeur;
    int i;
    int pidfils;

    for(i=NBPROC;i>0;i--){
        pidfils = fork();
        switch (pidfils)
        {
        case -1:
            perror("Erreur fork");
            exit(i);
            break;
        case 0:
            printf("mon numéro = %d , son pid = %d et son successeur = %d \n",i,getpid(),successeur);
            break;
        default:
            successeur=pidfils;
            break;
        }
        
        }


        wait
    }

