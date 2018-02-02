#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>

const size_t ARGS_COUNT = 3;

const size_t R = 1;
const size_t SQUARE_SIDE = 2;

const double multCoeff = 4;

using namespace std;

struct Point {
	Point(double x, double y) {
		this->x = x;
		this->y = y;
	}
	double x;
	double y;
};

double GenerateRandomDouble(const double &min, const double &max)
{	
	return (double)(rand()) / RAND_MAX * (max - min) + min;
}

Point GenerateRandomPoint(size_t squareSize)
{
	double min = -(double)(squareSize / 2);
	double max = (double)(squareSize / 2);
	return Point(GenerateRandomDouble(min, max), GenerateRandomDouble(min, max));
}

int main(int argc, char *argv[])
{
	clock_t start;
	clock_t end;

	start = clock();
	if (argc != ARGS_COUNT) {
		cout << "Invalid count of arguements." << endl;
		cout<< "Use: MonteCarloPi.exe <iterationsCount> <threadsCount>." << endl;
		return 1;
	}

	size_t iterationsCount = atoi(argv[1]);	
	size_t threadsCount = atoi(argv[2]);

	size_t pointsInCircle = 0;

	for(size_t i = 0; i < iterationsCount; i++) 
	{
		Point point = GenerateRandomPoint(SQUARE_SIDE);
		if (point.x * point.x + point.y * point.y <= R)
		{
			pointsInCircle++;
		}
	}

	double pi = multCoeff * pointsInCircle / iterationsCount;
	cout << pi << endl;
	end = clock();

	float duration = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << duration << endl;
    return 0;
}