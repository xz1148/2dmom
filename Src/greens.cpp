#include "greens.hpp" 
#include <iostream>
#include "complex_bessel.h"
#include <armadillo>
#include <vector>
#include "cartesian.hpp"
#include "dielectric.hpp"
#include "EMConst.hpp"
#include <cmath>
#include <omp.h>
#include <boost/math/special_functions.hpp>
#include <time.h>

using namespace std;
using namespace sp_bessel;  
using namespace arma;

complex<double> Greens2D(double k, double r)
{
	double  kr = k * r;
	complex<double> C = 1.0j/4.0;
	//cout << "the value of C is " << C << endl << flush;
	complex<double> output = C * boost::math::cyl_hankel_2(0, kr); 
	//cout << "the value of output is "  << output << endl << flush;
	return output;
}

Mat<complex<double> > GMat(vector<Element> elements,double omega)
{
	int N_dim = elements.size();
	Mat<complex<double> > GMat(N_dim, N_dim);
	vector<Point> pc; // the vector of incenter of elements
	for (int i=0; i<N_dim; i++)
	{
		Point pc_tmp;
		elements[i].GetCenterPoint(pc_tmp);
		pc.push_back(pc_tmp);
	}
	double t_start, t_end;
	t_start = omp_get_wtime();
	#pragma omp parallel
	{
		#pragma omp for
		for (int i=0; i<N_dim; i++)
		{
			#pragma omp parallel for 
			for (int j=0; j<N_dim; j++)
			{
				if (i==j) {GMat(i, j)=elements[j].GetLocalE(omega);}
				else {GMat(i, j)=elements[j].GetRemoteE(pc[i], omega);}
			}
		}
	}	
	t_end = omp_get_wtime();
	cout << "the time of generating G matrix is " << (t_end - t_start) << " seconds" << endl;
	return GMat;
}

Col<complex<double> > Ein(vector<Element> elements, double omega)
{
	int N_Dim = elements.size();
	double k0 = omega * sqrt(EPS0 * MU0);
	Col<complex<double> > Ein(N_Dim);
	for (int i=0; i<N_Dim; i++)
	{
		complex<double> alpha = 1.0i * k0 * elements[i].GetCenterX(); // field incident from right
		Ein(i) = exp(alpha);
	}
	return Ein;
}


