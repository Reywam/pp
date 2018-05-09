#include "stdafx.h"
#include "Point.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(const double &x, const double &y)
{
	this->x = x;
	this->y = y;
}

double Point::GetX()
{
	return x;
}

double Point::GetY()
{
	return y;
}

Point::~Point()
{
}