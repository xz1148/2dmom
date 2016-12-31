#include "dielectric.hpp"
#include <iostream>
#include "cartesian.hpp"
#include <cmath>
#include "EMConst.hpp"
#include <complex>
#include "greens.hpp"
using namespace std;

Element::Element(Triangle tri)
{
	GetPoint(0) = tri.GetPoint(0);
	GetPoint(1) = tri.GetPoint(1);
	GetPoint(2) = tri.GetPoint(2);
	m_eps_r = 1.0;
}

Element::Element(Triangle tri, complex<double> eps_r)
{
	GetPoint(0) = tri.GetPoint(0);
	GetPoint(1) = tri.GetPoint(1);
	GetPoint(2) = tri.GetPoint(2);
	m_eps_r = eps_r;
}

Element::Element(Point p1, Point p2, Point p3):Triangle(p1, p2, p3)
{
	m_eps_r = 1.0;
}

Element::Element(Point p1, Point p2, Point p3, complex<double> eps_r):Triangle(p1, p2, p3)
{
	m_eps_r = eps_r;
}

double Element::GetR(Point p_remote) const
{
	double dx = p_remote.GetX() - GetCenterX();
	double dy = p_remote.GetY() - GetCenterY();
	double dr = sqrt(dx*dx + dy*dy);
	return dr;
}

complex<double> Element::GetRemoteE(Point p_remote, double omega)
{
	double r = GetR(p_remote);
	double k0 = omega * sqrt(MU0 * EPS0);
	complex<double> eps = m_eps_r * EPS0;
	complex<double> eps_delta = eps - EPS0;
	double d_S = GetArea();
	complex<double> G_r = Greens2D(k0, r);
//	cout << "r: " << r << endl;
//	cout << "k0: " << k0 <<endl;
//	cout << "eps: " << eps <<endl;
//	cout << "eps_delta: " << eps_delta <<endl;
//	cout << "area: " << d_S <<endl;
//	cout << "G_r: " << G_r <<endl;
	complex<double> RemoteE = -omega*omega * MU0 * eps_delta * 1.0 * G_r * d_S;
	return RemoteE;
}

complex<double> Element::GetLocalE(double omega)
{
	double gamma = 0.5772156649015328606065120900824024310421; //Euler-Mascheroni constant
	double k0 = omega * sqrt(MU0 * EPS0);
	complex<double> eps = m_eps_r * EPS0;
	complex<double> eps_delta = eps - EPS0;
	double dS = GetArea();
	double r0 = sqrt(dS / M_PI);
	double z = k0 * r0 / 2.0;
	double G_dS_imag = dS / 4.0;
	double G_dS_real = (2.0/k0) * (2.0/k0) * (z*z*log(z)/2.0 - z*z/4.0) + gamma*r0*r0/2.0;
	complex<double> G_dS = G_dS_real + 1.0i * G_dS_imag;
	complex<double> LocalE = -omega*omega * MU0 * eps_delta * 1.0 * G_dS;
	return LocalE;
}

std::ostream& operator << (std::ostream& output, Element element)
{
	output << "the content of element is: " << endl;
	output << "Point 1:" << endl;
	output << element.GetPoint(0) << endl;
	output << "Point 2:" << endl;
	output << element.GetPoint(1) << endl;
	output << "Point 3:" << endl;
	output << element.GetPoint(2) << endl;
	output << "The area is:" << endl;
	output << element.GetArea() << endl;
	output << "The coordiante of center point is:" << endl;
	output << "(" << element.GetCenterX() << " , " << element.GetCenterY() << ")"<< endl;
	output << "The relative permittivity is: " << endl;
	output << element.m_eps_r << endl;
	return output;
}

