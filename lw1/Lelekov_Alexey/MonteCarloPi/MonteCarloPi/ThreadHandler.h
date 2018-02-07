#pragma once
#include <vector>
#include <Windows.h>

class ThreadHandler
{
public:
	ThreadHandler();
	void Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param);
	void JoinAll();
	bool empty();
	~ThreadHandler();
private:
	std::vector<HANDLE> threads;
};

