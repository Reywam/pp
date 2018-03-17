#pragma once
#include <string>
#include <queue>
#include <Windows.h>

class Messenger
{
public:
	static Messenger& GetInstanse()
	{
		static Messenger messenger;
		return messenger;
	}
	
	void AddMessageInQueue(const std::string msg);
	DWORD WINAPI SendMessages(LPVOID parameter);
	void StopWorking();
private:
	Messenger();
	~Messenger();
	Messenger(Messenger const&) = delete;
	Messenger& operator= (Messenger const&) = delete;
	
	std::queue<std::string> queue;
	bool stopWorking = false;
	HANDLE mutex;
};