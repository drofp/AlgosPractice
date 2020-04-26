CXX := g++
CXX_FLAGS := -Wall -std=c++17 -g -lgtest -lgtest_main
TESTINC := #/usr/local/include/gtest

BIN := bin
SRC := src
INCLUDE := include
TESTS := tests

EXECUTABLE := main
TESTEXEC := tests

all: clean $(BIN)/$(EXECUTABLE) $(BIN)/$(TESTEXEC)

run: clean all
		clear
		./$(BIN)/$(EXECUTABLE)

test: clean all
		./$(BIN)/$(TESTEXEC)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cc
		$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^ -o $@

NONMAIN_SRCS := $(filter-out $(SRC)/main.cc, $(wildcard $(SRC)/*.cc))
$(BIN)/$(TESTEXEC): $(TESTS)/*.cc $(NONMAIN_SRCS)
	$(CXX) $(CXX_FLAGS) -I $(INCLUDE) $^  -o $@

clean:
	-rm -r $(BIN)/*
