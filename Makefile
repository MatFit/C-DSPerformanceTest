# Basic Make file with g++ compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: main

clean:
	rm -f main test

main: main.cpp linear.hpp hashmap.hpp tree.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

test: test.cpp linear.hpp hashmap.hpp tree.hpp
	$(CXX) $(CXXFLAGS) test.cpp -o test


