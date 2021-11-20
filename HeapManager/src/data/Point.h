#pragma once
#include <ostream>

class Point {
private:
	double m_x;
	double m_y;
public:
	Point();
	Point(double const& x, double const& y);
	friend std::ostream & operator<<(std::ostream& os, Point& c);
};