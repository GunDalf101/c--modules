# include "Fixed.hpp"

Fixed::Fixed(): fixedValue(0){

}

Fixed::Fixed(const int intFixed): fixedValue(intFixed * (1 << this->fractalBit)){

}

Fixed::Fixed(const float floatFixed): fixedValue(roundf(floatFixed * (1 << this->fractalBit))){

}

Fixed::Fixed(const Fixed& oldObj){
    *this = oldObj;
}

void Fixed::operator=(const Fixed& oldObj){
    this->setRawBits(oldObj.fixedValue);
}

Fixed::~Fixed(){

}

int Fixed::getRawBits( void ) const{
    return (this->fixedValue);
}
void Fixed::setRawBits( int const raw ){
    this->fixedValue = raw;
}

float Fixed::toFloat( void ) const{
    return (float)this->fixedValue / (float)(1 << (Fixed::fractalBit));
}

int Fixed::toInt( void ) const{
    return (int)this->fixedValue / (int)(1 << (Fixed::fractalBit));
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr){
    stream << nbr.toFloat();
    return stream;
}

bool Fixed::operator<(const Fixed &num){
    return this->fixedValue < num.getRawBits();
}

bool Fixed::operator>(const Fixed &num){
    return this->fixedValue > num.getRawBits();
}

bool Fixed::operator<=(const Fixed &num){
    return this->fixedValue <= num.getRawBits();
}

bool Fixed::operator>=(const Fixed &num){
    return this->fixedValue >= num.getRawBits();
}

bool Fixed::operator==(const Fixed &num){
    return this->fixedValue == num.getRawBits();
}

bool Fixed::operator!=(const Fixed &num){
    return this->fixedValue != num.getRawBits();
}

Fixed Fixed::operator+(const Fixed &num){
    return Fixed(this->toFloat() + num.toFloat());
}
Fixed Fixed::operator-(const Fixed &num){
    return Fixed(this->toFloat() - num.toFloat());
}
Fixed Fixed::operator*(const Fixed &num){
    return Fixed(this->toFloat() * num.toFloat());
}
Fixed Fixed::operator/(const Fixed &num){
    return Fixed(this->toFloat() / num.toFloat());
}


Fixed &Fixed::operator++(void)
{
	this->fixedValue += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(this->fixedValue * toFloat());
	this->fixedValue += 1;
	return tmp;
}


Fixed &Fixed::operator--(void)
{
	this->fixedValue -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(this->fixedValue * toFloat());
	this->fixedValue -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}


const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}