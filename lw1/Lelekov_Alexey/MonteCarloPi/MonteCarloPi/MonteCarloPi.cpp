#include "stdafx.h"

const size_t ARGS_COUNT = 3;

using namespace std;

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
	size_t count = 0;

	MonteCarlo algorithm;	
	algorithm.Run(iterationsCount, count);
	cout << algorithm.GetResult() << endl;	

	clock_t end = clock();

	float duration = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << duration << endl;	
    return 0;
}