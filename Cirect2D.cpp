#define M_PI 3.14159265358979323846
#include "Cirect2D.h"
#include"MyPoint.h"
#include<cmath>
Cirect2D::Cirect2D()
{
    x = y = 0;
    r = 1;
}

Cirect2D::Cirect2D(double x, double y,double r)
{
    this->x = x;
    this->y = y;
    this->r = r;
}

double Cirect2D::getArea()
{
    return pow(r, 2) * M_PI;
}

double Cirect2D::getPerimeter()
{
    return r * 2 * M_PI;
}

bool Cirect2D::contains(double x, double y)
{
    double Distance;
    Distance = pow(this->x - x, 2) + pow(this->y - y, 2);
    Distance = sqrt(Distance);
    if (this->r > Distance)
        return true;
    return false;
}

bool Cirect2D::contains(Cirect2D& circle)
{
    double Distance;
    Distance = pow(this->x - x, 2) + pow(this->y - y, 2);
    Distance = sqrt(Distance);
    if (this->r + r > Distance)
        return true;
    return false;
}

bool Cirect2D::overlaps(Cirect2D& circle)
{
    double Distance;
    Distance = pow(this->x - x, 2) + pow(this->y - y, 2);
    Distance = sqrt(Distance);
    if (this->r + r > Distance)
        return true;
    return false;
}
bool contains(Cirect2D& circle, MyPoint& d)
{
    double Distance;
    Distance = pow(circle.x - d.getX(), 2) + pow(circle.y - d.getY(), 2);
    Distance = sqrt(Distance);
    if (circle.r > Distance)
        return true;
    return false;
}
