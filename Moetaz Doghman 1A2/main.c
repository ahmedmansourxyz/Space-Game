#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h> // librairies qui contient les fonctions
#include <SDL/SDL_image.h>
#include "main.h"
int main(int argc, char **argv[]) //Fonctions principales 
{  SDL_Event event;
int continuer =1;
int x,y;
 SDL_Init(SDL_INIT_VIDEO) ; 
 SDL_Surface *ecran = NULL ; 
SDL_Surface *lvl1 = NULL ; 
ecran= SDL_SetVideoMode(1120,700,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ; 
lvl1 = IMG_Load("back.png") ;
 enemy enemy1;

SDL_Rect positionDuFond  ;
positionDuFond.x= 0 ;
positionDuFond.y= 0 ;
 enemy1.posen.x=450;enemy1.posen.y=638.5;
enemy1.distance=570;
enemy1.position_initiale=450;
enemy1.direction = 1;
enemy1.en=IMG_Load("en1.png");



 
while (continuer)
{SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
             break;
 case SDL_MOUSEBUTTONUP:
                x=event.button.x;
                y=event.button.y;
break;
 }
  SDL_BlitSurface ( lvl1 , NULL , ecran , &positionDuFond) ;
  enemy1 = deplacement_aleatoire(enemy1);
 SDL_BlitSurface( enemy1.en,NULL,ecran,&enemy1.posen);
SDL_Flip(ecran);
      }


 // Mise à jour de l'écran avec sa nouvelle couleur
 
SDL_FreeSurface(lvl1);SDL_FreeSurface(enemy1.en);
SDL_Quit() ; // arreter SDL ;
}
