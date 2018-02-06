#pragma once
#include "MonteCarlo.h"
class MultithreadedMonteCarlo :
	public MonteCarlo
{
public:
	MultithreadedMonteCarlo(const size_t &itersCount);
	void Run(const size_t &threadsCount);
	~MultithreadedMonteCarlo();
};