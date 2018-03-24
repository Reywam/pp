#pragma once
#include <iostream>
#include <string>
class Messenger
{
public:
	Messenger();
	static void Messenger::PrintMessage(std::ostream &out, const std::string &message);
	static void PrintErrorMsg(std::ostream &out);
	static void PrintHelpMsg(std::ostream &out);
	static DWORD WINAPI PrintProgress(LPVOID param);
	~Messenger();
private:
	static const std::string helpMessage;
	static const std::string errorMessage;
};