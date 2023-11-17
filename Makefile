all: main.o ExactSolution.o Quad.o
	g++ main.o ExactSolution.o Quad.o -o linear

main.o: main.cpp
	g++ -c main.cpp

ExactSolution.o: ExactSolution.cpp 
	g++ -c ExactSolution.cpp

Quad.o: Quad.cpp  
	g++ -c Quad.cpp 

clean:
	rm *.o linear
