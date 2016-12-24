#include "greens.hpp" 
#include <iostream>
#include "complex_bessel.h"
using namespace std;
using namespace sp_bessel;  

complex<double> Greens2D(double k, double r)
{
	double  kr = k * r;
	complex<double> C = 1.0j/4.0;
	//cout << "the value of C is " << C << endl << flush;
	complex<double> output = C * hankelH2(0, kr); 
	//cout << "the value of output is "  << output << endl << flush;
	return output;
}

