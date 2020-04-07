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


void resolution_Enigme3(int random,enigme *enigme3,player *joueur,TTF_Font *font,int *entree)
{
		if (enigme3->pos==0) 
		{
			enigme3->klamPos.x=150;
			enigme3->klamPos.y=250;
		}
		else if (enigme3->pos==1)
		{
			enigme3->klamPos.x=350;
			enigme3->klamPos.y=250;
		}
		else if (enigme3->pos==2)
		{
			enigme3->klamPos.x=550;
			enigme3->klamPos.y=250;
		}

		switch(random)
		{
			case 0:
			if (enigme3->pos==1 && *entree==1)
				{
					score(&(*joueur),font);
				} 
			break;
			case 1:
			if (enigme3->pos==0 && *entree==1)
				{
					
					score(&(*joueur),font);
				}
			break;
			case 2:
			if (enigme3->pos==1 && *entree==1)
				{
					
					score(&(*joueur),font);
				}
			break;
		}

		if ( *entree==1 )
		{
			enigme3->etat=0;
			joueur->enigme++;
			*entree=0;		
		}

		
}
