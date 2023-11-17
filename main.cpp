#include <iostream>
#include <cmath>
#include "ExactSolution.hpp"
#include "Quad.hpp"

int main(int argc, char* argv[]){
	
	ExactSolution mySolution;
	Quad myQuad;
	
	double integral;

	integral=myQuad.GL_1D(mySolution.exact_1d,0.0,1.0,6);

	std::cout<<"probando"<<integral <<"\n";
	return 0;
}
