#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h> 
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "enigme.h"



void afficher_Enigme3(enigme *enigme3,SDL_Surface* ecran)
{
	SDL_BlitSurface(enigme3->background,NULL,ecran,NULL);
	SDL_BlitSurface(enigme3->klam,NULL,ecran,&enigme3->klamPos);
	SDL_BlitSurface(enigme3->Q,NULL,ecran,&enigme3->QPos);
	SDL_BlitSurface(enigme3->R,NULL,ecran,&enigme3->RPos);
	SDL_BlitSurface(enigme3->R2,NULL,ecran,&enigme3->R2Pos);
	SDL_BlitSurface(enigme3->R3,NULL,ecran,&enigme3->R3Pos);

	SDL_Flip(ecran);
}
