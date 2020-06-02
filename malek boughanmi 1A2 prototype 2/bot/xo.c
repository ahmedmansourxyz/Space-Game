#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "xo.h"
#include "outils.h"
#include "GameState.h"

xo* init_xo(char* img)
{
    int i,j,index=1;
    xo* xo_tmp;

    xo_tmp=malloc(sizeof(xo));
    xo_tmp->xoS=IMG_Load(img);
    xo_tmp->xoR.w=xo_tmp->xoS->w;
    xo_tmp->xoR.h=xo_tmp->xoS->h;
    xo_tmp->xoR.x=320-xo_tmp->xoR.w/2;
    xo_tmp->xoR.y=240-xo_tmp->xoR.h/2;
    xo_tmp->canplay=0;
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++,index++)
        {
            xo_tmp->tab[i][j]=index+'0'; //convert int -> char
        }
    }

    xo_tmp->xoNum=IMG_Load("nums.png");
    xo_tmp->numW=xo_tmp->xoNum->w/9;
    xo_tmp->numH=xo_tmp->xoNum->h;

    xo_tmp->xoLtr=IMG_Load("ltrs.png");
    xo_tmp->ltrW=xo_tmp->xoLtr->w/2;
    xo_tmp->ltrH=xo_tmp->xoLtr->h;

    srand(time(NULL));
    xo_tmp->tour=rand()%2; //tour random
    xo_tmp->maxtour=xo_tmp->tour+9;
    return xo_tmp;
}

void random_xo(xo* xo)
{
    int i,j,index,m,search=1,done;
    while(search)
    {
        done=0;
        index=1;
        m=rand()%10;
        for(j=0;j<3;j++)
        {
            for(i=0;i<3;i++,index++)
            {
                if(m==index && !isalpha(xo->tab[j][i]))
                {
                    xo->tab[j][i]=xo->tour%2?'x':'o';
                    xo->tour++;
                    done=1;
                }

            }
        }
        if(done)
            break;

    }


}

//int canplay=1;
void winner_xo(int winner,xo* xo,bot* bot)
{
    // 0:bot  1:player 2: draw
    if(winner==0)
        printf("\n-----------\nL\'ORDINATEUR GAGNE\n-----------\n");
    else if(winner==1)
    {
        bot->alive=0;
        printf("\n--------------\nJOUEUR 1 GAGNE!\n--------------\n");
        state=Play;
    }

    else
    {
        bot->alive=0;
        state=Play;
        printf("\n------\nEGALITé!\n------\n");
    }


    //canplay=0;

    xo->canplay=0;

}

void checkwin_xo(xo* xo,bot* bot)
{
    int i,j,t;
    int winner;
    char p;
    if(xo->tour>=xo->maxtour)
    {
        winner_xo(2,xo,bot);
    }
    for(t=0;t<2;t++)
    {
        if(t)p='x';
        else p='o';
        for(i=0;i<3;i++)
        {
            if(xo->tab[i][0]==p && xo->tab[i][1]==p && xo->tab[i][2]==p) //col
                winner_xo(t,xo,bot);
        }
        for(i=0;i<3;i++)
        {
            if(xo->tab[0][i]==p && xo->tab[1][i]==p && xo->tab[2][i]==p) //lignes
                winner_xo(t,xo,bot);
        }
        if(xo->tab[0][0]==p && xo->tab[1][1]==p && xo->tab[2][2]==p) //diag 1
            winner_xo(t,xo,bot);
        if(xo->tab[0][2]==p && xo->tab[1][1]==p && xo->tab[2][0]==p) //diag 2
            winner_xo(t,xo,bot);
    }


}


void put_xo(xo* xo,int place,bot* bot)
{
    int i,j,index=1;


    if(xo->tour%2)
    {
        for(j=0;j<3;j++)
        {
            for(i=0;i<3;i++,index++)
            {
                if(index==place && !isalpha(xo->tab[j][i]) && xo->canplay)
                    {
                        xo->tab[j][i]=xo->tour%2?'x':'o';
                        xo->tour++;

                    }
                //printf("[%c]",xo->tab[j][i]);
            }
            //printf("\n");
        }
    }

    checkwin_xo(xo,bot);




}

void bot_xo(xo* xo,bot* bot)
{
    if(!xo->canplay)
        return;
    if(xo->tour%2==0)
    {

        random_xo(xo);
        checkwin_xo(xo,bot);
    }
}



void afficher_xo(xo* xo,SDL_Surface* screen)
{
    int i,j,index=0;
    SDL_Rect src,dest;

    SDL_BlitSurface(xo->xoS,0,screen,&xo->xoR); //template

    for(j=0;j<3;j++)
    {
        for(i=0;i<3;i++,index++)
        {

            if(!isalpha(xo->tab[j][i])) //if char is int
            {
                src.w=xo->numW;
                src.h=xo->numH;
                /*dest.w=xo->ltrW;
                dest.h=xo->ltrH;*/
                dest.x=xo->xoR.x+48+96*i;
                dest.y=xo->xoR.y+34+96*j;
                src.x=(xo->tab[j][i]-'0'-1)*xo->numW;
                src.y=0;

                SDL_BlitSurface(xo->xoNum,&src,screen,&dest); //numeros
            }
            else
            {
                src.w=xo->ltrW;
                src.h=xo->ltrH;
                dest.x=xo->xoR.x+30+(xo->xoR.w-30)/3*i;
                dest.y=xo->xoR.y+30+(xo->xoR.h-30)/3*j;
                if(xo->tab[j][i]=='x')
                    src.x=0;
                else if(xo->tab[j][i]=='o')
                    src.x=xo->ltrW;
                src.y=0;

                SDL_BlitSurface(xo->xoLtr,&src,screen,&dest);
            }

        }
    }

}

void free_xo(xo* xo)
{
    SDL_FreeSurface(xo->xoS);
    SDL_FreeSurface(xo->xoNum);
    SDL_FreeSurface(xo->xoLtr);
    free(xo);
}
