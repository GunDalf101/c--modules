#include "Point.hpp"

Point::Point(): x(0), y(0){

}
Point::Point(const float x, const float y): x(x), y(y){

}
Point::Point(const Point& oldPoint): x(oldPoint.x), y(oldPoint.y){
    *this = oldPoint;
}
void Point::operator=(const Point& oldPoint){
    (void) oldPoint;
}
Point::~Point(){

}

Fixed Point::getX(){
    return this->x;
}

Fixed Point::getY(){
    return this->y;
}