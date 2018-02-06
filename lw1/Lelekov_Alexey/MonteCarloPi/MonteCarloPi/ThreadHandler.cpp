#include "stdafx.h"
#include "ThreadHandler.h"


ThreadHandler::ThreadHandler()
{
}

void ThreadHandler::Add(LPTHREAD_START_ROUTINE threadProc)
{
	threads.push_back(CreateThread(NULL, 0, threadProc, NULL, 0, 0));
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