#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "SDL/SDL.h"

#include<math.h>
#include "enigme.h"

#include "SDL/SDL_ttf.h"

int main(void)
{

enigme enig;
SDL_Surface *screen,*background;
int *p,*n, *fact, *rep;
int quit=1;
SDL_Init(SDL_INIT_VIDEO);
screen = SDL_SetVideoMode(952,535,24,SDL_HWSURFACE | SDL_DOUBLEBUF);
SDL_WM_SetCaption( "enigmes dynamique", NULL );
int temps;
temps = SDL_GetTicks();

enig.n=generate_question(&enig);

init_question(enig,screen);

enig.fact=resolution_factoriel(enig);

enig.rep=reponse(&quit);

if  (temps>=30)
{
   printf("Temps Perdu");
   SDL_Delay(30);
}

printf("la reponse est %d le factoriel est %d ",enig.rep,enig.fact);
if(quit==1)
{
	afficher_resultat (screen,enig);
}
SDL_Quit();
return 0;

}
