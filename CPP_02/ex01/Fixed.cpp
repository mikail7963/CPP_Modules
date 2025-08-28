#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const int IntNumber)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = IntNumber << this->fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = static_cast<int>(roundf(floatNumber * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

float Fixed::toFloat( void ) const
{
	return static_cast<float>(this->fixedPointNumber) / (1 << this->fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->fixedPointNumber >> this->fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}


Fixed& Fixed::operator=(const Fixed& copy)
{
	if (this != &copy) {
		this->fixedPointNumber = copy.fixedPointNumber;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointNumber;
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPointNumber = raw;
}
