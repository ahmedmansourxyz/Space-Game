#include <time.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "bot.h"
#include "perso.h"
#include "GameState.h"
#include "xo.h"


#define HAUT	0
#define DROITE	1
#define BAS	2
#define GAUCHE	3

#define AUCUNE_DIRECTION	0
#define DIRECTION_HAUT		1
#define DIRECTION_DROITE	2
#define DIRECTION_BAS		4
#define DIRECTION_GAUCHE	8

#define LARGEUR_ECRAN 1280
#define HAUTEUR_ECRAN 480

int main(int argc, char *argv[])
{
    freopen( "CON", "w", stdout );
    freopen( "CON", "w", stderr );

	SDL_Surface *ecran;
	SDL_Event event;
	int continuer = 0;
	Uint32 temps_courant, prochain_rendu = 0;
	Sprite Perso;
    int changement_direction1;
 	SDL_Surface *background = NULL;
	SDL_Rect posblit={640,0};



	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
	{
		fprintf(stderr, "Echec d'initialisation de SDL.\n");
		return 1;
	}
	ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
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

	//Etat du jeu
	state = Play; //global, declaré dans GameState.h

	//PLAYER
	Perso.dest.x = 304;
	Perso.dest.y = 260;
	Direction_Perso( &Perso, DIRECTION_BAS );
	Direction_Perso( &Perso, AUCUNE_DIRECTION );
 	background = IMG_Load("back.jpg" );

 	//Bot (voir bot.h)
    bot* bot;
    init_bot(bot,"mouse.png");

    //XO
    xo* xo;
    xo=init_xo("xo.png");
    int trig=1;


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


                // XO
                /*case SDLK_x:
                    if(state==Play)
                        {state=XO;xo->canplay=1;}
                    else state=Play;
                    break;*/

                case SDLK_KP1:
                    if(state==XO)
                        put_xo(xo,1,bot);
                    break;

                case SDLK_KP2:
                    if(state==XO)
                        put_xo(xo,2,bot);
                    break;

                case SDLK_KP3:
                    if(state==XO)
                        put_xo(xo,3,bot);
                    break;

                case SDLK_KP4:
                    if(state==XO)
                        put_xo(xo,4,bot);
                    break;

                case SDLK_KP5:
                    if(state==XO)
                        put_xo(xo,5,bot);
                    break;

                case SDLK_KP6:
                    if(state==XO)
                        put_xo(xo,6,bot);
                    break;

                case SDLK_KP7:
                    if(state==XO)
                        put_xo(xo,7,bot);
                    break;

                case SDLK_KP8:
                    if(state==XO)
                        put_xo(xo,8,bot);
                    break;

                case SDLK_KP9:
                    if(state==XO)
                        put_xo(xo,9,bot);
                    break;


                default :
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
                default :
                    break;

					}
				break;

			case SDL_QUIT:
				continuer = 1;
				break;

			default:
				break;
			}


        /*if(state==XO)
            xo->canplay=1;*/
		}

		/* On recupère le temps écoulé en mili-secondes */
		temps_courant = SDL_GetTicks();

		/* On regarde s'il est temps d'effectuer le prochain rendu */
		if (temps_courant > prochain_rendu)
		{
			/* un rendu toutes les 20 milli-secondes = 50 images par secondes */
			prochain_rendu = temps_courant + 20;

			if(state==Play)
            {
                move_bot(bot,Perso.dest);

                miseAJourSprite( &Perso);

            }

            else if(state==XO)
            {
                if(bot->alive)
                    xo->canplay=1;
                bot_xo(xo,bot);
            }


			SDL_FillRect(ecran, NULL, 0);

			SDL_BlitSurface( background, NULL,  ecran,NULL );

			afficher_bot(bot,ecran);

			Afficher_Perso( &Perso, ecran );

			if(state==XO)afficher_xo(xo,ecran);

            SDL_Flip(ecran);

		}

	}

	Supprimer_Perso( &Perso );
	free_bot(bot);
	SDL_Quit();
	return 0;
}


