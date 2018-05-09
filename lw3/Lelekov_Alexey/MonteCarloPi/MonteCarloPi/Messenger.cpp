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

Messenger::~Messenger()
{
}