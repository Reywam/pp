#include "stdafx.h"
#include "Customer.h"

Customer::Customer(const size_t &number)
{
	this->number = number;
	wakeupEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	exitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	ResetEvent(wakeupEvent);
}

void Customer::Wakeup()
{
	SetEvent(wakeupEvent);
}

size_t Customer::GetNumber()
{
	return number;
}

void Customer::WaitOnesTurn()
{
	std::cout << "Customer No: " + std::to_string(number) + " is sleeping now\n";
	WaitForSingleObject(wakeupEvent, INFINITE);
	SetEvent(exitEvent);
	ResetEvent(wakeupEvent);
}

HANDLE Customer::ExitEvent()
{
	return exitEvent;
}

Customer::~Customer()
{
	CloseHandle(wakeupEvent);
	CloseHandle(exitEvent);
}