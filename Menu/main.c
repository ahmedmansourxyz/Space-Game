#include <stdlib.h>
#include <stdio.h> 
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
int main(void)
{
Mix_Music* music; //introduction musique 
if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
	printf("%s",Mix_GetError());
}
music=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(music,-1);


Mix_Chunk* sound=NULL; //introduction son bref 
sound = Mix_LoadWAV("pop.wav");


SDL_Color couleurNoire = {255, 255, 255}; 



int continuer=1;
SDL_Event event ; 

SDL_Surface *ecran ;
SDL_Surface *Fond;
SDL_Surface *bouttonplay;
SDL_Surface *bouttonsettings;
SDL_Surface *bouttoncredits;
SDL_Surface *bouttonexit; 
SDL_Surface *playbig;
SDL_Surface *settingsbig;
SDL_Surface *creditsbig;
SDL_Surface *exitbig;
SDL_Surface *retour ;
SDL_Surface *retourbig ;
SDL_Surface *fullscreen ;
SDL_Surface *fullscreenbig ;
SDL_Surface *audiofull ;
SDL_Surface *audiomute ;
SDL_Surface *settingsGUI ;
SDL_Surface *BarNoir; 
SDL_Surface *BarRouge; 
SDL_Surface *creditsGUI; 
SDL_Surface *texte ;
SDL_Surface *back1;
SDL_Surface *back2 ;
SDL_Surface *back3 ;
SDL_Surface *back4 ;


SDL_Rect positionFond ; 
SDL_Rect positionPlay ; 
SDL_Rect positionSettings ; 
SDL_Rect positionCredits ; 
SDL_Rect positionExit ; 
SDL_Rect positionPlaybig ; 
SDL_Rect positionSettingsBig ; 
SDL_Rect positionCreditsBig ; 
SDL_Rect positionExitBig ; 
SDL_Rect positionRetour ;
SDL_Rect positionRetourBig ;
SDL_Rect positionFullScreen ;
SDL_Rect positionFullScreenBig ;
SDL_Rect positionAudioFull ;
SDL_Rect positionAudioMute ;
SDL_Rect positionSettingsGUI ; 
SDL_Rect positionBarNoir ;
SDL_Rect positionBarRouge ; 
SDL_Rect positionCreditsGUI ; 
SDL_Rect positionTexte ; 
SDL_Rect positionBack1 ; 
SDL_Rect positionBack2 ; 
SDL_Rect positionBack3 ;
SDL_Rect positionBack4 ;




BarNoir = SDL_CreateRGBSurface(SDL_HWSURFACE, 200, 50, 32, 0, 0, 0, 0);
SDL_FillRect(BarNoir, NULL, SDL_MapRGB(BarNoir->format, 0, 0, 0));


positionFond.x=0 ; 
positionFond.y=0 ;
positionPlay.x=350 ; 
positionPlay.y=100;
positionPlaybig.x=350 ; 
positionPlaybig.y=100 ;
positionSettings.x=350 ; 
positionSettings.y=200 ;
positionSettingsBig.x=350 ; 
positionSettingsBig.y=200 ;
positionCredits.x=350 ; 
positionCredits.y=300 ;  
positionCreditsBig.x=350 ; 
positionCreditsBig.y=300 ;
positionExit.x=350 ; 
positionExit.y=400 ;
positionExitBig.x=350; 
positionExitBig.y=400; 





positionRetour.x = 600 ;
positionRetour.y = 10 ;
positionRetourBig.x = 600; 
positionRetourBig.y = 10 ; 

positionFullScreen.x=380 ; 
positionFullScreen.y=150 ; 
positionFullScreenBig.x=380 ; 
positionFullScreenBig.y=150 ; 


positionAudioFull.x=200; 
positionAudioFull.y=130; 
positionAudioMute.x=200; 
positionAudioMute.y=130; 


positionSettingsGUI.x=90 ; 
positionSettingsGUI.y=120; 

positionBarNoir.x= 400 ; 
positionBarNoir.y= 260 ; 
positionBarRouge.x= 400 ; 
positionBarRouge.y= 260 ; 

positionCreditsGUI.x=300; 
positionCreditsGUI.y=50; 

