CC = g++  #the compiler
CFLAGS = -g
OBJ = Src/main.cpp 
BIN = run
all: $(OBJ) Src/vector.cpp
	$(CC) -o $(BIN) $(OBJ) $(CFLAGS)

