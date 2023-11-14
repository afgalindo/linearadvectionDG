#ifndef QUADHEADERDEF
#define QUADHEADERDEF

class Quad
{
	public:
		Quad(const int DIM);
		~Quad() {};
		//DIM: dimension of space
		const int DIM; 
		//Computes integral of a function in 1D interval
		//[lLim,rLim] using Gauss-Legendre quadrature rule
		double GL_int1d((*f)(double) ,const double lLim, constant double rLim,const int points);
				
};

#endif
