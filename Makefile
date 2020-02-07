CC=g++
FLAGS=-g3 -Wall -O0
SRC=main.cpp
BIN=toy-code

all: clean
	$(CC) $(FLAGS) $(SRC) -o $(BIN)

run: all
	./$(BIN)

clean:
	rm -rf *.o $(BIN)
