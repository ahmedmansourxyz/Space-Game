#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h> // librairies qui contient les fonctions
#include <SDL/SDL_image.h>
#include "fc.h"
int main(int argc, char **argv[]) //Fonctions principales 
{  SDL_Event event;
int continuer =1,vie=3,die1=0,die2=0;
int x,y,d=1;
 SDL_Init(SDL_INIT_VIDEO) ; 
 SDL_Surface *ecran = NULL ; 
SDL_Surface *lvl1 = NULL ; 
ecran= SDL_SetVideoMode(1120,700,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ; 
lvl1 = IMG_Load("back.png") ;
 enemy enemy1;
 personnage perso;

enemy nar;
SDL_Rect positionDuFond  ;
positionDuFond.x= 0 ;
positionDuFond.y= 0 ;

enemy1=intialisation_enemy(enemy1) ;
perso=initialisation_perso(perso);
nar=initialisation_box(nar);

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
  case SDL_KEYDOWN:
{

                   switch(event.key.keysym.sym)
                   {
                   case SDLK_RIGHT:
               
                  perso.posperso.x+=5;
                break;
            case SDLK_LEFT:
               
 perso.posperso.x-=5;}}
   break;
  
 }
  SDL_BlitSurface ( lvl1 , NULL , ecran , &positionDuFond) ;
  enemy1 = deplacement_aleatoire(enemy1);
  
   die1=callenemy(perso, enemy1);
   die2=callenemy(perso,nar);
   
afficher (enemy1,ecran); 
  afficher_perso (perso,nar,ecran,&d);
  afficher_nar (nar,ecran);
      if ((die1 ==1)||(die2 ==1))
   {
        perso.posperso.x += 300;
      
      vie--; 

   }
SDL_Flip(ecran);
      }


 // Mise à jour de l'écran avec sa nouvelle couleur
 
SDL_FreeSurface(lvl1);SDL_FreeSurface(enemy1.en);
SDL_Quit() ; // arreter SDL ;
}
