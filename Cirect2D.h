#pragma once
class Cirect2D
{
private:
	double x, y, r;
public:
	Cirect2D();
	Cirect2D(double x, double y,double r);
	double getArea();//면적
	double getPerimeter();//둘레
	bool contains(double x, double y);
	bool contains(Cirect2D& circle);
	bool overlaps(Cirect2D& circle);
	bool contains(Cirect2D& circle, MyPoint& d);
};