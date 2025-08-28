#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const int IntNumber)
{
	//std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = IntNumber << this->fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
	//std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = static_cast<int>(roundf(floatNumber * (1 << this->fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->fixedPointNumber = other.fixedPointNumber;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy) {
		this->fixedPointNumber = copy.fixedPointNumber;
	}
	return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    this->fixedPointNumber += 1;
    return old;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
    this->fixedPointNumber -= 1;
    return old;
}

Fixed& Fixed::operator++()
{
	this->fixedPointNumber += 1;
	return 	*this;
}

Fixed& Fixed::operator--()
{
	this->fixedPointNumber -= 1;
	return 	*this;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->fixedPointNumber > other.fixedPointNumber);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->fixedPointNumber < other.fixedPointNumber);
	
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->fixedPointNumber >= other.fixedPointNumber);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->fixedPointNumber <= other.fixedPointNumber);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->fixedPointNumber == other.fixedPointNumber);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->fixedPointNumber != other.fixedPointNumber);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}


Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointNumber;
}

void Fixed::setRawBits( int const raw )
{
	this->fixedPointNumber = raw;
}
