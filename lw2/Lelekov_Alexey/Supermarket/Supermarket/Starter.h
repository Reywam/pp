#pragma once
#include <Windows.h>

class Starter
{
public:
	Starter();
	static DWORD WINAPI Execute(LPVOID parameter);
	~Starter();
};

