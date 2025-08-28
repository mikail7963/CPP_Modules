#pragma once

#include <iostream>

class Fixed {
private:
	int fixedPointNumber;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& copy);
	~Fixed();

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};
