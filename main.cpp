#include <iostream>
#include <cmath>
#include "ExactSolution.hpp"

int main(int argc, char* argv[]){
	
	ExactSolution mySolution;
	double solution;

	solution=mySolution.exact_1d(0.5*M_PI,0.0);

	std::cout<<"probando"<<solution <<"\n";
	return 0;
}
