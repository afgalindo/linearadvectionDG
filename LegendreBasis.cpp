#include "LegendreBasis.hpp"

LegendreBasis::LegendreBasis(int degree)
{
	dgree=degree;		
}
double LegendreBasis::legendre_poly(const int p, const double x)
{
	if(std::abs(x)>1.0)
	{
		return 0.0;
	}

	if (p==0)
	{
		return std::sqrt(2.0)/2.0;
	}
	else if (p==1)
	{
		return x*std::sqrt(6.0)/2.0;
	}
	else if (p==2)
	{
		return (3.0*x*x-1.0)*std::sqrt(10.0)/4.0;
	}
	else if (p==3)
	{
		return (5.0*x*x*x-3.0*x)*sqrt(14.0)/4.0;
	}
}


double LegendreBasis::legendre_poly_prime(const int p, const double x)
{
        if(std::abs(x)>1.0)
        {
                return 0.0;
        }

        if (p==0)
        {
                return 0.0;
        }
        else if (p==1)
        {
                return std::sqrt(6.0)/2.0;
        }
        else if (p==2)
        {
                return (1.5*std::sqrt(10.0))*x;
        }
        else if (p==3)
        {
                return (15.0*x*x-3.0)*sqrt(14.0)/4.0;
        }
	
}
