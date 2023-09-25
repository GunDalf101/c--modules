# include "Fixed.hpp"

Fixed::Fixed(): fixedValue(0){
    std::cout << "Conjure lesser Class" << std::endl;
    std::cout << "Object Summoned: Default constructor called" << std::endl;
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