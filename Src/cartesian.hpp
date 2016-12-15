#ifndef CARTESIAN_HPP
#define CARTESIAN_HPP
#include <iostream>


class Point
{
private:
	double mx;
	double my;
public:
	Point();
	Point(double x, double y);
	double GetX() const;
	double GetY() const;
	friend std::ostream& operator<<(std::ostream& output, const Point& p);
};


class Real_Vector
{
private:
	double mx;
	double my;
public:
	Real_Vector();
	Real_Vector(double x, double y);
	Real_Vector(Point p1, Point p2);
	double GetX() const;
	double GetY() const;
	double GetLength() const;
	void SetVector(Point& p1, Point& p2);
	void SetX(double x);
	void SetY(double y);
	friend std::ostream& operator<<(std::ostream& output, const Real_Vector& vec);
};






#endif /* CARTESIAN_HPP */
