#include "stdafx.h"
#include "Messenger.h"

Messenger::Messenger()
{
}

void Messenger::AddMessageInQueue(const std::string msg)
{
	mutex = CreateMutex(NULL, FALSE, NULL);
	queue.push(msg);
	ReleaseMutex(mutex);
}

DWORD WINAPI Messenger::SendMessages(LPVOID parameter)
{
	while (true)
	{
		if (queue.empty() && stopWorking)
		{
			break;
		}

		if (!queue.empty())
		{
			std::string newMsg = queue.front() + '\n';
			std::cout << newMsg;
			queue.pop();
		}
	}
	return 0;
}

void Messenger::StopWorking()
{
	stopWorking = true;
}

Messenger::~Messenger()
{
	CloseHandle(mutex);
}