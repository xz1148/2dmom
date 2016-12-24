#include "cartesian.hpp"
#include <iostream>
#include <cmath>
#include <armadillo>


using namespace arma;
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

void Point::SetX(double x)
{
	mx = x;
}

void Point::SetY(double y)
{
	my = y;
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

Triangle::Triangle()
{
}

Triangle::Triangle(Point p1, Point p2, Point p3)
{
	mPoints[0] = p1;
	mPoints[1] = p2;
	mPoints[2] = p3;
}

Point& Triangle::GetPoint(int i)
{
	return mPoints[i];
}

double Triangle::GetArea() const
{
	double v1[2];
	double v2[2];  // the two vectors formed a triangle
	v1[0] = mPoints[1].GetX() - mPoints[0].GetX(); 
	v1[1] = mPoints[1].GetY() - mPoints[0].GetY(); 
	v2[0] = mPoints[2].GetX() - mPoints[0].GetX(); 
	v2[1] = mPoints[2].GetY() - mPoints[0].GetY(); 
	mat Mat_Area(2,2); // construct a 2*2 matrix
	Mat_Area(0,0) = v1[0];
	Mat_Area(0,1) = v1[1];
	Mat_Area(1,0) = v2[0];
	Mat_Area(1,1) = v2[1]; 
	double Area_para_quad = det(Mat_Area); // the area of parallel duadrilateral formed by v1 and v2
	double Area_Triangle = Area_para_quad / 2.0;
	return Area_Triangle;
}

double Triangle::GetCenterX() const
{
	double x1 = mPoints[0].GetX();
	double x2 = mPoints[1].GetX();
	double x3 = mPoints[2].GetX();
	return (x1 + x2 + x3) / 3.0;
}

double Triangle::GetCenterY() const
{
	double y1 = mPoints[0].GetY();
	double y2 = mPoints[1].GetY();
	double y3 = mPoints[2].GetY();
	return (y1 + y2 + y3) / 3.0;
}

void Triangle::GetCenterPoint(Point& pc)
{
	pc.SetX(GetCenterX());
	pc.SetY(GetCenterY());
}

std::ostream& operator<<(std::ostream& output, Triangle& tri)
{
	output << "The info of the triangle are :" << endl;
	output << "Point 1:" << endl;
	output << tri.GetPoint(0) << endl;
	output << "Point 2:" << endl;
	output << tri.GetPoint(1) << endl;
	output << "Point 3:" << endl;
	output << tri.GetPoint(2) << endl;
	output << "The area is:" << endl;
	output << tri.GetArea() << endl;
	output << "The coordiante of center point is:" << endl;
	output << "(" << tri.GetCenterX() << " , " << tri.GetCenterY() << ")"<< endl;
	return output;
}
