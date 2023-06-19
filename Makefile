LIBS=-lm -lncurses
FLAGS=-g
CC=gcc
FILES=test.c rasterizer.c vector.c fbuffer.c
all:
	$(CC) $(FILES) $(LIBS) $(FLAGS)

run:
	./a.out

clean:
	rm a.out