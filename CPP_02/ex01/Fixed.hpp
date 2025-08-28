#pragma once

#include <iostream>
#include <cmath>

class Fixed {
private:
	int fixedPointNumber;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& copy);
	~Fixed();

	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
