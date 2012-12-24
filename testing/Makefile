TARGET=test

SORT=bubble

CC=gcc
CFLAGS=--std=c99
SRC=main.c ../src/util.c ../src/sorts/*.c

bubble:
	$(CC) $(SRC) -o $(TARGET) -DALGORITHM=$(SORT)
	./$(TARGET)

clean:
	rm $(TARGET)
