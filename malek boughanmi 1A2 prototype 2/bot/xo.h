#ifndef XO_H_INCLUDED
#define XO_H_INCLUDED

#include <SDL/SDL.h>
#include "bot.h"

typedef struct
{
    SDL_Surface* xoS;
    SDL_Rect xoR;
    char tab[3][3];

    SDL_Surface* xoNum;
    int numW,numH;

    SDL_Surface* xoLtr;
    int ltrW,ltrH;

    unsigned int tour;
    unsigned int maxtour;
    int canplay;

}xo;

xo* init_xo(char* img);

void put_xo(xo* xo,int place,bot* bot);

void bot_xo(xo* xo,bot* bot);

void checkwin_xo(xo* xo,bot* bot);

void afficher_xo(xo* xo,SDL_Surface* screen);

void free_xo(xo* xo);

#endif // XO_H_INCLUDED
