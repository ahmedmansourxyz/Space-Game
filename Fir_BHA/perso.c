

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

#define LARGEUR_ECRAN 640
#define HAUTEUR_ECRAN 480


SDL_Surface *loadBmp(const char *fichier)
{
	SDL_Surface *image;

	                        image = SDL_LoadBMP(fichier);
	                        if ( image == NULL )
	                        {
		                   fprintf(stderr, "Echec de chargement du fichier %s : %s.\n", fichier, SDL_GetError());
		                                                                                              return NULL;
	                        }
	return image;
}

int Inistialiser_Perso( Sprite *sprite, const char *image )
{
	sprite->image = loadBmp( image );
	if ( !sprite->image )
		return 0;
	SDL_SetColorKey( sprite->image, SDL_SRCCOLORKEY, SDL_MapRGB( sprite->image->format, 255,0,0 ) );
	sprite->anim = 0;
	// on commence par la première animation
	sprite->anim_courante = 0;
	sprite->total_anims = 4;

	// par défaut, le sprite est tourné vers le bas
	sprite->orientation = BAS;

	// chaque animation dure 5 affichages,on affiche une animation pendant 8 rafraichissement pour assurer plus de fluidité 
	sprite->temps_anim = 8;

	// Le temps qu'il reste à afficher l'animation courante
	sprite->temps_anim_courante = 0;

	// On definit ensuite les dimentions du sprite.
	sprite->largeur = 32;
	sprite->hauteur = 32;
	
	sprite->source.x = sprite->anim_courante * sprite->largeur;
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.w = sprite->largeur;
	sprite->source.h = sprite->hauteur;

	sprite->dest.x = 0;
	sprite->dest.y = 0;
	sprite->dest.w = sprite->largeur;
	sprite->dest.h = sprite->hauteur;
	
	// on definit enfin la vitesse et la direction du sprite
	sprite->vitesse = 2;
	sprite->direction = AUCUNE_DIRECTION;
	
	return 1;
}

void Supprimer_Perso( Sprite *sprite )
{
	SDL_FreeSurface( sprite->image );
}

void Direction_Perso( Sprite *sprite, int direction )
{
	// On affecte la direction au sprite
	sprite->direction = direction;
	
	if (direction != AUCUNE_DIRECTION)
	{
		sprite->anim = 1;
		switch (direction)
		{
		case DIRECTION_HAUT:
			sprite->orientation = HAUT;
			break;
			
		case DIRECTION_DROITE:
			sprite->orientation = DROITE;
			break;

		case DIRECTION_BAS:
			sprite->orientation = BAS;
			break;

		case DIRECTION_GAUCHE:
			sprite->orientation = GAUCHE;
			break;

		default:
			;
		}
	}
	else
		sprite->anim = 0;

	// on met la première animation
	sprite->anim_courante = 0;
	sprite->temps_anim_courante = 0;

	// on regle la source de l'image à copier
	sprite->source.y = sprite->orientation * sprite->hauteur;
	sprite->source.x = sprite->anim_courante * sprite->largeur;
}

void miseAJourSprite( Sprite *sprite )
{
	// le sprite vas vers le haut
	if (sprite->direction & DIRECTION_HAUT)
	{
		// on monte et on faut attention a ne pas sortie de l'ecran
		sprite->dest.y -= sprite->vitesse;
		if (sprite->dest.y < 0)
			sprite->dest.y = 0;
	}
	else if (sprite->direction & DIRECTION_DROITE)
	{
		// on va à droite et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x += sprite->vitesse;	
		if (sprite->dest.x + sprite->largeur > LARGEUR_ECRAN)	
			sprite->dest.x = LARGEUR_ECRAN - sprite->largeur;
	}
	else if (sprite->direction & DIRECTION_BAS)
	{
		// on descend et on faut attention a ne pas sortie de l'ecran
		sprite->dest.y += sprite->vitesse;	
		if (sprite->dest.y + sprite->hauteur > HAUTEUR_ECRAN)
			sprite->dest.y = HAUTEUR_ECRAN - sprite->hauteur;
	}
	else if (sprite->direction & DIRECTION_GAUCHE)
	{
		// on va à gauche et on fait attention a ne pas sortie de l'ecran
		sprite->dest.x -= sprite->vitesse;	
		if (sprite->dest.x < 0)
			sprite->dest.x = 0;
	}
}

void Afficher_Perso( Sprite *sprite, SDL_Surface *destination )
{
	/* si le sprite est animé, on gere l'animation */
	if (sprite->anim)
	{
		// on decremente le temps restant à l'animation courante
		sprite->temps_anim_courante--;
		// et on regarde s'il est temps de changer d'animation
		if ( sprite->temps_anim_courante <= 0 )
		{
			// s'il faut changer, on passe à l'animation suivante
			sprite->anim_courante++;
			// si on était à la dernière animation, on repasse à la première
			if (sprite->anim_courante >= sprite->total_anims)
				sprite->anim_courante = 0;
			
			// on regle la source à copier
			sprite->source.x = sprite->largeur * sprite->anim_courante;
			sprite->temps_anim_courante = sprite->temps_anim;
		}
	}
	
	// enfin, on affiche le sprite à l'ecran
	SDL_BlitSurface( sprite->image, &sprite->source, destination, &sprite->dest );
}


