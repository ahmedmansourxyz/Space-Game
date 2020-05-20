#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "time.h"
#include "SDL/SDL.h"
#include <math.h>

typedef struct
{
SDL_Surface *screen;
SDL_Surface *background;
SDL_Rect *p;
  
int n;
int fact;
int rep;

}enigme;



int generate_question(enigme *enig);
void init_question(enigme enig,SDL_Surface *screen);
int resolution_factoriel(enigme enig);
int reponse(int *quit);
void afficher_resultat (SDL_Surface *screen, enigme enig);



