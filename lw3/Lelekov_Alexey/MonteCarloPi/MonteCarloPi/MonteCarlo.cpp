#include "stdafx.h"
#include "MonteCarlo.h"

size_t MonteCarlo::points = 0;

void MonteCarlo::GeneratePointsInCircle(const size_t &iterCount)
{
	Randomizer rand;
	#pragma omp parallel
	{
		#pragma omp for
		for (int i = 0; i < iterCount; ++i)
		{
			Point point = rand.GenerateRandomPoint(SQUARE_SIDE);
			double x = point.GetX();
			double y = point.GetY();
			if (x * x + y * y <= R)
			{
				InterlockedIncrement(&points);
			}
		}
	}
}

MonteCarlo::MonteCarlo(const size_t &itersCount)
{
	if (itersCount >= 0)
	{
		iterCount = itersCount;
	}
}

void MonteCarlo::Run()
{
	GeneratePointsInCircle(iterCount);
	result = MULT_COEFF * points / iterCount;
}

double MonteCarlo::GetResult()
{
	return result;
}

MonteCarlo::~MonteCarlo()
{
}