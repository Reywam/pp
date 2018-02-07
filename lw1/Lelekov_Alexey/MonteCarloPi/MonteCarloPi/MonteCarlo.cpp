#include "stdafx.h"
#include "MonteCarlo.h"

DWORD WINAPI GeneratePointsInCircle(LPVOID param)
{			
	ThreadInfo *info = (ThreadInfo*)(param);
	Randomizer rand;
	const size_t iterCount = info->iterCount;
	for (; Counter::GetCount() < iterCount;)
	{		
		Counter::IncCount();		
		if (Counter::GetCount() > iterCount)
		{
			break;
		}

		std::cout << Counter::GetCount() << "/" << iterCount << std::endl;
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

MonteCarlo::MonteCarlo(const size_t &itersCount)
{
	if (itersCount >= 0) 
	{		
		iterCount = itersCount;
	}
}

void MonteCarlo::Run(size_t threadsCount)
{
	ThreadHandler handler;
	if (threadsCount > 1) {		
		for (size_t i = 1; i < threadsCount; i++)
		{
			handler.Add(GeneratePointsInCircle, &iterCount);
		}		
	}

	if (!handler.empty()) {
		handler.JoinAll();
	}

	//ThreadInfo info(iterCount);
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