positionTexte.x=300; 
positionTexte.y=30 ;
positionBack1.x=0 ; 
positionBack1.y=0 ; 
positionBack2.x=0 ; 
positionBack2.y=0 ; 
positionBack3.x=0 ; 
positionBack3.y=0 ;  
positionBack4.x=0 ; 
positionBack4.y=0 ;  



ecran = SDL_SetVideoMode(800,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF) ;
Fond = IMG_Load("back.jpg") ;
bouttonplay=IMG_Load("play.png");
bouttonsettings=IMG_Load("settings.png");
bouttoncredits=IMG_Load("credits.png");
bouttonexit=IMG_Load("exit.png");
playbig=IMG_Load("big.png") ; 
settingsbig=IMG_Load("settingsbig.png") ; 
creditsbig=IMG_Load("creditsbig.png") ; 
exitbig=IMG_Load("exitbig.png") ; 
retour = IMG_Load("return.png") ;
retourbig = IMG_Load("returnbig.png") ; 
fullscreen = IMG_Load("fullscreenlittleNEW.png") ; 
fullscreenbig = IMG_Load("fullscreenbigNEW.png") ;
audiofull = IMG_Load("audiofullNEW.png") ;
audiomute = IMG_Load("audiomuteNEW.png") ;
settingsGUI = IMG_Load("settingsGUI.png") ; 
creditsGUI = IMG_Load("1.png") ;
back1=IMG_Load("back1.png") ;
back2=IMG_Load("back2.png") ;
back3=IMG_Load("back3.png") ;
back4=IMG_Load("back4.png") ;


TTF_Init();
TTF_Font *police = NULL;

police = TTF_OpenFont("Candara1.ttf", 60);
texte = TTF_RenderText_Blended(police, "SPACE BATTLE", couleurNoire);


int moverplay=0, moversett=0, movercred=0,moverexit=0, moverretour =0, moverfullscreen=0,moveraudio=0,moverbar=0,
exitclick=0,settclick=0,credclick=0,playclick=0,retourclick=0,fullscreenclick=0,audioclick=0,barclick=0,
full=0,son=1,barrougeX=0,volume=128 , bar=0, longbarRouge=0 ,b1=1,b2=0,b3=0,b4=0,b5=0;

