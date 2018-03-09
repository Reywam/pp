#include "stdafx.h"
#include "ThreadHandler.h"

ThreadHandler::ThreadHandler()
{
}

void ThreadHandler::Add(LPTHREAD_START_ROUTINE threadProc, LPVOID param)
{
	threads.push_back(CreateThread(NULL, 0, threadProc, param, 0, 0));
}

void ThreadHandler::WaitAll()
{
	WaitForMultipleObjects(threads.size(), threads.data(), true, INFINITE);
}

void ThreadHandler::TerminateAll()
{
	for (size_t i = 0; i < threads.size(); i++)
	{
		TerminateThread(threads[i], 0);
	}
}

ThreadHandler::~ThreadHandler()
{
	for (auto &thread : threads)
	{
		CloseHandle(thread);
	}
}