CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
HDRS = $(INC)/quicksort.h $(INC)/statistics.h
OBJS = $(OBJ)/main.o $(OBJ)/quicksort.o $(OBJ)/statistics.o
CFLAGS = -Wall -g -c -I$(INC) -std=c++11
EXE = $(BIN)/main.out

all: run

run: $(EXE)
	$(EXE)

$(EXE): $(OBJS)
	$(CC) -pg -g -o $(EXE) $(OBJS) $(LIBS)
	
$(OBJ)/%.o: $(SRC)/%.cpp $(HDRS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(EXE) $(OBJS) gmon.out
