#include "stdafx.h"

const size_t ARGS_COUNT = 3;

using namespace std;

int main(int argc, char *argv[])
{	
	if ((argc == 2 && argv[1] == "--help") || (argc != ARGS_COUNT))
	{		
		cout << "Use: MonteCarloPi.exe <iterationsCount> <threadsCount>." << endl;
		cout << "Also use: MonteCarloPi.exe --help for help message" << endl;
		return 1;
	}	

	size_t iterationsCount = atoi(argv[1]);
	size_t threadsCount = atoi(argv[2]);	

	clock_t start = clock();
	
	MonteCarlo algorithm(iterationsCount);
	algorithm.Run(threadsCount);
	cout << algorithm.GetResult() << endl;		

	clock_t end = clock();

	float duration = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Time: " << duration << endl;	
    return 0;
}