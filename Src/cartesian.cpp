#include "cartesian.hpp"
#include <iostream>
#include <cmath>

using namespace std;
Point::Point()
{
	mx = 0.0;
	my = 0.0;
}

Point::Point(double x, double y)
{
	mx = x;
	my = y;
}

double Point::GetX() const
{
	return mx;
}

double Point::GetY() const
{
	return my;
}

ostream& operator<<(ostream& output, const Point& p)
{
	output << "the coordiante of point is:";
	output << " (" << p.mx << ", " << p.my << ")"<< endl;
	return output;
}

Real_Vector::Real_Vector()
{
	mx = 0.0;
	my = 0.0;
}

Real_Vector::Real_Vector(double x, double y)
{
	mx = x;
	my = y;
}

Real_Vector::Real_Vector(Point p1, Point p2)
{
	SetVector(p1, p2);
}

double Real_Vector::GetX() const
{
	return mx;
}

double Real_Vector::GetY() const
{
	return my;
}

double Real_Vector::GetLength() const
{
	double tmp = mx*mx + my*my;
	return sqrt(tmp);

}

void Real_Vector::SetVector(Point& p1, Point& p2)
{
	mx = p2.GetX() - p1.GetX();
	my = p2.GetY() - p1.GetY();
}

void Real_Vector::SetX(double x)
{
	mx = x;
}

void Real_Vector::SetY(double y)
{
	my = y;
}

ostream& operator<<(ostream& output, const Real_Vector& vec)
{
	output << "the coordiante of vector is:";
	output << " (" << vec.mx << ", " << vec.my << ")"<< endl;
	output << "the length of vector is:";
	output << vec.GetLength() << endl;
	return output;
}



