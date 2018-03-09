#include "stdafx.h"
#include "Cashier.h"
#include "Messenger.h"

Cashier::Cashier(const size_t &number)
{
	this->number = number;
	semaphore = CreateSemaphore(NULL, 0, 50, NULL);
}

void Cashier::ServeCustomer()
{
	auto customer = queue.front();
	customer.Wakeup();
	WaitForSingleObject(customer.IsWakedUp(), INFINITE);
	std::string msg = "Customer No: " + std::to_string(customer.GetNumber()) + " served in cashdesk: " + std::to_string(number) + '\n';
	Messenger::GetInstanse().SendMessageTo(std::cout, msg);
	queue.pop();
}

void Cashier::ServeCustomers()
{
	while (true)
	{
		if (!isWorking && queue.empty())
		{
			break;
		}

		if (queue.empty())
		{
			Messenger::GetInstanse().SendMessageTo(std::cout, "Cashier No: " + std::to_string(number) + " is sleeping now" + '\n');
		}
		
		WaitForSingleObject(semaphore, INFINITE);
		ServeCustomer();
	}
}

void Cashier::AddCustomerInQueue(Customer &customer)
{
	std::string msg = "New customer " + std::to_string(customer.GetNumber()) + " arrived on cashdesk No: " + std::to_string(number) + '\n';
	Messenger::GetInstanse().SendMessageTo(std::cout, msg);
	queue.push(customer);
	ReleaseSemaphore(semaphore, 1, NULL);
}

void Cashier::StopWorking()
{
	isWorking = false;
}

Cashier::~Cashier()
{
	CloseHandle(semaphore);
}