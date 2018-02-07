#include "stdafx.h"
#include "ThreadHandler.h"

ThreadHandler::ThreadHandler()
{
}

bool ThreadHandler::empty()
{
	return threads.size() > 0 ? false : true;
}

void ThreadHandler::Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param)
{
	threads.push_back(CreateThread(NULL, 0, threadProc, param, 0, 0));
}

void ThreadHandler::JoinAll()
{
	WaitForMultipleObjects(threads.size(), threads.data(), true, INFINITE);
}

ThreadHandler::~ThreadHandler()
{
	for (auto &thread : threads)
	{
		CloseHandle(thread);
	}
}