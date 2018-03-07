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
	
	void SendMessageTo(std::ostream &out, const std::string &msg);
private:
	Messenger();
	~Messenger();
	Messenger(Messenger const&) = delete;
	Messenger& operator= (Messenger const&) = delete;
	
	HANDLE mutex;
};