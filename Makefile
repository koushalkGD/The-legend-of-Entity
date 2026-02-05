CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -02
SRC = src/main.cpp
OUT = bin/game

all:
  mkdir -p bin
  $(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run: all
  ./$(OUT)

clean:
  rm -rf bin
