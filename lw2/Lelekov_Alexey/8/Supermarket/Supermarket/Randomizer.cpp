#include "stdafx.h"
#include "Randomizer.h"

int Randomizer::Get(int min, int max)
{
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(GetEngineInstance());
}

std::mt19937 & Randomizer::GetEngineInstance()
{
	static std::random_device device;
	static std::mt19937 engine(device());
	return engine;
}