#include "stdafx.h"

const size_t ARGS_COUNT = 3;

const size_t R = 1;
const size_t SQUARE_SIDE = 2;

const double multCoeff = 4;

using namespace std;

struct Point 
{
	Point(double x, double y) 
	{
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

void GeneratePoints(size_t &pointsInCircle, 
	const size_t &iterationsCount, 
	mutex &mtx,
	size_t &count) 
{
	for (; count < iterationsCount;)
	{
		std::lock_guard<std::mutex> lock(mtx);
		count++;
		if (count > iterationsCount)
		{
			break;
		}
		
		cout << count << "/" << iterationsCount << endl;		
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
	mutex &mtx,
	size_t &count)
{
	vector<thread> threads;
	for (size_t i = 0; i < threadsCount; i++)
	{
		threads.push_back(thread(GeneratePoints, ref(pointsInCircle), ref(itersForThread), ref(mtx), ref(count)));
	}
	return threads;
}

void StartWaitingForThreadsEnd(vector<thread> &threads) 
{
	for (auto &thread : threads)
	{
		thread.join();
	}
}

int main(int argc, char *argv[])
{		
	if (argc != ARGS_COUNT) 
	{
		cout << "Invalid count of arguements." << endl;
		cout << "Use: MonteCarloPi.exe <iterationsCount> <threadsCount>." << endl;
		return 1;
	}

	clock_t start = clock();
	
	size_t iterationsCount = atoi(argv[1]);	
	size_t threadsCount = atoi(argv[2]);		
	size_t pointsInCircle = 0;	

	mutex mtx;
	size_t count = 0;
	vector<thread> threads = InitThreads(threadsCount, pointsInCircle, iterationsCount, mtx, count);
	StartWaitingForThreadsEnd(threads);

	double pi = multCoeff * pointsInCircle / iterationsCount;
	cout << "Pi: " << pi << endl;

	clock_t end = clock();

	float duration = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << duration << endl;	
    return 0;
}