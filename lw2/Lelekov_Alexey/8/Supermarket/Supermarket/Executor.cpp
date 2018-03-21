#include "stdafx.h"
#include "Executor.h"
#include "Cashier.h"
#include <memory>

struct DataForCustomer
{
	std::vector<Cashier*> cashiers;
	Customer* customer;
};

Executor::Executor()
{
}

DWORD WINAPI Executor::ExecuteCashier(LPVOID parameter)
{
	Cashier *cashier = reinterpret_cast<Cashier*>(parameter);
	cashier->ServeCustomers();
	return 0;
}

DWORD WINAPI Executor::ExecuteCustomer(LPVOID parameter)
{
	DataForCustomer* data = reinterpret_cast<DataForCustomer*>(parameter);
	Customer* customer = data->customer;
	customer->Action(data->cashiers);
	return 0;
}

Executor::~Executor()
{
}