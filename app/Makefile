CXX = g++
CXXFLAGS = -fopenmp -g3 -Wall -std=c++17
MKDIR = mkdir -p

LIBS = -lm

directorios:
	$(MKDIR) build dist

Matriz.o: directorios Matriz.cpp
	$(CXX) $(CXXFLAGS) -c Matriz.cpp -o build/Matriz.o

main.o: directorios main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o build/main.o

all: clean main.o Matriz.o
	$(CXX) $(CXXFLAGS) -o dist/programa \
	build/main.o build/Matriz.o \
	$(LIBS)
	rm -fr build

clean:
	rm -fr *.o a.out core programa dist build

.DEFAULT_GOAL := all
