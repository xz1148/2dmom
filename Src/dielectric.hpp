#ifndef DIELECTRIC_HPP
#define DIELECTRIC_HPP
#include "cartesian.hpp"
#include <complex>
#include <iostream>
class Element : public Triangle
{
private:
	std::complex<double> m_eps_r;
	// the relative permittivity of element
public:
	Element(Triangle tri);
	// the element can be constructed from triangle
	Element(Triangle tri, std::complex<double> eps_r);
	// initialized form triangle and epsr
	Element(Point p1, Point p2, Point p3);
	// element can be constructed from 3 points
	Element(Point p1, Point p2, Point p3, std::complex<double> eps_r);
	// elements initialize from point and permittivity
	std::complex<double> GetRemoteE(Point p_remote, double omega);
	// calculates the remote scattering field when the element is excited by a unit E field
	// explanitions:
	// The remote field equals to:
	// Es_remote = -omega^2 * mu0 * eps_delta * (Ein + Es) * G(r,r') * d_S
	// 1j: imaginary number unit
	// omega: angular frequency
	// mu0: vaccum permeability
	// eps_delta; difference to the vacumm permittivity, eps - eps0
	// Ein + Es: the total field, set to be 1 when calculate 
	// G(r,r'): Greens function, r is location of field point, r' is location of source point
	// d_S: the area of element 
	std::complex<double> GetLocalE(double omega);
	double GetR(Point p_remote) const;
	friend std::ostream& operator << (std::ostream& output, Element element);
};


#endif /* DIELECTRIC_HPP*/
