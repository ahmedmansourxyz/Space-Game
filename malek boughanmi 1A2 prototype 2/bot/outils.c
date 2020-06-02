#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface* LoadPNG(char* img)
{
    SDL_Surface* imageopt;
    SDL_Surface* imagepreop=IMG_Load(img);
    if(!imagepreop)
    {
        printf("\nImpossible de trouver l image %s, sortie du jeu...\n",img);
        SDL_Quit();
        exit(-1);
    }
    imageopt=SDL_DisplayFormat(imagepreop);

    SDL_FreeSurface(imagepreop);

    return imageopt;
}

int aabb(SDL_Rect rect1,SDL_Rect rect2)
{
    if(rect1.x>=rect2.x+rect2.w)
        return 0;
    if(rect1.x+rect1.w<=rect2.x)
        return 0;
    if(rect1.y>=rect2.y+rect2.h)
        return 0;
    if(rect1.y+rect1.h<=rect2.y)
        return 0;
    return 1;
}
