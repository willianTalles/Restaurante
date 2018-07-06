INC = ./include
SRC = ./src
OBJ = ./build
LIB = ./lib

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -ansi -I$(INC)
AR = ar

# linux: util.a util.so prog_estatico prog_dinamico

windows: util.lib util.dll prog_estatico.exe prog_dinamico.exe

util.lib: $(SRC)/util.cpp $(INC)/util.h
	$(CC) $(CFLAGS) -c $(SRC)/util.cpp -o $(OBJ)/util.o
	$(AR) rcs $(LIB)/$@ $(OBJ)/util.o 

util.dll: $(SRC)/util.cpp $(INC)/util.h
	$(CC) $(CFLAGS) -c $(SRC)/util.cpp -o $(OBJ)/util.o
	$(CC) -shared -o $(LIB)/$@ $(OBJ)/util.o

$(OBJ)/status.o: $(INC)/status.h
	$(CC) $(CPPFLAGS) -c $(SRC)/status.cpp -o $@

$(OBJ)/mesa.o: $(OBJ)/status.o $(INC)/mesa.h
	$(CC) $(CPPFLAGS) -c $(SRC)/mesa.cpp -o $@

$(OBJ)/reserva.o: $(OBJ)/mesa.o $(OBJ)/status.o $(INC)/reserva.h
	$(CC) $(CPPFLAGS) -c $(SRC)/reserva.cpp -o $@

prog_estatico.exe: 
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(LIB)/util.a -o $(OBJ)$@

prog_estatico.exe: 
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(LIB)/util.a -o $(OBJ)$@