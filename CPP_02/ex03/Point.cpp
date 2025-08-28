#include "Point.hpp"

float Point::getX() const
{
	return this->x.toFloat();
}

float Point::getY() const
{
	return this->y.toFloat();
}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point() : x(0), y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float xValue, const float yValue): x(xValue), y(yValue) 
{
	//std::cout << "Float constructor called" << std::endl;
}


Point& Point::operator=(const Point& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	(void)copy;
	return *this;
}

Point::~Point()
{
	//std::cout << "Destructor called" << std::endl;
}
