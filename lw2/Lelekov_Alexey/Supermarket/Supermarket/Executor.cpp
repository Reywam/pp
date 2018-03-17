#include "stdafx.h"
#include "Executor.h"
#include "Cashier.h"
#include "Messenger.h"
#include <memory>

Executor::Executor()
{
}

DWORD WINAPI Executor::ExecuteCashier(LPVOID parameter)
{
	Cashier *cashier = (Cashier *) parameter;
	cashier->ServeCustomers();
	return 0;
}

DWORD WINAPI Executor::ExecuteMessenger(LPVOID parameter)
{
	Messenger::GetInstanse().SendMessages(NULL);
	return 0;
}

DWORD WINAPI Executor::ExecuteCustomer(LPVOID parameter)
{
	Customer* customer = (Customer*)parameter;
	customer->WaitOnesTurn();
	return 0;
}

Executor::~Executor()
{
}