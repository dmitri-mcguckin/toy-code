CC=c++
CFLAGS=-Wall -O2
SRC=*.cpp
BIN=toy-code

all:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

run: all
	clear
	./$(BIN)

clean:
	rm -rf *.o $(BIN)
