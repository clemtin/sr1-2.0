#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/


#define NBPROC 4    /* NBR DE PROCESSUS FILS*/
#define N 10


void affichage(pid_t pid){
    for(int k=0;k<N;k++){

        sleep(1);
    }
}

int main(int agrc,char* argv[]){

    int successeur;
    int i;
    int pidfils;

    for(i=NBPROC;i>0;i--){
        pidfils = fork();
        if(pidfils==-1){
            perror("Echec fork");
            exit(1);
        }
        else if(pidfils==0){
            printf("je suis le fils %d: je m'apelle %d mon successeur est %d.\n",i,(int)getpid(),(int)successeur);
            affichage(getpid());
            printf("%d j'ai fini ! \n",(int)getpid());
            exit(i);
        }
        successeur=pidfils;
        }

        printf("Je suis le pere; je m'apelle %d mon sucesseur est %d.\n",(int)getpid(),(int)successeur);
        
        pid_t fils_terminer; /* id fils terminés*/
        int circonsrtance;
        /* pere attends que tous ses fils soient termines */

        while((fils_terminer=wait(&circonsrtance))!=-1)
            printf("[%d] :Mon fils %d est terminé avec le code %d.\n",(int)getpid(),(int)fils_terminer,WEXITSTATUS(circonsrtance));

    printf("[%d] : Tous mes fils sont terminés, adieu.\n", (int)getpid());
    exit(0);
}

