#include "Quad.h"

Quad::Quad(const int DIM)
{
	 //Limited number of quadrautere points.
	 gl_quad_num=std::vector<int>{1,2,3,4,5,6};
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
