#define _POSIX_C_SOURCE 200809L     /* POur nomre Posix 1.2017 */
#include <unistd.h>
#include <stdio.h>                  /* pour print f*/
#include <stdlib.h>                 /* pour le exit */
#include <errno.h>                  /* include le erno*/


int main(int argc, char* argv[]){
    int pid;
    for(int i =0;i<2;i++){
        switch (pid = fork())
        {
        case -1:
            perror("Echec fork");
            break;
        
        case 0:
            if(i==0)
                execlp("ls","ls","-l",NULL);
            else{
                execlp("pwd","pwd",NULL);
            }
            break;
        
        default:
            wait(NULL);
        }   
    }
}