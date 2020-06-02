#include <time.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"

#define HAUT	0
#define DROITE	1
#define BAS	2
#define GAUCHE	3

#define AUCUNE_DIRECTION	0
#define DIRECTION_HAUT		1
#define DIRECTION_DROITE	2
#define DIRECTION_BAS		4
#define DIRECTION_GAUCHE	8

#define LARGEUR_ECRAN 500
#define HAUTEUR_ECRAN 480

int main()
{
	SDL_Surface *ecran;
	SDL_Event event;
	int continuer = 0;
	Uint32 temps_courant, prochain_rendu = 0;
	Sprite Perso,Perso1;
    int changement_direction1;
	
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "Echec d'initialisation de SDL.\n");
		return 1;
	}
	ecran = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	printf ("init secene");

		if ( ecran == NULL )
	{
		fprintf(stderr, "Echec de changement du mode video : %s.\n", SDL_GetError());
		return 1;
	}
	if ( !Inistialiser_Perso( &Perso, "perso.bmp" ) )
	{
		SDL_Quit();
		return 1;
	}
	if ( !Inistialiser_Perso( &Perso1, "perso.bmp" ) )
	{
		SDL_Quit();
		return 1;
	}

	//PLAYER
	Perso.dest.x = 304;
	Perso.dest.y = 260;
	Direction_Perso( &Perso, DIRECTION_BAS );
	Direction_Perso( &Perso, AUCUNE_DIRECTION );

	//PLAYER1
	Perso1.dest.x = 304;
	Perso1.dest.y = 260;
	Direction_Perso( &Perso1, DIRECTION_BAS );
	Direction_Perso( &Perso1, AUCUNE_DIRECTION );


	while (!continuer)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					continuer = 1;
					break;
				case SDLK_UP:
					Direction_Perso( &Perso, DIRECTION_HAUT );
					break;
				
				case SDLK_RIGHT:
					Direction_Perso( &Perso, DIRECTION_DROITE );
					break;
				
				case SDLK_DOWN:
					Direction_Perso( &Perso, DIRECTION_BAS );
					break;
				
				case SDLK_LEFT:
					Direction_Perso( &Perso, DIRECTION_GAUCHE );
					break;
				
				
				}
				break;
			
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case SDLK_UP:
					if (Perso.direction == DIRECTION_HAUT)
						Direction_Perso( &Perso, AUCUNE_DIRECTION );
					break;
				
				case SDLK_RIGHT:
					if (Perso.direction == DIRECTION_DROITE)
						Direction_Perso( &Perso, AUCUNE_DIRECTION );
					break;
				
				case SDLK_DOWN:
					if (Perso.direction == DIRECTION_BAS)
						Direction_Perso( &Perso, AUCUNE_DIRECTION );
					break;
				
				case SDLK_LEFT:
					if (Perso.direction == DIRECTION_GAUCHE)
						Direction_Perso( &Perso, AUCUNE_DIRECTION );
					break;
				}
				break;

			case SDL_QUIT:
				continuer = 1;
				break;
			
			default:
				;
			}


		}
		
		/* On recupère le temps écoulé en mili-secondes */
		temps_courant = SDL_GetTicks();
		
		/* On regarde s'il est temps d'effectuer le prochain rendu */
		if (temps_courant > prochain_rendu)
		{
			/* un rendu toutes les 20 milli-secondes = 50 images par secondes */
			prochain_rendu = temps_courant + 20;
                        // d'abords les directions du sprite de l'Ennemie

			miseAJourSprite( &Perso1);
            miseAJourSprite( &Perso);
			SDL_FillRect(ecran, NULL, 0);
			Afficher_Perso( &Perso, ecran );
            Afficher_Perso( &Perso1, ecran );	
			/* On met à jour de la zone d'affichage de la fenetre */
			SDL_UpdateRect(ecran, 0, 0, 0, 0);
		}
		
	}

	Supprimer_Perso( &Perso );
	Supprimer_Perso( &Perso1 );
	SDL_Quit();
	return 0;
}


