#include "cartesian.hpp"
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <complex>
#include <string>
#include "complex_bessel.h"
#include "mesh.hpp"
#include "plot.hpp"
#include "EMConst.hpp"
#include "greens.hpp"
#include "dielectric.hpp"
#include "readmatlab.hpp"
#include <armadillo>
#include <omp.h>

using namespace std;
using namespace sp_bessel; using namespace arma;


int main(int argc, char** argv)
{
//	double k=1;
//	complex<double> output;
//	double t_start = omp_get_wtime();
//	double N_threads = omp_get_num_threads();
//	cout << "number of threads: " << N_threads << endl;
//#pragma omp parallel for
//	for (int i=0; i<10000000; i++)
//	{
//		output = Greens2D(k, 1.0+i*1.0e-7);
//	}
//	
//	double t_end = omp_get_wtime();
//	cout << "time elapsed: " << t_end - t_start << endl;
//	return 0;
	int n_dl;
	double freq_MHz;
	cout << "please input the mesh factor " << endl;
	cin >> n_dl;
	cout << "please input the frequency " << endl;
	cin  >> freq_MHz;

	double freq = freq_MHz * 1e6;
	double omega = 2*M_PI*freq;
	double lambda = c0 / freq;
	complex<double> eps_r = 10.0 - 10.0i;
	complex<double> eps1 = EPS0 * eps_r;
	double sigma = -imag(eps1)*omega; //conductivity
	double radii = 0.5;
	double lc = lambda/n_dl;

	Mat<complex<double> > G;
	cx_vec Ei;
	cx_vec E;
	double P_loss;
	vector<Point> points, pc;	
	vector<Triangle> triangles;	
	vector<Element> elements;
	
	CreateGeo(radii, lc);
	StartMesh();
	ReadMesh(points, triangles);	

	int N_tri = triangles.size();
	vec area(N_tri);
	for (int i=0; i<N_tri; i++)
	{
		Point pc_buf;
		Element element_buf(triangles[i], eps_r);
		elements.push_back(element_buf);
		elements[i].GetCenterPoint(pc_buf);
		pc.push_back(pc_buf);
		area[i] = elements[i].GetArea();
	}
	cout << "Number of elements is " << triangles.size() << endl;
	cout << "Generating G matrix" << endl;
	G = GMat(elements, omega);
//	cout << "The time of generating G matrix is " << time_end - time_start << " seconds" << endl;
	cout << "Generating right end" << endl;
	Ei = Ein(elements, omega);
	cout << "solving equation " << endl;
	E = solve(G - eye<cx_mat>(N_tri, N_tri), -Ei);
	P_loss = sum(0.5 * sigma * abs(E) % abs(E) % area);
	cout << P_loss << endl;	
	cout << sum(area) << endl;
	cout << M_PI * radii * radii << endl;
	return 0;
}	

