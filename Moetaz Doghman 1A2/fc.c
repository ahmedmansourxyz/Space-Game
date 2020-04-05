#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdio.h>
#include "main.h"
enemy deplacement_aleatoire(enemy enemyy)
{ 
 if (enemyy.direction % 2 ==1){  if (enemyy.posen.x<enemyy.position_initiale + enemyy.distance ) {enemyy.posen.x+=10;   }
         else  { enemyy.direction++; } }
        else if (enemyy.direction % 2 ==0)
              {  if (enemyy.posen.x>enemyy.position_initiale ) {enemyy.posen.x-=10;   }
         else  { enemyy.direction++; } }  
   return (enemyy) ;   
}
