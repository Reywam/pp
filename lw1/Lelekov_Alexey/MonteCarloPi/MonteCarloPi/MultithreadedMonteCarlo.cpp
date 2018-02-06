#include "stdafx.h"
#include "MultithreadedMonteCarlo.h"
#include <Windows.h>
#include <vector>
#include "ThreadHandler.h"

MultithreadedMonteCarlo::MultithreadedMonteCarlo(const size_t &itersCount)	
	: MonteCarlo(itersCount)
{
}

void MultithreadedMonteCarlo::Run(const size_t &threadsCount)
{	
	ThreadHandler handler;
	for(size_t i = 1; i < threadsCount; i++) 
	{
		handler.Add(MonteCarlo::Run(NULL));
	}
	MonteCarlo::Run(NULL);
}

MultithreadedMonteCarlo::~MultithreadedMonteCarlo()
{
}