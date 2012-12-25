TARGET=test

CC=gcc
CFLAGS=--std=c99
SRC=main.c ../src/util.c ../src/sorts/*.c

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

clean:
	rm $(TARGET)
