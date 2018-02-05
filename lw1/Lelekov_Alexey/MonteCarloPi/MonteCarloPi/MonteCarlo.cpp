#include "stdafx.h"
#include "MonteCarlo.h"

MonteCarlo::MonteCarlo()
{
}

void MonteCarlo::Run(const size_t &iterationsCount, size_t &count)
{
	Randomizer rand;
	size_t pointsInCircle = 0;
	for (; count < iterationsCount;)
	{		
		count++;
		if (count > iterationsCount)
		{
			break;
		}

		std::cout << count << "/" << iterationsCount << std::endl;
		Point point = rand.GenerateRandomPoint(SQUARE_SIDE);
		double x = point.GetX();
		double y = point.GetY();
		if (x * x + y * y <= R)
		{
			pointsInCircle++;
		}
	}

	result = MULT_COEFF * pointsInCircle / iterationsCount;
}

double MonteCarlo::GetResult()
{
	return result;
}

MonteCarlo::~MonteCarlo()
{
}