LIBS=-lm -lncurses -lpthread
FLAGS=-g 
CC=gcc
FILES=test.c rasterizer.c vector.c fbuffer.c quaternion.c matrix4.c camera.c
all:
	$(CC) $(FILES) $(LIBS) $(FLAGS)

run:
	./a.out

clean:
	rm a.out