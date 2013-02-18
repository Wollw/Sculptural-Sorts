TARGET=test

CC=gcc
LIBS=glu
CFLAGS=--std=c99 -g $(shell pkg-config --libs --cflags $(LIBS)) -lglut -lpthread
SRC=main.c util.c shader.c ../src/sorts/*.c


all:

bubble:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=bubble

selection:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=selection

insertion:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=insertion

shell:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=shell

heap:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=heap

clean:
	rm $(TARGET)
