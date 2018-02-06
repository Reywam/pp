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
		CreateThread(NULL, 0, MonteCarlo::Test, NULL, 0, NULL);
		/*auto test = MonteCarlo::Test;
		CreateThread(NULL, 0, test, NULL, 0, NULL);*/
		//CreateThread(NULL, 0, thread2, NULL, 0, NULL);
	}
	MonteCarlo::Run(NULL);
}

MultithreadedMonteCarlo::~MultithreadedMonteCarlo()
{
}