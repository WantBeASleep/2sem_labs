SOURCE = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SOURCE))

all: 
	g++ -c $(SOURCE)
	g++ -o lab2 $(OBJ)
	rm *.o