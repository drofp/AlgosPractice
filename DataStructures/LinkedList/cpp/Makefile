CXX := g++
CXX_FLAGS := -Wall -std=c++17 -g -lgtest -lgtest_main
TESTINC := # /usr/local/include/gtest

BIN := bin
SRC := src
INCLUDE := include
TESTS := tests

EXECUTABLE := main
TESTEXEC := tests

all: $(BIN)/$(EXECUTABLE) $(BIN)/$(TESTEXEC)

run: clean all
		clear
		./$(BIN)/$(EXECUTABLE)

testAll: clean all
			clear
			./$(BIN)/$(TESTEXEC)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
		$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@

$(BIN)/$(TESTEXEC):
	$(CXX) $(CXX_FLAGS) -I $(TESTINC) $(TESTS) -o $@

clean:
	-rm $(BIN)/*
