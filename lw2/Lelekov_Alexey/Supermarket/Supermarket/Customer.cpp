#include "stdafx.h"
#include "Customer.h"

Customer::Customer(size_t number)
{
	this->number = number;
	wakedUp = CreateEvent(NULL, FALSE, FALSE, NULL);
}

HANDLE Customer::IsWakedUp()
{
	return wakedUp;
}

size_t Customer::GetNumber()
{
	return number;
}

void Customer::WaitOnesTurn()
{
	SetEvent(wakedUp);
	std::string msg = "Customer No: " + std::to_string(number) + " was waked up\n";
	Messenger::GetInstanse().SendMessageTo(std::cout, msg);
}

void Customer::Wakeup()
{
	SetEvent(wakedUp);
}

Customer::~Customer()
{
}