#include "stdafx.h"
#include "MultithreadedMonteCarlo.h"
#include <Windows.h>
#include <vector>

MultithreadedMonteCarlo::MultithreadedMonteCarlo(const size_t &itersCount)	
	: MonteCarlo(itersCount)
{
}

void MultithreadedMonteCarlo::Run(const size_t &threadsCount)
{	
	for(size_t i = 1; i < threadsCount; i++) 
	{				
	}
	MonteCarlo::Run(NULL);
}

MultithreadedMonteCarlo::~MultithreadedMonteCarlo()
{
}