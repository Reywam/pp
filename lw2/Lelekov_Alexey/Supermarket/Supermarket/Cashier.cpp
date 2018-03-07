#include "stdafx.h"
#include "Cashier.h"
#include <Windows.h>
#include <iostream>
#include <string>

Cashier::Cashier(const size_t &number)
{
	this->number = number;
	semaphore = CreateSemaphore(NULL, 0, 50, NULL);	
}

void Cashier::ServeCustomer()
{
	std::cout << "Customer served in cashdesk: " + std::to_string(number) << std::endl;
	queue.pop();
}

void Cashier::ServeCustomers()
{
	while (true)
	{	
		if (queue.empty())
		{
			std::cout << "Cashier No: " + std::to_string(number) + " is sleeping now" << std::endl;
		}
		WaitForSingleObject(semaphore, INFINITE);
		ServeCustomer();
	}
}

void Cashier::AddCustomerInQueue(const Customer &customer)
{	
	std::cout << "New customer arrived on cashdesk No: " + std::to_string(number) << std::endl;
	queue.push(customer);	
	ReleaseSemaphore(semaphore, 1, NULL);
}

Cashier::~Cashier()
{
	CloseHandle(semaphore);
}