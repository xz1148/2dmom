#include "cartesian.hpp"
#include <iostream>
#include <fstream>
#include <complex>
#include <string>
#include <complex_bessel.h>
#include "mesh.hpp"

using namespace std;
using namespace sp_bessel;

int main(int argc, char** argv)
{
	double x = 1;
	complex<double> y = 1;
	complex<double> z = hankelH1(x,y);
	cout << z << endl;
	Point p1(2.0, 2.0);
	Point p2(3.0, 5.0);
	Real_Vector v1(p1, p2);
	cout << v1 << endl;
	cout << v1.GetLength() << endl;
	StartMesh();
	ReadMesh();
	return 0;
}	

