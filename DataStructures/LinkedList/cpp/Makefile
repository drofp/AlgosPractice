CXX := g++
CXX_FLAGS := -Wall -std=c++17 -g -lgtest -lgtest_main
TESTINC := # /usr/local/include/gtest

BIN := bin
SRC := src
INCLUDE := include
TESTS := tests

EXECUTABLE := main
TESTEXEC := tests

all:  $(BIN)/$(TESTEXEC) $(BIN)/$(EXECUTABLE)

run: clean all
		clear
		./$(BIN)/$(EXECUTABLE)

testAll: clean all
			clear
			./$(BIN)/$(TESTEXEC)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
		$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@

$(BIN)/$(TESTEXEC): $(TESTS)/*.cc $(SRC)/*.cc #$(filter-out , ./$(SRC)/main.cc)
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^  -o $@

clean:
	-rm $(BIN)/*
