#include "stdafx.h"
#include "Customer.h"
#include "Cashier.h"
#include <memory>

Customer::Customer(const size_t &number)
{
	this->number = number;
	wakeupEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	exitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
}

void Customer::Wakeup()
{
	SetEvent(wakeupEvent);
}

size_t Customer::GetNumber()
{
	return number;
}

void Customer::GetInLine(std::vector<Cashier*> cashiers)
{
	srand(time(NULL));
	int cashierNumber = rand() % cashiers.size();
	cashiers[cashierNumber]->AddCustomerInQueue(this);
}

void Customer::Action(std::vector<Cashier*> cashiers)
{
	int sleepTime = 1000 + rand() % 5000;
	std::cout << "Sleep for : " + std::to_string(sleepTime) + '\n';
	Sleep(sleepTime);
	GetInLine(cashiers);
	WaitOnesTurn();
}

void Customer::WaitOnesTurn()
{
	std::cout << "Customer No: " + std::to_string(number) + " is sleeping now\n";
	WaitForSingleObject(wakeupEvent, INFINITE);
	SetEvent(exitEvent);
}

HANDLE Customer::GetExitEvent()
{
	return exitEvent;
}

Customer::~Customer()
{
	CloseHandle(wakeupEvent);
	CloseHandle(exitEvent);
}