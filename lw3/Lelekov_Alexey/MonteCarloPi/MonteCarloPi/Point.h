#pragma once
class Point
{
public:
	Point();
	Point(const double &x, const double &y);
	double GetX();
	double GetY();
	~Point();
private:
	double x;
	double y;
};

