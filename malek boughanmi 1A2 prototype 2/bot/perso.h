
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

typedef struct
{
	// pour l'affichage
	SDL_Surface *image;
	SDL_Rect source;
	SDL_Rect dest;
	// taille du sprite

	int largeur;
	int hauteur;

	// direction dans laquelle se deplace le sprite
	int direction;

	// vitesse du sprite
	int vitesse;
	
	// pour la gestion des animations
	
	// si le sprite est anime
	int anim;
	
	// direction dans laquelle est orienté le sprite
	int orientation;

	// animation courante du sprite
	int anim_courante;

	// le temps que dure une animation
	int temps_anim;

	// le temps de l'animation courante
	int temps_anim_courante;

	// nombre d'animations du sprite
	int total_anims;

}Sprite;





SDL_Surface *loadBmp(const char *fichier);
int Inistialiser_Perso( Sprite *sprite, const char *image );
void Supprimer_Perso( Sprite *sprite );
void Direction_Perso( Sprite *sprite, int direction );
void miseAJourSprite( Sprite *sprite );
void Afficher_Perso( Sprite *sprite, SDL_Surface *destination );
