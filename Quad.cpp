#include "Quad.hpp"

Quad::Quad()
{
	//Limited number of quadrautere points.
	 gl_quad_num=std::vector<int>{1,2,3,4,5,6};
	 	
	//read Gauss-Legendre quadrature points and weights in 1D;
	read_GL_quad_1D();	
}

void Quad::read_GL_quad_1D()
{	
	for(auto const & num: gl_quad_num)
	{
		std::vector<double> quad_x(num);
		std::vector<double> quad_w(num);
		if (num==1)
		{
			quad_w=std::vector<double>{ 2 };
			quad_x=std::vector<double>{ 0 };
		}
		else if (num == 2)
		{
			quad_w=std::vector<double>{ 1, 1 };
			quad_x=std::vector<double>{-0.5773502691896257,0.5773502691896257};
		}
		else if (num == 3)
		{
			quad_w = std::vector<double>{ 0.5555555555555556, 0.8888888888888895, 0.5555555555555554 };
			quad_x = std::vector<double>{ -0.7745966692414833, 0, 0.7745966692414832 };
		}
		else if (num == 4)
		{
			quad_w = std::vector<double>{ 0.3478548451374547, 0.6521451548625466, 0.6521451548625458, 0.3478548451374541 };
			quad_x = std::vector<double>{ -0.8611363115940527, -0.3399810435848563, 0.3399810435848563, 0.8611363115940526 };
		}
		else if (num == 5)
		{
			quad_w = std::vector<double>{ 0.2369268850561892, 0.4786286704993669, 0.568888888888889, 0.4786286704993672, 0.2369268850561891 };
			quad_x = std::vector<double>{ -0.9061798459386641, -0.538469310105683, 0, 0.5384693101056831, 0.9061798459386639 };
		}
		else if (num == 6)
		{
			quad_w = std::vector<double>{ 0.1713244923791705, 0.3607615730481384, 0.4679139345726904, 0.467913934572691, 0.3607615730481382, 0.1713244923791708 };
			quad_x = std::vector<double>{ -0.9324695142031522, -0.6612093864662647, -0.238619186083197, 0.2386191860831969, 0.6612093864662647, 0.9324695142031522 };
		} 
		// insert into map that contains abscisas and weights.
		gl_quad_x_1D.insert(std::make_pair(num, quad_x));
		gl_quad_w_1D.insert(std::make_pair(num, quad_w));
	}
}

/**
* @brief linear map, map each point x in range [xrange[0],xrange[1]] to t in range 
* [trange[0],trange[1]]
*
* @param[in] x x in range [xrange[0],xrange[1]]
* @param xrange the range of x
* @param trange the range of t
*
* @return t in range [trange[0], trange[1]]
*/
double Quad::linear_map(const double x, const std::vector<double> & xrange, const std::vector<double> & trange)
{
	double xl= xrange[0], xr=xrange[1];
	double tl=trange[0],  tr=trange[1];

	return (x-xl)/(xr-xl)*(tr-tl)+tl;
}

/**
 * @brief      linear map, map each point x in range [ xl, xr ] to t in range [ tl, tr ]
 *
 * @param[in]  x
 * @param[in]  xl    left end for range x
 * @param[in]  xr    right end for range x
 * @param[in]  tl    left end for range t
 * @param[in]  tr    right end for range t
 *
 * @return     t in range [ tl, tr ]
 *
 * @note       This is a overload version of linear_map( double x, std::vector<double> & xrange, std::vector<double> & trange )
 */
double Quad::linear_map(const double x, const double xl, const double xr, const double tl, const double tr) {

	return (x - xl) / (xr - xl)*(tr - tl) + tl;;
}

/** 
 * @brief Calculates integral of a function in 1D using Gauss-Legendre quadrature rule
 *
 * @param[in] func The function
 * @param[in] tl left interval end 
 * @param[in] tr right interval end
 * @param[in] points number of quadrature points
 *
 * @retun     Integral of the function in [tl,tr].
 */
double Quad::GL_1D(double (*func)(double), const double tl, const double tr, const int points) const
{
	// pick out quadrature coordinates and weights with given quadrature points
	auto quad_x=gl_quad_x_1D.at(points);
	auto quad_w=gl_quad_w_1D.at(points);

	std::vector<double> xrange = {-1.0,1.0}; //Regular interval [-1,1] of Gauss-Legendre quadrature
	std::vector<double> trange= { tl, tr};   // Our integral interval
	
	double integral=0.0;

	for (int i=0; i<points; i++){
		integral +=quad_w[i]*func(linear_map(quad_x[i], xrange, trange));
	}
	integral *=(tr-tl)/2.0;  //normalization factor
	
	return integral;
}

