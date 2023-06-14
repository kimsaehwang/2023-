#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Rectangle2D.h"
#include "MyPoint.h"

Rectangle2D::Rectangle2D()
{
    x = y = 0.0;
    w = h = 1;
}

Rectangle2D::Rectangle2D( double x, double y, double w, double h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

double Rectangle2D::getPerimeter()
{
    return (h + w) * 2;
}

double Rectangle2D::getArea()
{
    return w * h;
}

bool Rectangle2D::contains(double x, double y)
{
    double min_x = this->x - this->w/2;
    double max_x = this->x + this->w/2;
    double min_y = this->y - this->h/2;
    double max_y = this->y + this->h/2;
    if (x >= min_x && x <= max_x && y >= min_y && y <= min_y)
        return true;
    else
        return false;
}

bool Rectangle2D::contains(Rectangle2D& r)
{
    double min_x = this->x - this->w / 2;
    double max_x = this->x + this->w / 2;
    double min_y = this->y - this->h / 2;
    double max_y = this->y + this->h / 2;

    double min_x1 = r.x - r.w / 2;
    double max_x1 = r.x + r.w / 2;
    double min_y1 = r.y - r.h / 2;
    double max_y1 = r.y + r.h / 2;
    if (x >= min_x1 && x <= max_x1 && y >= min_y1 && y <= min_y1)
        return true;
    else
        return false;
}
bool Rectangle2D::overlaps(Rectangle2D& r)
{
    double min_x = this->x - this->w / 2;
    double max_x = this->x + this->w / 2;
    double min_y = this->y - this->h / 2;
    double max_y = this->y + this->h / 2;

    double min_x1 = r.x - r.w / 2;
    double max_x1 = r.x + r.w / 2;
    double min_y1 = r.y - r.h / 2;
    double max_y1 = r.y + r.h / 2;
    if (x > min_x1 || x < max_x1 || y > min_y1 || y < min_y1)
        return true;
    else
        return false;
}
bool contains(const Rectangle2D& r, const MyPoint& d)
{
    if(d>)
}
