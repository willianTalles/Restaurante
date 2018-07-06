INC = include
SRC = src
OBJ = build
LIB = lib

CC = g++
CFLAGS = -Wall -pedantic -std=c++11 -ansi -I. -I $(INC)
AR = ar

# linux: util.a util.so prog_estatico prog_dinamico

windows: status.o util.lib mesa.o reserva.o menu.o util.dll prog_estatico.exe prog_dinamico.exe

status.o: $(INC)/status.h
	$(CC) $(CFLAGS) -c $(SRC)/status.cpp -o $@

mesa.o: $(OBJ)/status.o $(INC)/mesa.h
	$(CC) $(CFLAGS) -c $(SRC)/mesa.cpp -o $@

reserva.o: $(OBJ)/mesa.o $(OBJ)/status.o $(INC)/reserva.h
	$(CC) $(CFLAGS) -c $(SRC)/reserva.cpp -o $@

menu.o: $(OBJ)/mesa.o $(OBJ)/status.o $(OBJ)/reserva.o $(INC)/excecao.h $(INC)/menu.h
	$(CC) $(CFLAGS) -c $(SRC)/menu.cpp -o $@

util.lib: $(OBJ)/mesa.o $(OBJ)/status.o $(OBJ)/reserva.o $(SRC)/util.cpp $(INC)/util.h
	$(CC) $(CFLAGS) -c $(SRC)/util.cpp -o $(OBJ)/util.o
	$(AR) rcs $(LIB)/$@ $(OBJ)/util.o 

util.dll: $(OBJ)/mesa.o $(OBJ)/status.o $(OBJ)/reserva.o $(SRC)/util.cpp $(INC)/util.h
	$(CC) $(CFLAGS) -c $(SRC)/util.cpp -o $(OBJ)/util.o
	$(CC) -shared -o $(LIB)/$@ $(OBJ)/util.o

prog_estatico.exe: 
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(LIB)/util.a -o $(OBJ)$@

prog_estatico.exe: 
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(LIB)/util.a -o $(OBJ)$@