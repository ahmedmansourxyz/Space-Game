prog:background.o main.o
	gcc background.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_ttf -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_image -lSDL_ttf -g
