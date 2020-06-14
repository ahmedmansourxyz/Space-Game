#include "fonction3.h"



void enigme3(SDL_Surface *screen,int *rep)
{
  
SDL_Surface *enigme = NULL,*gameover , *goodjob;
 

 enigme = IMG_Load("enigme3.png");



SDL_Rect p_enigme3;

p_enigme3.x = 0;
p_enigme3.y = 0;

SDL_Rect p_gover;

p_gover.x = 0;
p_gover.y = 0;
 gameover = IMG_Load("failed.png");

SDL_Rect p_goodjob;

p_goodjob.x = 120;
p_goodjob.y = 200;
 goodjob = IMG_Load("goodjob.jpeg");


SDL_Event event4;
int conti = 1;

while(conti)
{
SDL_BlitSurface(enigme,NULL,screen,&p_enigme3);
SDL_Flip(screen);
SDL_WaitEvent(&event4);

switch(event4.type)
{
case SDL_QUIT:
   conti = 0;
  break;


case SDL_MOUSEBUTTONUP:
if(event4.button.button==SDL_BUTTON_LEFT)
{
 
if(event4.button.x>53 && event4.button.x<156 && event4.button.y>293 && event4.button.y<323 )
{
*rep=1;
SDL_BlitSurface(goodjob,NULL,screen,&p_goodjob);
SDL_Flip(screen);
SDL_Delay(3000);
conti=0;
}
else
{
*rep=0;
SDL_BlitSurface(gameover,NULL,screen,&p_gover);
SDL_Flip(screen);
SDL_Delay(3000);
conti=0;

}
}
break;




}
}
}

void pause();

int main (int argc, char *argv[])
{SDL_Surface *screen=NULL;
int rep=-1;
  SDL_Init(SDL_INIT_VIDEO);
  if(!SDL_Init)
  {
    printf("erreur de chargement de la bibliotheque image : > %s",SDL_GetError());
  }
  
 screen = SDL_SetVideoMode(500,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
 if(!screen)
 {
   printf("erreur de chargement de l'ecran : > %s",SDL_GetError());
 }
	

 enigme3(screen,&rep);
	
 pause();
  //liberer la memoire
 SDL_FreeSurface(screen);
 SDL_Quit();	
	
 }

void pause()
{
  int continuer = 1;
  SDL_Event event;
  while (continuer)
  {
   SDL_WaitEvent(&event);
   switch(event.type)
   {
    case SDL_QUIT:
      continuer = 0;
   }
  }
}

