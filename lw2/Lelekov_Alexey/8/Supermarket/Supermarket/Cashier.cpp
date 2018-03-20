#include "stdafx.h"
#include "Cashier.h"

Cashier::Cashier(const size_t &number)
{
	this->number = number;
	semaphore = CreateSemaphore(NULL, 0, clientsBufferSize, NULL);
}

void Cashier::ServeCustomer()
{
	Sleep(3000);
	auto &customer = queue.front();
	customer->Wakeup();
	std::cout << "Customer No: " + std::to_string(customer->GetNumber()) + " served in cashdesk: " + std::to_string(number) + '\n';
	WaitForSingleObject(customer->GetExitEvent(), INFINITE);
	queue.pop();
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
			std::cout << "Cashier No: " + std::to_string(number) + " is sleeping now\n";
		}
		
		WaitForSingleObject(semaphore, INFINITE);
		std::cout << "Cashier No: " + std::to_string(number) + " awekened\n";
		ServeCustomer();
	}
	std::cout << "Cashdesk " + std::to_string(number) + " closed\n";
}

void Cashier::AddCustomerInQueue(std::shared_ptr<Customer> customer)
{
	std::string msg = "New customer " + std::to_string(customer->GetNumber()) + " arrived on cashdesk No: " + std::to_string(number) + '\n';
	std::cout << msg;
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