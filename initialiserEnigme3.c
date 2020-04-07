#include <stdio.h> 
#include <stdlib.h>
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h> 
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "enigme.h"



void initialiser_enigme3(enigme *enigme3,int random,SDL_Surface* ecran)
{

	enigme3->page=1;
		
		enigme3->etat=0;

		enigme3->pos=0;

		TTF_Init();
		
		TTF_Font* font=TTF_OpenFont("Capture_it.ttf",20);

		enigme3->klam=IMG_Load("pencil1.png");
                enigme3.background=IMG_Load("aaa.png");
	SDL_Color white={255,255,255};
	FILE *f1,*f2,*f3;
	f1=fopen("enigme3.txt","r");
	f2=fopen("enigme3-2.txt","r");
	f3=fopen("enigme3-3.txt","r");
	
	char question[100];
	
	char reponse1_ch[100];
	char reponse2_ch[100];
	char reponse3_ch[100];
	
	int i;

	
	

	switch(random)
	{
		case 0:
		while (fscanf(f1,"%s \n %s \n %s \n %s \n",question,reponse1_ch,reponse2_ch,reponse3_ch) != EOF)
			i++;
		break;
		case 1:
		while (fscanf(f2,"%s \n %s \n %s \n %s \n",question,reponse1_ch,reponse2_ch,reponse3_ch) != EOF)
			i++;
		break;
		case 2:
		while (fscanf(f3,"%s \n %s \n %s \n %s \n",question,reponse1_ch,reponse2_ch,reponse3_ch) != EOF)
			i++;
		break;
	
	}

	

	enigme3->Q= TTF_RenderText_Solid( font, question, white);
	enigme3->R= TTF_RenderText_Solid( font, reponse1_ch, white);
	enigme3->R2= TTF_RenderText_Solid( font, reponse2_ch, white);
	enigme3->R3= TTF_RenderText_Solid( font, reponse3_ch, white);



	enigme3->QPos.x=(ecran->w/2 - enigme3->Q->w)/2;
	enigme3->QPos.y=100;

			enigme3->RPos.x=150;
			enigme3->RPos.y=200;

			enigme3->R2Pos.y=200;
			enigme3->R2Pos.x=350;

			enigme3->R3Pos.x=550;
			enigme3->R3Pos.y=200;

			fclose(f1);
			fclose(f2);
			fclose(f3);

}
