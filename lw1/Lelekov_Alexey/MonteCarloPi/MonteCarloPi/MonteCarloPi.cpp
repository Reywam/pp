#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

#include <thread>
#include <mutex>

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
	double max = (double)(squareSize / 2);
	double min = -max;
	return Point(GenerateRandomDouble(min, max), GenerateRandomDouble(min, max));
}

void GeneratePoints(size_t &pointsInCircle, const size_t &iterationsCount, mutex &mtx) {
	for (size_t i = 0; i < iterationsCount; i++)
	{
		std::lock_guard<std::mutex> lock(mtx);
		Point point = GenerateRandomPoint(SQUARE_SIDE);
		if (point.x * point.x + point.y * point.y <= R)
		{
			pointsInCircle++;
		}
	}
}

vector<thread> InitThreads(
	const size_t &threadsCount, 
	size_t &pointsInCircle,
	const size_t &itersForThread,
	mutex &mtx)
{
	vector<thread> threads;
	for (size_t i = 0; i < threadsCount; i++)
	{
		threads.push_back(thread(GeneratePoints, ref(pointsInCircle), ref(itersForThread), ref(mtx)));
	}
	return threads;
}

void StartThreadsEndWaiting(vector<thread> &threads) 
{
	for (auto &thread : threads)
	{
		thread.join();
	}
}

int main(int argc, char *argv[])
{		
	if (argc != ARGS_COUNT) {
		cout << "Invalid count of arguements." << endl;
		cout << "Use: MonteCarloPi.exe <iterationsCount> <threadsCount>." << endl;
		return 1;
	}

	clock_t start = clock();
	
	size_t iterationsCount = atoi(argv[1]);	
	size_t threadsCount = atoi(argv[2]);	
	size_t itersForThread = iterationsCount / threadsCount;

	size_t pointsInCircle = 0;	

	mutex mtx;
	vector<thread> threads = InitThreads(threadsCount, pointsInCircle, itersForThread, mtx);	
	StartThreadsEndWaiting(threads);

	double pi = multCoeff * pointsInCircle / iterationsCount;
	cout << pi << endl;

	clock_t end = clock();

	float duration = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << duration << endl;	
    return 0;
}