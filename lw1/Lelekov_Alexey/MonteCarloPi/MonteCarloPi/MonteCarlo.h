#pragma once
#include "Randomizer.h"
#include <iostream>
#include <Windows.h>

class MonteCarlo
{
public:	
	MonteCarlo(const size_t &itersCount);
	DWORD WINAPI Run(LPVOID t);		
	double GetResult();
	~MonteCarlo();
private:
	const size_t R = 1;
	const size_t SQUARE_SIDE = 2;
	const double MULT_COEFF = 4;	
	size_t iterCount;
	double result = 0;
};