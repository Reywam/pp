#pragma once
#include <queue>
#include "Customer.h"
#include <Windows.h>

class Cashier
{
public:
	Cashier(const size_t &number);
	void ServeCustomer();
	void ServeCustomers();
	void AddCustomerInQueue(Customer &customer);
	void StopWorking();
	~Cashier();
private:
	HANDLE semaphore;
	std::queue<Customer> queue;
	size_t number;
	bool isWorking = true;
};