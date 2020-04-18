#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "deplacement.h"

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
enum {HAUT, BAS, DROITE, GAUCHE};

void jouer(SDL_Surface* ecran)
{
	SDL_Surface *perso[4] = {NULL};
	SDL_Surface *persoActuel = NULL;
	SDL_Rect positionJoueur;
	SDL_Event event;

	 int continuer = 1, i=0;
	 perso[HAUT] = IMG_Load("HAUT.bmp");
	 perso[BAS] = IMG_Load("BAS.bmp");
	 perso[DROITE] = IMG_Load("DROITE.bmp");
	 perso[GAUCHE] = IMG_Load("GAUCHE.bmp");
	 persoActuel = perso[BAS];

	 SDL_EnableKeyRepeat(100, 100);
	 while (continuer)
	 {
		 SDL_WaitEvent(&event);
		 switch (event.type)
		 {
			 case SDL_QUIT:
			 	continuer = 0;
				break;
			 case SDL_KEYDOWN:
			  	switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						continuer = 0;
						break;
					case SDLK_UP:
						persoActuel = perso[HAUT];
						deplacerJoueur(&positionJoueur, HAUT);
						break;
					case SDLK_DOWN:
						persoActuel = perso[BAS];
						deplacerJoueur(&positionJoueur, BAS);
						break;
					case SDLK_RIGHT:
						persoActuel = perso[DROITE];
						deplacerJoueur(&positionJoueur, DROITE);
						break;
					case SDLK_LEFT:
						persoActuel = perso[GAUCHE];
						deplacerJoueur(&positionJoueur, GAUCHE);
						break;
				}
			break;
		 }
	 }
	 SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	 SDL_BlitSurface(persoActuel, NULL, ecran, &positionJoueur);
	 SDL_Flip(ecran);
	 SDL_EnableKeyRepeat(0, 0);
	 for (i = 0 ; i < 4 ; i++)
		 SDL_FreeSurface(perso[i]);
}

void deplacerJoueur(SDL_Rect *pos, int direction)
{
	switch(direction)
	{
		case HAUT:
			if (pos->y - 1 < 0)
				break;
			pos->y--;
			break;
		case BAS:
			if(pos->y + 1 >= HAUTEUR_FENETRE)
				break;
			pos->y++;
		case GAUCHE:
			if (pos->x - 1 < 0)
				break;
			pos->x--;
		case DROITE:
			if (pos->x + 1 >= LARGEUR_FENETRE)
				break;
			pos->x++;
	}
}
