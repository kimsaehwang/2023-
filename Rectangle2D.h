#pragma once

class Rectangle2D
{
private:
	double x, y, w, h;
public:
	Rectangle2D();
	Rectangle2D(double x, double y, double w, double h);
	double getArea();//면적
	double getPerimeter();//둘레
	bool contains(double x, double y);
	bool contains(Rectangle2D& r);
	bool overlaps(Rectangle2D& r);
	bool contains(Rectangle2D& r, MyPoint& d);
};