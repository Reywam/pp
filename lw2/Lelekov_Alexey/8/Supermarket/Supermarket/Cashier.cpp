#include "stdafx.h"
#include "Cashier.h"
#include "Customer.h"

Cashier::Cashier(const size_t &number)
{
	this->number = number;
	semaphore = CreateSemaphore(NULL, 0, clientsBufferSize, NULL);
}

void Cashier::ServeCustomer()
{
	int sleepTime = 3000 + rand() % 5000;
	Sleep(sleepTime);
	auto customer = queue.front();
	customer->Wakeup();
	std::cout << "Customer No: " + std::to_string(customer->GetNumber()) + " served in cashdesk: " + std::to_string(number) + '\n';
	std::cout << "Serving time: " + std::to_string(sleepTime) + "\n\n";
	WaitForSingleObject(customer->GetExitEvent(), INFINITE);
	queue.pop();
}

size_t Cashier::GetNumber()
{
	return number;
}

void Cashier::ServeCustomers()
{
	srand(time(NULL));
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
		ServeCustomer();
	}
	std::cout << "Cashdesk " + std::to_string(number) + " closed\n";
}

void Cashier::AddCustomerInQueue(Customer* customer)
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