#pragma once
#include "Randomizer.h"
#include <iostream>
#include <Windows.h>
#include "Messenger.h"
#include <iostream>

const size_t R = 1;
const size_t SQUARE_SIDE = 2;
const double MULT_COEFF = 4;

class MonteCarlo
{
public:
	MonteCarlo(const size_t &itersCount);
	void Run();
	double GetResult();
	~MonteCarlo();
private:
	void GeneratePointsInCircle(const size_t &iterCount);
	size_t iterCount;
	double result = 0;
	static size_t points;
};