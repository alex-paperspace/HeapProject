#include "Point.h"

Point::Point() :
	m_x(0.0),
	m_y(0.0)
{
}

Point::Point(double const& x, double const& y) :
	m_x(x) ,
	m_y(y)
{
}

std::ostream & operator<<(std::ostream & os, Point & c)
{
	os << "X: " << c.m_x << "Y: " << c.m_y << std::endl;
	return os;
}
