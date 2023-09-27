#ifndef FIXED_CPP
# define FIXED_CPP

# include <iostream>
# include <string>
# include <math.h>

class Fixed {
    private:
        int fixedValue;
        static const int fractalBit = 8;
    public:
        Fixed();
        Fixed(const Fixed& oldObj);
        Fixed(const int intFixed);
        Fixed(const float floatFixed);
        void operator=(const Fixed& oldObj);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);

#endif