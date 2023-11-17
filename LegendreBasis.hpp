#ifndef BASISHEADERDEF
#define BASISHEADERDEF

#include "libs.hpp"

//Class that will contain the normalized Legendre polynomial base definition
//and its derivatives

class LegendreBasis
{
	private:
		int dgree;
	public:
		LegendreBasis(int dgree);
		~LegendreBasis(){};
//	private:
		//Legendre polynomial in [-1,1] 
		//p is degree p <= dgree
		//double x argument
		static double legendre_poly(const int p, const double x);
		static double legendre_poly_prime(const int p, const double x);
};

#endif
