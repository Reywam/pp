#include "stdafx.h"
#include "Counter.h"

size_t Counter::count = 0;
size_t Counter::points = 0;

Counter::Counter()
{
	Counter::Reset();
}

void Counter::IncPoint()
{
	InterlockedIncrement(&points);
}

void Counter::IncCount()
{
	InterlockedIncrement(&count);
}

size_t Counter::GetCount()
{
	return count;
}

size_t Counter::GetPoints()
{
	return points;
}

void Counter::Reset()
{
	count = 0;
	points = 0;
}

Counter::~Counter()
{
}