#include <SDL/SDL.h>

#include "bot.h"
#include "outils.h"

int init_bot(bot* bot,char* img)
{
    bot->botS=LoadPNG(img);
    bot->botR.h=bot->botS->h;
    bot->botR.w=bot->botS->w;
    bot->botR.x=300;
    bot->botR.y=100;
    bot->yfix=100;
    bot->lim_g=200;
    bot->lim_d=400;
    bot->lim_h=0;
    bot->lim_b=250;
    bot->dir=-1;
    bot->follow=0;
    bot->pdist=50;
    bot->alive=1;
}

int sign(int x)
{
    return (x > 0) - (x < 0);
}

void move_bot(bot* bot,SDL_Rect persoR)
{

    if(bot->botR.x<bot->lim_g)
        bot->dir=1;
    if(bot->botR.x>bot->lim_d)
        bot->dir=-1;

    if(!bot->follow)
    {
        bot->botR.x+=bot->dir;
    }
    else
    {
        bot->botR.x+=sign((persoR.x+persoR.w/2)-(bot->botR.x+bot->botR.w/2));

        bot->botR.y+=sign((persoR.y+persoR.h/2)-(bot->botR.y+bot->botR.h/2));
    }


    if(bot->pdist>abs((persoR.x+persoR.w/2)-(bot->botR.x+bot->botR.w/2)) && bot->pdist>abs((persoR.y+persoR.h/2)-(bot->botR.y+bot->botR.h/2)))
        bot->follow=1;
    else
        bot->follow=0;

    /*if(bot->botR.y<bot->lim_h || bot->botR.y>bot->lim_b)
        bot->follow=0;*/

    if(aabb(bot->botR,persoR) && bot->alive) //check collision and bot
        state=XO;



}

void afficher_bot(bot* bot,SDL_Surface* screen)
{
    if(bot->alive)
        SDL_BlitSurface(bot->botS,0,screen,&bot->botR);
}

void free_bot(bot* bot)
{
    SDL_FreeSurface(bot->botS);
}
