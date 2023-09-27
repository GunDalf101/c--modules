# include "Fixed.hpp"

Fixed::Fixed(): fixedValue(0){
    std::cout << "Conjure lesser Class" << std::endl;
    std::cout << "Object Summoned: Default constructor called" << std::endl;
}

Fixed::Fixed(const int intFixed): fixedValue(intFixed * (1 << this->fractalBit)){
    std::cout << "Conjure lesser Class" << std::endl;
    std::cout << "Object Summoned: Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatFixed): fixedValue(roundf(floatFixed * (1 << this->fractalBit))){
    std::cout << "Conjure lesser Class" << std::endl;
    std::cout << "Object Summoned: Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& oldObj){
    std::cout << "Clone Object: Copy constructor called" << std::endl;
    *this = oldObj;
}

void Fixed::operator=(const Fixed& oldObj){
    std::cout << "Mirror Object Stats: Copy assignment operator called" << std::endl;
    this->setRawBits(oldObj.fixedValue);
}

Fixed::~Fixed(){
    std::cout << "Object Disenchanted: Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedValue);
}
void Fixed::setRawBits( int const raw ){
    this->fixedValue = raw;
}

float Fixed::toFloat( void ) const{
    return (float)this->fixedValue / (float)(1 << (Fixed::fractalBit));
}

int Fixed::toInt( void ) const{
    return this->fixedValue >> Fixed::fractalBit;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr){
    stream << nbr.toFloat();
    return stream;
}