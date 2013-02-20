CC=gcc
LIBS=glu
CFLAGS=--std=c99 -g $(shell pkg-config --libs --cflags $(LIBS)) -lglut -lpthread
SRC=src/main.c src/util.c src/shader.c ../src/sorts/*.c


all:

bubble:
	$(CC) $(CFLAGS) $(SRC) -o bin/$@ -DALGORITHM=bubble

selection:
	$(CC) $(CFLAGS) $(SRC) -o bin/$@ -DALGORITHM=selection

insertion:
	$(CC) $(CFLAGS) $(SRC) -o bin/$@ -DALGORITHM=insertion

shell:
	$(CC) $(CFLAGS) $(SRC) -o bin/$@ -DALGORITHM=shell

heap:
	$(CC) $(CFLAGS) $(SRC) -o bin/$@ -DALGORITHM=heap

clean:
	rm bin/*
