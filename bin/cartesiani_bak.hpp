#ifndef CARTESIAN_HPP
#define CARTESIAN_HPP

#include <iostream>
#include <complex>

template<typename Type>
class Vector2D
{
	private:
		Type mxy[2]; // the array stores x coordinate and y coordiante
	public:
		Vector2D();
		Vector2D(const Type* xy); //input is array of coordinates
		template<typename T>
		friend std::ostream& operator<<(std::ostream& output, const Vector2D<T>& vector);
};

template <>
Vector2D<double>::Vector2D() // the default constructor for real vector is to set zero
{
	mxy[0] = 0;
	mxy[1] = 0;
}

template <>
Vector2D<std::complex<double> >::Vector2D() // the default constructor for real vector is to set zero
{
	mxy[0] = 0+0i;
	mxy[1] = 0+0i;
}

template<typename Type>
Vector2D<Type>::Vector2D(const Type* xy)
{
	mxy[0] = xy[0];
	mxy[1] = xy[1];
}

//template<typename Type>
//Type* Vector2D<Type>::GetXY() 
//{
//	return mxy;
//}
	

template<typename Type>
std::ostream& operator<<(std::ostream& output, const Vector2D<Type>& vector)
{
	output << "vector is: ";
	output << vector.mxy[0] << ", " << vector.mxy[1] << std::endl;
	return output;
}

#endif
