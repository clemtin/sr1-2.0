#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/


#define NBMOTSMAX 20

int Decoupe(char Chaine[], char *pMots[])
{
  char *p;
  int NbMots=0;

  p=Chaine;	/* On commence par le début */
  /* Tant que la fin de la chaîne n'est pas atteinte et qu'on ne déborde pas */
  while ((*p)!='\0' && NbMots<NBMOTSMAX)
  {
    while ((*p)==' ' && (*p)!='\0') p++; /* Recherche du début du mot */
    if ((*p)=='\0') break;	/* Fin de chaîne atteinte */
    pMots[NbMots++]=p;		/* Rangement de l'adresse du 1er caractère du mot */
    while ((*p)!=' ' && (*p)!='\0') p++; /* Recherche de la fin du mot */
    if ((*p)=='\0') break;	/* Fin de chaîne atteinte */
    *p='\0';			/* Marquage de la fin du mot */
    p++;			/* Passage au caractère suivant */
  }
  pMots[NbMots]=NULL;		/* Dernière adresse */
  return NbMots;
}


int main(int argc, char* argv[]){
    if(argc<1){
        fprintf(stderr,"Usage %s cmd1 [cmd2 ...]",argv[0]);
        exit(1);
    }
    int i;
    int fils;
    char* pMots[NBMOTSMAX+1];
    for(i=1;i<argc;i++){
        fils = fork();
        switch (fils)
        {
        case -1:
            perror("fork");
            break;
        case 0:
            Decoupe(argv[i],pMots);
            printf("fils: %d va exec %s\n",fils,argv[1]);
            execvp(pMots[0],pMots);
            perror(pMots[0]);
            exit(3);

            
        default:
            printf("pere: [%d] J’ai delegue %s a [%d]. J’attends sa fin..\n",getpid(),argv[i],fils);
  
            break;
        }


    }
    for(int j=0;j<argc;j++){
        
        wait(&fils);

    }

}