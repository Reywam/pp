#pragma once
#include "Randomizer.h"
#include <iostream>

class MonteCarlo
{
public:
	MonteCarlo();
	void MonteCarlo::Run(const size_t &iterationsCount, size_t &count);
	double GetResult();
	~MonteCarlo();
private:
	const size_t R = 1;
	const size_t SQUARE_SIDE = 2;
	const double MULT_COEFF = 4;
	double result = 0;
};