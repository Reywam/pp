#pragma once
#include "Randomizer.h"
#include <iostream>
#include <Windows.h>
#include "Counter.h"
#include "ThreadHandler.h"

const size_t R = 1;
const size_t SQUARE_SIDE = 2;
const double MULT_COEFF = 4;

DWORD WINAPI GeneratePointsInCircle(LPVOID param);

struct ThreadInfo
{
	ThreadInfo(size_t iterCount)
	{
		this->iterCount = iterCount;		
	}
	size_t iterCount;
};

class MonteCarlo
{
public:	
	MonteCarlo(const size_t &itersCount);
	void Run(size_t threadsCount);
	double GetResult();
	~MonteCarlo();
private:	
	size_t iterCount;
	double result = 0;
};