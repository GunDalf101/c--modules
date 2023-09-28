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
        ~Fixed();

        bool operator<(const Fixed &num);
        bool operator>(const Fixed &num);
        bool operator<=(const Fixed &num);
        bool operator>=(const Fixed &num);
        bool operator==(const Fixed &num);
        bool operator!=(const Fixed &num);

        void operator=(const Fixed& oldObj);

        Fixed operator+(const Fixed &num);
        Fixed operator-(const Fixed &num);
        Fixed operator*(const Fixed &num);
        Fixed operator/(const Fixed &num);

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr);


#endif