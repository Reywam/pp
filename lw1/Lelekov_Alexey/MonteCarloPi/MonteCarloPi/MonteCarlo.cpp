#include "stdafx.h"
#include "MonteCarlo.h"
#include "Windows.h"

MonteCarlo::MonteCarlo(const size_t &itersCount)
{
	if (itersCount >= 0) 
	{
		this->itersCount = itersCount;
	}
}

DWORD WINAPI MonteCarlo::Run(LPVOID t)
{	
	static size_t count = 0;
	Randomizer rand;
	size_t pointsInCircle = 0;
	for (; count <  itersCount;)
	{		
		count++;
		if (count > this->itersCount)
		{
			break;
		}

		std::cout << count << "/" << this->itersCount << std::endl;
		Point point = rand.GenerateRandomPoint(SQUARE_SIDE);
		double x = point.GetX();
		double y = point.GetY();
		if (x * x + y * y <= R)
		{
			pointsInCircle++;
		}
	}

	result = MULT_COEFF * pointsInCircle / this->itersCount;

	return 0;
}

double MonteCarlo::GetResult()
{
	return result;
}

MonteCarlo::~MonteCarlo()
{
}