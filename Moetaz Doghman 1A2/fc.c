#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "fc.h"
enemy deplacement_aleatoire(enemy enemyy)
{ 
 if (enemyy.direction % 2 ==1){  if (enemyy.posen.x<enemyy.position_initiale + enemyy.distance ) {enemyy.posen.x+=10;   }
         else  { enemyy.direction++; } }
        else if (enemyy.direction % 2 ==0)
              {  if (enemyy.posen.x>enemyy.position_initiale ) {enemyy.posen.x-=10;   }
         else  { enemyy.direction++; } }  
   return (enemyy) ;   
}

enemy intialisation_enemy(enemy enemyy)
{
enemyy.posen.x=450;enemyy.posen.y=637; //638.5
enemyy.distance=570;
enemyy.position_initiale=450;
enemyy.direction = 1;
enemyy.en=IMG_Load("en1.png");
 return (enemyy) ; 
}

personnage initialisation_perso(personnage perso)
{
perso.posperso.x=400;perso.posperso.y=637; //638.5
perso.perso=IMG_Load("pers.png");
perso.h=61;
perso.w=64;
 return (perso) ; 
}
box initialisation_box(box nar)
{
nar.posbox.x=200;nar.posbox.y=600; //638.5

nar.box=IMG_Load("feu.png");
 return (nar) ; 
}



void afficher (enemy enemy1,SDL_Surface *ecran)
{SDL_BlitSurface( enemy1.en,NULL,ecran,&enemy1.posen);}

void afficher_nar (box nar,SDL_Surface *ecran)
{
  SDL_BlitSurface( nar.box,NULL,ecran,&nar.posbox);
}

void afficher_perso (personnage perso ,box nar,SDL_Surface *ecran,int *d)
{
  if ((nar.posbox.x==perso.posperso.x))
    *d=2;
 if (*d!=2){SDL_BlitSurface( perso.perso,NULL,ecran,&perso.posperso);}
}
