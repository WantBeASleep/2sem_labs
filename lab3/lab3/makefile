SOURCE = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

all: 
	g++ -c $(SOURCE)
	g++ -o lab3 $(OBJ)
	rm *.o