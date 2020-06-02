#ifndef BOT_H_INCLUDED
#define BOT_H_INCLUDED

#include <SDL/SDL.h>
#include "GameState.h"


typedef struct
{
    SDL_Surface* botS; // bot surface
    SDL_Rect botR; //bot rect
    int dir; //direction
    int lim_g,lim_d; //limite x : gauche+droite
    int lim_h,lim_b; // limit haut, bas
    int yfix;
    int pdist; //distance player - bot pour attirer le bot
    int follow; //
    int alive;
}bot;


int init_bot(bot* bot,char* img); //initaliser le bot

void move_bot(bot* bot,SDL_Rect persoR); // movement et interaction avec le bot

void afficher_bot(bot* bot,SDL_Surface* screen);

void free_bot(bot* bot);

#endif // BOT_H_INCLUDED
