all: main.o ExactSolution.o Quad.o LegendreBasis.o
	g++ -Wall -lm -O main.o ExactSolution.o Quad.o LegendreBasis.o -o linear

main.o: main.cpp
	g++ -Wall -O -c main.cpp

ExactSolution.o: ExactSolution.cpp 
	g++ -Wall -O -c ExactSolution.cpp

Quad.o: Quad.cpp  
	g++ -Wall -O -c Quad.cpp 

Basis.o: LegendreBasis.cpp
	 g++ -Wall -O -c LegendreBasis.cpp 	

clean:
	rm *.o linear
