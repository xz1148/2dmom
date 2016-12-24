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
	void SetX(double x);
	void SetY(double y);
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
class Triangle
{
private:
	Point mPoints[3];
public:
	
	Triangle();
	Triangle(Point p1, Point p2, Point p3);
	Point& GetPoint(int i);
	double GetArea() const;
	// this function calculates the area of triangle
	double GetCenterX() const;
	// returns the x coordiante of center point
	double GetCenterY() const;
	// returns the y coordinate of center point
	void GetCenterPoint(Point& pc); 
	// sets the point pc to the center point of triangle
	friend std::ostream& operator<<(std::ostream& output, Triangle& tri);
};





#endif /* CARTESIAN_HPP */
