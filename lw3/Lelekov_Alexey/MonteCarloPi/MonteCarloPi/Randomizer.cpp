#include "stdafx.h"
#include "Randomizer.h"

Randomizer::Randomizer()
{
}

double Randomizer::GenerateRandomDouble(const double &min, const double &max)
{
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

Point Randomizer::GenerateRandomPoint(const size_t squareSize)
{
	double max = (double)(squareSize / 2);
	double min = -max;
	return Point(GenerateRandomDouble(min, max), GenerateRandomDouble(min, max));
}

Randomizer::~Randomizer()
{
}