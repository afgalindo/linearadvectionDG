#include "ExactSolution.hpp"

//Contains the definition of the exact solution to 
//transport equation u_t+u_x=0, periodic boundary conditions

double ExactSolution::exact_1d(double x)
{
	double outp;
	outp=sin(x);
	return outp;
}
