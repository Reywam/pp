#include "stdafx.h"
#include "MonteCarlo.h"

size_t MonteCarlo::iterCount = 0;

DWORD WINAPI GeneratePointsInCircle(LPVOID param)
{
	size_t *info = (size_t*)(param);
	Randomizer rand;
	const size_t iterCount = *info;
	for (; Counter::GetCount() < iterCount;)
	{
		Counter::IncCount();
		if (Counter::GetCount() > iterCount)
		{
			break;
		}

		Point point = rand.GenerateRandomPoint(SQUARE_SIDE);
		double x = point.GetX();
		double y = point.GetY();
		if (x * x + y * y <= R)
		{
			Counter::IncPoint();
		}
	}
	return 0;
}

size_t MonteCarlo:: GetProgressBorder()
{
	return iterCount;
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
	GeneratePointsInCircle(&iterCount);
	result = MULT_COEFF * Counter::GetPoints() / iterCount;
}

double MonteCarlo::GetResult()
{
	return result;
}

MonteCarlo::~MonteCarlo()
{
}