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
	Messenger::GetInstanse().SendMessageTo(std::cout, "Customer served in cashdesk: " + std::to_string(number) + '\n');	
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

void Cashier::AddCustomerInQueue(const Customer &customer)
{	
	Messenger::GetInstanse().SendMessageTo(std::cout, "New customer arrived on cashdesk No: " + std::to_string(number) + '\n');	
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