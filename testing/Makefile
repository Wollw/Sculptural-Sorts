TARGET=test

CC=gcc
CFLAGS=--std=c99 -g
SRC=main.c ../src/sorts/*.c

all:

bubble:
	$(CC) $(SRC) -o $(TARGET) -DALGORITHM=bubble
	./$(TARGET)

selection:
	$(CC) $(SRC) -o $(TARGET) -DALGORITHM=selection
	./$(TARGET)

insertion:
	$(CC) $(SRC) -o $(TARGET) -DALGORITHM=insertion
	./$(TARGET)

shell:
	$(CC) $(SRC) -o $(TARGET) -DALGORITHM=shell
	./$(TARGET)

clean:
	rm $(TARGET)
