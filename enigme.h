

typedef struct 
{
	
int etat;
SDL_Surface* klam;
SDL_Surface* background;
SDL_Rect klamPos;
SDL_Surface *Q,*Q2,*Q3,*R,*R2,*R3,*R4,*R5,*R6,*R7,*R8,*R9;
SDL_Rect QPos,Q2Pos,Q3Pos,RPos,R2Pos,R3Pos,R4Pos,R5Pos,R6Pos,R7Pos,R8Pos,R9Pos;
int image;
int page;
int pos;


}enigme;


void initialiser_enigme(enigme *enigme,SDL_Surface* ecran);
void resolution_Enigme(enigme *enigme,int *entree,int tt);
void afficher_Enigme(enigme *enigme,SDL_Surface* ecran);

