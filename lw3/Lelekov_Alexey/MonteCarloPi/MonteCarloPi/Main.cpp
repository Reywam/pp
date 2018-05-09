#include "stdafx.h"

const size_t ARGS_COUNT = 2;

int main(int argc, char *argv[])
{
	if (argc == 2 && std::string(argv[1]) == "--help")
	{
		std::cout << argv[1] << std::endl;
		Messenger::PrintHelpMsg(std::cout);
		return 1;
	}

	if (argc != ARGS_COUNT)
	{
		Messenger::PrintErrorMsg(std::cout);
		return 1;
	}

	size_t iterationsCount = atoi(argv[1]);

	clock_t start = clock();
	
	MonteCarlo algorithm(iterationsCount);
	algorithm.Run();
	std::cout << algorithm.GetResult() << std::endl;

	clock_t end = clock();

	float duration = (float)(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time: " << duration << std::endl;

    return 0;
}