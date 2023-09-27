#ifndef FIXED_CPP
# define FIXED_CPP

# include <iostream>
# include <string>

class Fixed {
    private:
        int fixedValue;
        static const int fractalBit = 8;
    public:
        Fixed();
        Fixed(const Fixed& oldObj);
        void operator=(const Fixed& oldObj);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};


#endif