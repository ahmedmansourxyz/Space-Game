prog: main.o enigme.o
	gcc main.o enigme.o -o prog -g -lSDL -lSDL_image -lSDL_ttf 
main.o: main.c
	gcc -c main.c -g

enigme.o: enigme.c
	gcc -c enigme.c -g
