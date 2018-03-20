#pragma once
#include <random>

class Randomizer
{
public:
	static int Get(int min, int max);
private:
	static std::mt19937& GetEngineInstance();
};