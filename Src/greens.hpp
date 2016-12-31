#ifndef GREENS_HPP
#define GREENS_HPP
#include <complex>
#include <armadillo>
#include <vector>
#include "dielectric.hpp"
std::complex<double> Greens2D(double k, double r);
// this function calculates the greens funciton in 2d, which is
// (1j/4) * HankelH2(0, k0*r); hankel funciton of the second kind
// k: the complex wave number
// r: the distance from source to field point
arma::Mat<std::complex<double> > GMat(std::vector<Element> elements,double omega);

arma::Col<std::complex<double> > Ein(std::vector<Element> elements, double omega);


#endif /* GREENS_HPP */
