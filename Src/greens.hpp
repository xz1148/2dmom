#ifndef GREENS_HPP
#define GREENS_HPP
#include <complex>
std::complex<double> Greens2D(double k, double r);
// this function calculates the greens funciton in 2d, which is
// (1j/4) * HankelH2(0, k0*r); hankel funciton of the second kind
// k: the complex wave number
// r: the distance from source to field point






#endif /* GREENS_HPP */
