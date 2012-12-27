TARGET=test

CC=gcc
CFLAGS=--std=c99 -g
SRC=main.c ../src/sorts/*.c

all:

bubble:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=bubble
	./$(TARGET)

selection:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=selection
	./$(TARGET)

insertion:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=insertion
	./$(TARGET)

shell:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=shell
	./$(TARGET)

heap:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -DALGORITHM=heap
	./$(TARGET)

clean:
	rm $(TARGET)
