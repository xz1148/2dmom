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

using namespace std;
using namespace sp_bessel;

int main(int argc, char** argv)
{

//	double mesh_factor;
//	double rad;
//	double freq = 100e6;
//	double lambda = c0 / freq;
//	double k0 = 2 * M_PI / lambda;
//	double r = 1;
//
//
//	cout << "Please input the radius of cylinder:" << endl;
//	cin >> rad;
//	cout << "Please input the mesh factor (segment_length = radius / mesh_factor)" << endl;
//	cin >> mesh_factor;
//	vector<Point> Points;
//	vector<Triangle> Triangles;
//	vector<Element> Elements;
//	double lc = rad / mesh_factor;
//	CreateGeo(rad, lc);
//	StartMesh();
//	ReadMesh(Points, Triangles);
//	double area = 0.0;
//	int NTriangles = Triangles.size();
//	for (int i=0; i<NTriangles; i++)
//	{
//		area += Triangles[i].GetArea(); // calculate the total area
//	}
//	cout << "the area of cylinder cross section is " << setprecision(15) << area << endl;
//	cout << "the real area is " << M_PI * rad * rad << endl;
//	cout << "the permittivity is " << EPS0 << endl;
//	cout << "k0r is" << k0 * r << endl;
//	cout << "the output of greens function is " << Greens2D(k0, r) << endl;
//	cout << Triangles[0] << endl;
//
//	for (int i=0; i<NTriangles; i++)
//	{
//		Element element_tmp(Triangles[i]);
//		Elements.push_back(element_tmp);
//	}
//
//
//	cout << Elements[0] << endl;
//
//	Elements[0].GetPoint(0).SetX(1.0);
//	Elements[0].GetPoint(0).SetY(2.0);
//
//	cout << Triangles[0] << endl;
//	cout << Elements[0] << endl;

//	for (int i=0; i<NPoint; i++)
//	{
//	cout << "the coordinate of point is: " << Points[i] << endl;
//	}
//	cout << "number of points is: "	 << NPoint << endl;
//	Point p1, p2, p3;
//	p1.SetX(1);
//	p1.SetY(1);
//	Triangle tri(p1, p2, p3);
//	cout << tri.GetPoint(0) << endl;
//
	int idx;
	vector<Point> p1, p2, p3;
	vector<Element> elements;
	ReadMATLAB(p1, p2, p3);
	int N_tri = p1.size();
	double area = 0.0;
	for (int i=0; i<N_tri; i++)
	{
		Element element_buf(p1[i], p2[i], p3[i]);
		elements.push_back(element_buf);
		area += elements[i].GetArea();
	}
	cout << "Number of points is " << p1.size() << endl;
	cout << "please input the index of p1 p2 p3" << endl;
	cin >> idx;
	cout << elements[idx] << endl;
	cout << "the total area is " << area << endl;
	return 0;
}	

