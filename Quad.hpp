#ifndef QUADHEADERDEF
#define QUADHEADERDEF

#include "libs.hpp"


class Quad
{
	public:
		Quad();
		~Quad() {};
		//DIM: dimension of space
		//const int DIM=1; 
		//Computes integral of a function in 1D interval
		//[lLim,rLim] using Gauss-Legendre quadrature rule
		//double GL_1D(std::function<double(double)> func, const double tl, const double tr, const int points) const;
 		double GL_1D(double (*func)(double), const double tl, const double tr, const int points) const;
		//double GL_int1d((*f)(double) ,const double lLim, constant double rLim,const int points);
	private:	
		// Map storing 1d gauss-legendre quadrature:
		std::map<int, std::vector<double>> gl_quad_x_1D; //Key, number of quadrature. Value, node   of quadrature.
		std::map<int, std::vector<double>> gl_quad_w_1D; //Key, number of quadrature. Value, weight of quadrature
		std::vector<int> gl_quad_num; //Only limited number of quadrature points provided.
		void read_GL_quad_1D();
		static double linear_map(const double x, const std::vector<double> & xrange, const std::vector<double> & trange);
		static double linear_map(const double x, const double xl, const double xr, const double tl, const double td);
				 		
};

#endif
