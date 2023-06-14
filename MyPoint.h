#pragma once

class MyPoint
{
private:
	double x, y;
public:
	MyPoint();
	MyPoint(double x, double y);
	double getX();
	double getY();
	double length(MyPoint& dot);
};