while (continuer==1) 
    {



        while(SDL_PollEvent(&event))
{  
        switch(event.type) 
        {
	   case SDL_MOUSEMOTION:
  		if ((event.motion.x>=350)&&(event.motion.x<=500)&&(event.motion.y>=100)&&(event.motion.y<=200)) 
		{
		 
		  moverplay=1;  
		  	
		} else 
		{
		 moverplay=0; 
		}
	      if ((event.motion.x>=350)&&(event.motion.x<=450)&&(event.motion.y>=200)&&(event.motion.y<=300))
		{
		  moversett=1 ; 
		} else 
		{
		  moversett=0 ;
		}
	      if ((event.motion.x>=350)&&(event.motion.x<=450)&&(event.motion.y>=300)&&(event.motion.y<=400))
		{
		  movercred=1 ; 
		   	
		} else 
		{
		  movercred=0 ;	
		  
		}
	       if  ((event.motion.x>=350)&&(event.motion.x<=450)&&(event.motion.y>=400)&&(event.motion.y<=540))
		{
		  moverexit=1 ; 
		} else 
		{
		  moverexit=0 ;
		}
	       if  ((event.motion.x>=600)&&(event.motion.x<=720)&&(event.motion.y>=10)&&(event.motion.y<=100))
		{
		  moverretour=1 ; 
		} else 
		{
		  moverretour=0 ;
		}
	       if  ((event.motion.x>=380)&&(event.motion.x<=450)&&(event.motion.y>=150)&&(event.motion.y<=220))
		{
		  moverfullscreen=1 ; 
		} else 
		{
		  moverfullscreen=0 ;
		}
	       if  ((event.motion.x>=200)&&(event.motion.x<=270)&&(event.motion.y>=130)&&(event.motion.y<=200))
		{
		  moveraudio=1 ; 
		} else 
		{
		  moveraudio=0 ;
		}
	       if  ((event.motion.x>=400)&&(event.motion.x<=600)&&(event.motion.y>=260)&&(event.motion.y<=310))
		{
		  moverbar=1 ; 
		} else 
		{
		  moverbar=0 ;
		}

		break ; 

case SDL_MOUSEBUTTONDOWN : 
		if  (moverexit==1)
		{
		 	exitclick=1 ; 
		}
		else if ((moversett==1)&&((playclick==0)&&(credclick==0)))
		{
			 Mix_PlayChannel(-1,sound,0) ;
			 settclick=1 ; 
	
		}
		else if ((movercred==1)&&((playclick==0)&&(settclick==0)))        
		{
			 Mix_PlayChannel(-1,sound,0) ; 
			 credclick=1 ; 
		}
		else if ((moverplay==1)&&((settclick==0)&&(credclick==0)))
		{
			 Mix_PlayChannel(-1,sound,0) ;
			 playclick=1;
		}
		else if ((moverretour==1)&&(((settclick==1)||(playclick==1))||(credclick==1))) 
		{
			 Mix_PlayChannel(-1,sound,0) ;
			 retourclick=1 ; 
		} else if ((moverfullscreen==1)&&(settclick==1))
		{
			 Mix_PlayChannel(-1,sound,0) ;
			 fullscreenclick=1 ; 
		} else if (0 && (moveraudio==1)&&(settclick==1))
		{
		 	audioclick=1 ;  
		} else if ((moverbar==1)&&(settclick==1))
		{
			 barclick=1 ;  
			 barrougeX=event.motion.x;
			 printf ("Bar x = %d ",barrougeX) ; 	
		 
		   
		}
break ; 
case SDL_KEYDOWN : 
switch (event.key.keysym.sym)
            {
		case SDLK_DOWN : 
			if (((settclick==0)&&(playclick==0))&&(credclick==0)&&(exitclick==0)) 
			{
				if ((((moverplay==0)&&(moversett==0))&&(movercred==0))&&(moverexit==0))
				{
					moverplay=1 ; 
					movercred=0 ; 
					moversett=0 ; 
					moverexit=0 ;
					break ; 
				}
				else if ((((moverplay==1)&&(moversett==0))&&(movercred==0))&&(moverexit==0))
				{
					moverplay=0 ; 
					moversett= 1 ;
					movercred=0 ;
					moverexit=0 ;
					break ; 
					
					
				}
				else if ((((moverplay==0)&&(moversett==1))&&(movercred==0))&&(moverexit==0))
				{
					moverplay=0 ;  
					moversett=0 ;
					movercred=1 ;
 					moverexit=0 ;  
					break ;                                      
				}
				if ((((moverplay==0)&&(moversett==0))&&(movercred==1))&&(moverexit==0))
 				{
					moverplay=0 ;  
					moversett=0;
					movercred=0 ; 
					moverexit=1 ; 
					break ;                                      
                                        
				}
				if ((((moverplay==0)&&(moversett==0))&&(movercred==0))&&(moverexit==1))
                       	        {
					moverplay=1;
                        	        moversett=0 ;
					movercred=0 ; 
                           	        moverexit=0;
					break ; 
				}
                       }
		break ; 
		case SDLK_UP : 
			if (((settclick==0)&&(playclick==0))&&(credclick==0)&&(exitclick==0)) 
			{
				if (((moverplay==0)&&(moversett==0))&&(movercred==0)&&(moverexit==0))
				{
					moverplay=0 ; 
					movercred=0 ; 
					moversett=0 ; 
					moverexit=1; 
					break ; 
				}
				if (moverplay==1)
				{
					movercred= 0 ; 
					moverplay=0 ; 
					moverexit=1 ; 
                                        moversett=0;
					break ; 
				}
				if (moversett==1)
				{
					moverplay=1 ; 
					moversett=0 ;
					moverexit=0 ; 
                                        movercred=0;
					break ; 
				}
				if (movercred==1)
 				{
					moversett=1 ; 
					movercred=0 ; 
					moverexit=0 ; 
                                        moverplay=0 ;
					break ; 
				}
				if (moverexit==1)
 				{
					moversett=0; 
					movercred=1 ; 
					moverexit=0 ; 
                                        moverplay=0 ;
					break ; 
				}
			}
		break ; 
	case SDLK_RETURN : 
			if (moversett==1) 
  				settclick=1 ; 
			else if (moverplay==1) 
				playclick=1 ; 
			else if (movercred==1) 
				credclick=1 ; 
			else if (moverexit==1) 
				exitclick=1 ; 
			
		break ; 
            }
break ; 	
		
            case SDL_QUIT: //croix
               continuer = 0; 
                break;
        }
}
 
SDL_BlitSurface(Fond,NULL,ecran,&positionFond) ;
if (playclick==1) // affichage play
{   moverplay=0;
	
	if (moverexit==1) SDL_BlitSurface(exitbig,NULL,ecran,&positionExitBig);
	else 
            SDL_BlitSurface(bouttonexit,NULL,ecran,&positionExit) ;
 
	
	if (moverretour==1) SDL_BlitSurface(retourbig,NULL,ecran,&positionRetourBig);
	else SDL_BlitSurface(retour,NULL,ecran,&positionRetour) ;

	if(retourclick==1)
	{
	settclick=0 ;playclick=0 ;credclick=0 ;retourclick=0;
	}
}
else if (settclick==1) // affichage settings
{   moversett=0;

 	SDL_BlitSurface(settingsGUI,NULL,ecran,&positionSettingsGUI) ;
	SDL_BlitSurface(BarNoir,NULL,ecran,&positionBarNoir) ;
	longbarRouge=((200*volume)/128)+400 ; 
	BarRouge = SDL_CreateRGBSurface(SDL_HWSURFACE, longbarRouge-400, 50, 32, 0, 0, 0, 0);
	SDL_FillRect(BarRouge, NULL, SDL_MapRGB(BarRouge->format, 255, 0, 0));
	SDL_BlitSurface(BarRouge,NULL,ecran,&positionBarRouge) ;

	int aux ;
	if (barclick==1) 
	{
	 BarRouge = SDL_CreateRGBSurface(SDL_HWSURFACE, barrougeX-400, 50, 32, 0, 0, 0, 0);
	 SDL_FillRect(BarRouge, NULL, SDL_MapRGB(BarRouge->format, 255, 0, 0));
	 SDL_BlitSurface(BarRouge,NULL,ecran,&positionBarRouge) ;
	 volume=(int)((barrougeX-400)*128)/200 ; 
 
	 Mix_VolumeMusic(volume) ;
	 aux=volume;
	 
	 son=1 ;
	  
	} else if ((audioclick==1)&&(son==1))
	{
		
			volume=0 ; 
			Mix_VolumeMusic(0) ;				
			son=0 ;
	} else if ((audioclick==1)&&(son==0))
	{
			volume=aux ; 
			Mix_VolumeMusic(aux) ; 
			son=1 ; 
				 
	} 

	if (volume==0) SDL_BlitSurface(audiomute,NULL,settingsGUI,&positionAudioMute) ; 
	 else SDL_BlitSurface(audiofull,NULL,settingsGUI,&positionAudioFull); 
	
		  
	audioclick=0 ; 
	barclick=0 ; 
	

        if (moverexit==1) SDL_BlitSurface(exitbig,NULL,ecran,&positionExitBig);
	else SDL_BlitSurface(bouttonexit,NULL,ecran,&positionExit) ;
	

	if (moverfullscreen==1) SDL_BlitSurface(fullscreenbig,NULL,ecran,&positionFullScreenBig);
	else SDL_BlitSurface(fullscreen,NULL,ecran,&positionFullScreen) ;
	
	if (moverretour==1) SDL_BlitSurface(retourbig,NULL,ecran,&positionRetourBig);
	else SDL_BlitSurface(retour,NULL,ecran,&positionRetour) ;
	
	
	if (fullscreenclick==1)
	{
		 if (full==0)
		 {
			ecran = SDL_SetVideoMode(950,600,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN) ;
	
			fullscreenclick=0 ; 
		       	full=1 ;
		 } else 
		 {
		 	ecran = SDL_SetVideoMode(800,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF ) ;	
			fullscreenclick=0 ; 
		       	full=0 ;
		 }
	}


	

	

	if(retourclick==1)
	{
		
	settclick=0 ;playclick=0 ;credclick=0 ;retourclick=0;
	}

}
else if (credclick==1) //affichage credits
{ movercred=0;
	SDL_BlitSurface(Fond,NULL,ecran,&positionFond) ;
 	SDL_BlitSurface(creditsGUI,NULL,ecran,&positionCreditsGUI) ;

	if (moverexit==1) SDL_BlitSurface(exitbig,NULL,ecran,&positionExitBig);
	else SDL_BlitSurface(bouttonexit,NULL,ecran,&positionExit) ;

	if (moverretour==1) SDL_BlitSurface(retourbig,NULL,ecran,&positionRetourBig);
	else SDL_BlitSurface(retour,NULL,ecran,&positionRetour) ;

	//SDL_BlitSurface(texte, NULL, ecran, &positionTexte);


	if(retourclick==1)
	{
	settclick=0 ;playclick=0 ;credclick=0 ;retourclick=0;
	}



} else //affichage menu
{         if (b1==1)
	{
		SDL_BlitSurface(Fond,NULL,ecran,&positionFond) ;
		b2=1; 
		b1=0 ; 
		SDL_Delay(40) ; 
	} else if(b2==1)
	{
		SDL_BlitSurface(back1,NULL,ecran,&positionBack1) ;
		b2=0; 
		b3=1 ; 
		SDL_Delay(40) ;
	} else if(b3==1)
	{
		SDL_BlitSurface(back2,NULL,ecran,&positionBack2) ;
		b3=0; 
		b4=1 ; 
		SDL_Delay(40) ;
	} else if(b4==1)
	{
		SDL_BlitSurface(back3,NULL,ecran,&positionBack3) ;
		b4=0; 
		b5=1 ; 
		SDL_Delay(40) ;
	} else if(b5==1)
	{
		SDL_BlitSurface(back4,NULL,ecran,&positionBack4) ;
		b5=0; 
		b1=1 ; 
		SDL_Delay(40) ;
	} 


	SDL_BlitSurface(texte, NULL, ecran, &positionTexte);


	if(moverplay==1)SDL_BlitSurface(playbig,NULL,ecran,&positionPlaybig) ;
	else SDL_BlitSurface(bouttonplay,NULL,ecran,&positionPlay) ; 

	if (moversett==1)SDL_BlitSurface(settingsbig,NULL,ecran,&positionSettingsBig); 
	else  SDL_BlitSurface(bouttonsettings,NULL,ecran,&positionSettings) ;

	if (movercred==1) SDL_BlitSurface(creditsbig,NULL,ecran,&positionCreditsBig);
	else SDL_BlitSurface(bouttoncredits,NULL,ecran,&positionCredits) ;  

	if (moverexit==1) SDL_BlitSurface(exitbig,NULL,ecran,&positionExitBig);
	else SDL_BlitSurface(bouttonexit,NULL,ecran,&positionExit) ; 
	
}


		if(exitclick==1) continuer = 0;




		SDL_Flip(ecran) ;

    } //fin while(continuer)


TTF_Quit();
TTF_CloseFont(police);

SDL_FreeSurface(Fond) ; 
SDL_FreeSurface(bouttonplay) ; 
SDL_FreeSurface(bouttonsettings) ; 
SDL_FreeSurface(bouttoncredits) ; 
SDL_FreeSurface(bouttonexit) ; 
SDL_FreeSurface(playbig) ;
SDL_FreeSurface(settingsbig) ;
SDL_FreeSurface(creditsbig) ;
SDL_FreeSurface(exitbig) ;
SDL_FreeSurface(retour) ;
SDL_FreeSurface(retourbig) ;
SDL_FreeSurface(fullscreen) ;
SDL_FreeSurface(fullscreenbig) ;
SDL_FreeSurface(audiofull) ;
SDL_FreeSurface(audiomute) ;
SDL_FreeSurface(settingsGUI) ;
SDL_FreeSurface(BarNoir) ;
SDL_FreeSurface(BarRouge) ;
SDL_FreeSurface(BarRouge) ;
SDL_FreeSurface(creditsGUI) ;
SDL_FreeSurface(texte) ;

SDL_Quit() ;
}



 





