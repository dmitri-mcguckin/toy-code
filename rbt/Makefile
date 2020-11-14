CC=c++
CFLAGS=-Wall -O2 -g
VFLAGS=--leak-check=full -s
SRC=*.cpp
BIN=demo-rbt

all:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

run: all
	clear
	./$(BIN)

leak: all
	clear
	valgrind $(VFLAGS) ./$(BIN)

clean:
	rm -rf *.o *.gch $(BIN)
