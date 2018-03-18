#pragma once
#include <Windows.h>

class Executor
{
public:
	Executor();
	static DWORD WINAPI ExecuteCashier(LPVOID parameter);
	static DWORD WINAPI ExecuteCustomer(LPVOID parameter);
	~Executor();
};