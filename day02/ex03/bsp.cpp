#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Point v0 = a;
    Point v1 = b;
    Point v2 = c;
    Point v3 = point;
    Fixed zero;
    Fixed one(1.0f);
    
    float d00 = (v1.getX().toFloat() - v0.getX().toFloat()) * (v1.getX().toFloat() - v0.getX().toFloat()) + (v1.getY().toFloat() - v0.getY().toFloat()) * (v1.getY().toFloat() - v0.getY().toFloat());
    float d01 = (v1.getX().toFloat() - v0.getX().toFloat()) * (v2.getX().toFloat() - v0.getX().toFloat()) + (v1.getY().toFloat() - v0.getY().toFloat()) * (v2.getY().toFloat() - v0.getY().toFloat());
    float d11 = (v2.getX().toFloat() - v0.getX().toFloat()) * (v2.getX().toFloat() - v0.getX().toFloat()) + (v2.getY().toFloat() - v0.getY().toFloat()) * (v2.getY().toFloat() - v0.getY().toFloat());
    float d20 = (v3.getX().toFloat() - v0.getX().toFloat()) * (v2.getX().toFloat() - v0.getX().toFloat()) + (v3.getY().toFloat() - v0.getY().toFloat()) * (v2.getY().toFloat() - v0.getY().toFloat());
    float d21 = (v3.getX().toFloat() - v0.getX().toFloat()) * (v1.getX().toFloat() - v0.getX().toFloat()) + (v3.getY().toFloat() - v0.getY().toFloat()) * (v1.getY().toFloat() - v0.getY().toFloat());

    float abcArea = d00 * d11 - d01 * d01;
    Fixed alpha = (d11 * d20 - d01 * d21) / abcArea;
    Fixed beta = (d00 * d21 - d01 * d20) / abcArea;
    float num = 1.0 - alpha.toFloat() - beta.toFloat();
    Fixed lambda = num;
    std::cout << alpha << std::endl;
    std::cout << beta << std::endl;
    std::cout << lambda << std::endl;
    return (alpha > zero) && (beta > zero) && (lambda > zero);
}