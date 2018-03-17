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
	auto &customer = queue.front();
	customer->Wakeup();
	std::string msg = "Customer No: " + std::to_string(customer->GetNumber()) + " served in cashdesk: " + std::to_string(number) + '\n';
	Messenger::GetInstanse().AddMessageInQueue(msg);

	WaitForSingleObject(customer->ExitEvent(), INFINITE);
	queue.pop();
	customer->Suicide();
}

size_t Cashier::GetNumber()
{
	return number;
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
			Messenger::GetInstanse().AddMessageInQueue("Cashier No: " + std::to_string(number) + " is sleeping now\n");
		}
		
		WaitForSingleObject(semaphore, INFINITE);
		Messenger::GetInstanse().AddMessageInQueue("Cashier No: " + std::to_string(number) + " awekened\n");
		ServeCustomer();
	}
	Messenger::GetInstanse().AddMessageInQueue("Cashier No: " + std::to_string(number) + " closed cashdesk\n");
}

void Cashier::AddCustomerInQueue(std::shared_ptr<Customer> customer)
{
	std::string msg = "New customer " + std::to_string(customer->GetNumber()) + " arrived on cashdesk No: " + std::to_string(number) + '\n';
	Messenger::GetInstanse().AddMessageInQueue(msg);
	queue.push(customer);
	ReleaseSemaphore(semaphore, 1, NULL);
}

void Cashier::StopWorking()
{
	isWorking = false;
}

Cashier::~Cashier()
{
	Messenger::GetInstanse().AddMessageInQueue(">>>>>>Closing cashier No:" + std::to_string(number) + '\n');
	CloseHandle(semaphore);
}