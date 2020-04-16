CXX := g++
CXX_FLAGS := -Wall -std=c++17 -g

BIN := bin
SRC := src
INCLUDE := include

EXECUTABLE := main

all: $(BIN)/$(EXECUTABLE)

run: clean all
		clear
		./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
		$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@

clean:
	-rm $(BIN)/*
