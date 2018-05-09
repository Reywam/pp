#include "stdafx.h"
#include "Messenger.h"

const std::string Messenger::helpMessage = "Use MonteCarloPi.exe <iterCount>\n<iterCount>: 0-inf+\n";
const std::string Messenger::errorMessage = "Error! Use MonteCarloPi.exe --help for help message.";

Messenger::Messenger()
{
}

void Messenger::PrintMessage(std::ostream &out, const static std::string &message)
{
	out << message << std::endl;
}

void Messenger::PrintErrorMsg(std::ostream &out)
{
	PrintMessage(out, errorMessage);
}

void Messenger::PrintHelpMsg(std::ostream &out)
{
	PrintMessage(out, helpMessage);
}

DWORD WINAPI Messenger::PrintProgress(LPVOID param)
{
	while (Counter::GetCount() < MonteCarlo::GetProgressBorder())
	{
		std::string progress = '\n' + std::to_string(Counter::GetCount()) + " / " + std::to_string(MonteCarlo::GetProgressBorder()) + '\n';
		std::cout << progress;
	}
	return 0;
}

Messenger::~Messenger()
{
}