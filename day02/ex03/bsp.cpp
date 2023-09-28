#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point){
    Point v0 = a;
    Point v1 = b;
    Point v2 = c;
    Point v3 = point;
    
    float d00 = (v1.getX().toFloat() - v0.getX().toFloat()) * (v1.getX().toFloat() - v0.getX().toFloat()) + (v1.getY().toFloat() - v0.getY().toFloat()) * (v1.getY().toFloat() - v0.getY().toFloat());
    float d01 = (v1.getX().toFloat() - v0.getX().toFloat()) * (v2.getX().toFloat() - v0.getX().toFloat()) + (v1.getY().toFloat() - v0.getY().toFloat()) * (v2.getY().toFloat() - v0.getY().toFloat());
    float d11 = (v2.getX().toFloat() - v0.getX().toFloat()) * (v2.getX().toFloat() - v0.getX().toFloat()) + (v2.getY().toFloat() - v0.getY().toFloat()) * (v2.getY().toFloat() - v0.getY().toFloat());
    float d20 = (v3.getX().toFloat() - v0.getX().toFloat()) * (v2.getX().toFloat() - v0.getX().toFloat()) + (v3.getY().toFloat() - v0.getY().toFloat()) * (v2.getY().toFloat() - v0.getY().toFloat());
    float d21 = (v3.getX().toFloat() - v0.getX().toFloat()) * (v1.getX().toFloat() - v0.getX().toFloat()) + (v3.getY().toFloat() - v0.getY().toFloat()) * (v1.getY().toFloat() - v0.getY().toFloat());

    float denom = d00 * d11 - d01 * d01;
    float u = (d11 * d20 - d01 * d21) / denom;
    float v = (d00 * d21 - d01 * d20) / denom;
    float num = 1.0 - u - v;
    float w = num;
    return (u >= 0.0) && (v >= 0.0) && (w >= 0.0);
}