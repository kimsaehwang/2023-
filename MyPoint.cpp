#include "MyPoint.h"
#include<cmath>
MyPoint::MyPoint()
{
    x = y = 0.0;
}

MyPoint::MyPoint(double x, double y)
{
    this->x = x;
    this->y = y;
}
double MyPoint::getX()
{
    return x;
}
double MyPoint::getY()
{
    return y;
}
double MyPoint::length(MyPoint& dot)
{
    double Distance;
    Distance = pow(x - dot.x, 2) + pow(y - dot.y, 2);
    Distance = sqrt(Distance);
    return Distance;
}
