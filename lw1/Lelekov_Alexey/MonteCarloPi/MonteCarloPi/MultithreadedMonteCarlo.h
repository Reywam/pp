#pragma once
#include "MonteCarlo.h"
class MultithreadedMonteCarlo :
	public MonteCarlo
{
public:
	MultithreadedMonteCarlo();
	void Run(const size_t &threadsCount);
	~MultithreadedMonteCarlo();
};