#include <iostream>
#include <cmath>
#include "ExactSolution.hpp"
#include "Quad.hpp"
#include "LegendreBasis.hpp"

int main(int argc, char* argv[]){
	
	ExactSolution mySolution;
	Quad myQuad;
	LegendreBasis myBasis(3);
	
	double lagrange;

	lagrange=myBasis.legendre_poly(3,2.0);

	std::cout<<"probando"<<lagrange <<"\n";
	return 0;
}
