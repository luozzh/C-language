OBJ = direction.o game2048.o main.o tools.o
CC = gcc
BIN =game2048.bin
FLAG = -Werror -Wall #-DDEBUG
SID = -std=gnu99 

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ) && ./$(BIN)

direction.o:direction.c direction.h
	$(CC) $(STD) $(FLAG) -c direction.c

game2048.o:game2048.c game2048.h
	$(CC) $(STD) $(FLAG) -c game2048.c

tools.o:tools.c tools.h
	$(CC) $(STD) $(FLAG) -c tools.c

main.o:main.c
	$(CC) $(STD) $(FLAG) -c main.c 

clean:
	rm $(BIN) $(OBJ)
	
