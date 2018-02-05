#pragma once
#include "Point.h"

class Randomizer
{
public:
	Randomizer();
	double GenerateRandomDouble(const double &min, const double &max);
	Point GenerateRandomPoint(const size_t squareSize);
	~Randomizer();
};