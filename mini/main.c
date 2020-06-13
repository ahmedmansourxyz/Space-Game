#include <SDL/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
/**
* @file main.c
* @brief mini map
* @author Moetaz Doghman
* @version 1.0
* @date June ,13 2020
*
* Affichage de mini map
*
*/

int main()
{
	SDL_Surface *screen=NULL;
	SDL_Surface *perso=NULL;
	SDL_Surface *map=NULL;
	int done=0;
	SDL_Surface *miniperso=NULL;
	SDL_Event event;
	SDL_Surface *minimap=NULL;
	SDL_Rect positionperso, positionFond, positionminiperso, positionminimap;
	positionperso.x=50;
	positionperso.y=400;
	positionminiperso.x=903;
	positionminiperso.y=71;
	SDL_Init(SDL_INIT_VIDEO);
	positionminimap.x=900;
	positionminimap.y=50;
	screen = SDL_SetVideoMode(1100,800, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("MINIMAP", NULL);  
	perso = IMG_Load("perso.png");
	map = IMG_Load("map.jpg");
	minimap = IMG_Load("minimap.jpg");
	miniperso = IMG_Load("miniperso.png");
	SDL_EnableKeyRepeat(50,50);
	while  ( done==0 )  { 
		while  (SDL_PollEvent ( &event ))  
		{ 
	        switch  ( event.type )  
	        { 
	            case  SDL_QUIT : 
	                done  =  1 ; 
	                break ;  
	                 
	            case SDL_KEYDOWN : 
	                switch( event.key.keysym.sym )
	                    {
	      				case SDLK_RIGHT : 
							positionperso.x+=10; 
							positionminiperso.x+=1; 
							SDL_BlitSurface(map,NULL,screen,NULL);
							SDL_BlitSurface(perso,NULL,screen,&positionperso);   
							SDL_BlitSurface(minimap,NULL, screen, &positionminimap);
							SDL_BlitSurface(miniperso,NULL,screen,&positionminiperso);
							SDL_Flip(screen) ; 
							break ; 
						case SDLK_LEFT : 
							positionperso.x-=10 ; 
							positionminiperso.x-=1 ; 
							SDL_BlitSurface(map,NULL,screen,NULL); 
							SDL_BlitSurface(perso,NULL,screen,&positionperso); 
							SDL_BlitSurface(minimap,NULL, screen, &positionminimap);
							SDL_BlitSurface(miniperso,NULL,screen,&positionminiperso);
							SDL_Flip(screen) ; 
							break ; 
						case SDLK_UP : 
							positionperso.y-=10 ; 
							positionminiperso.y-=1 ; 
							SDL_BlitSurface(map,NULL,screen,NULL); 
							SDL_BlitSurface(perso,NULL,screen,&positionperso); 
							SDL_BlitSurface(minimap,NULL, screen, &positionminimap);
							SDL_BlitSurface(miniperso,NULL,screen,&positionminiperso);
							SDL_Flip(screen) ; 
							break ; 
						case SDLK_DOWN : 	
								positionperso.y+=10 ; 
								positionminiperso.y+=1 ; 
								SDL_BlitSurface(map,NULL,screen,NULL); 
								SDL_BlitSurface(perso,NULL,screen,&positionperso); 
								SDL_BlitSurface(minimap,NULL, screen, &positionminimap);
								SDL_BlitSurface(miniperso,NULL,screen,&positionminiperso);
								SDL_Flip(screen) ; 
							break ;
						}
			}
		}
	}
	 SDL_Quit();
	return 0 ; 
}
